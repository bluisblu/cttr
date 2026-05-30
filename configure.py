#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "G9RE7D",  # 0
    "G9RP7D",
    "G9RJ7D",
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--ninja", metavar="BINARY", type=Path, help="path to ninja binary (optional)"
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--warn",
    dest="warn",
    type=str,
    choices=["all", "off", "error"],
    help="how to handle warnings",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.ninja_path = args.ninja
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-1"
config.compilers_tag = "20251118"
config.dtk_tag = "v1.8.3"
config.objdiff_tag = "v3.5.1"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.1.0"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym BUILD_VERSION={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
]
if args.debug:
    config.ldflags.append("-g")  # Or -gdwarf-2 for Wii linkers
if args.map:
    config.ldflags.append("-mapunused")
    # config.ldflags.append("-listclosure") # For Wii linkers

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    # "-W all",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-multibyte",  # For Wii compilers, replace with `-enc SJIS`
    "-i include",
    "-i include/stl",
    "-i include/stl/internal",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

# Debug flags
if args.debug:
    # Or -sym dwarf-2 for Wii compilers
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Warning flags
if args.warn == "all":
    cflags_base.append("-W all")
elif args.warn == "off":
    cflags_base.append("-W off")
elif args.warn == "error":
    cflags_base.append("-W error")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-gccinc",
    "-common off",
    "-inline auto",
    "-i src/PowerPC_EABI_Support/Runtime/Inc/",
    "-i src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include",
]

# REL flags
cflags_rel = [
    *cflags_base,
    "-sdata 0",
    "-sdata2 0",
]

# Game-specific flags
cflags_cttr = [
    *cflags_base,
    "-RTTI on",
    "-lang=C++",
    "-common on",
    "-char unsigned",
    "-str reuse,pool,readonly",
    "-use_lmw_stmw on",
    '-pragma "cpp_extensions on"',
    "-inline off",
    "-gccinc",
    "-i include/",
    "-i src/",
    "-DGAMECUBE",
]

cflags_lua = [
    *cflags_base,
    "-lang=C",
    "-i src/PowerPC_EABI_Support/Runtime/Inc/",
    "-i src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include",
    "-i src/lua/src/",
    "-i src/lua/include/",
    "-O4,s",
    "-inline off",
    "-DLUA_NUMBER=float",
    "-DBUFSIZ=1024",
]

cflags_libpng = [
    *cflags_base,
    "-lang=C",
    "-i src/PowerPC_EABI_Support/Runtime/Inc/",
    "-i src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include",
    "-i src/libpng/",
    "-O4,s",
    "-inline off",
]

cflags_dolphin = [
    *cflags_base,
    "-lang=C",
    "-i src/PowerPC_EABI_Support/Runtime/Inc/",
    "-i src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include",
    "-i include/dolphin",
    "-i include/dolphin/os",
    "-i src/dolphin/os",
    "-i src/dolphin/dvd",
    "-D__GEKKO__"
]

config.linker_version = "GC/2.6"


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_dolphin,
        "progress_category": "sdk",
        "objects": objects,
    }


# Helper function for REL script objects
def Rel(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3.2",
        "cflags": cflags_rel,
        "progress_category": "game",
        "objects": objects,
    }


Matching = True  # Object matches and should be linked
NonMatching = False  # Object does not match and should not be linked
Equivalent = (
    config.non_matching
)  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    {
        "lib": "CTTR",
        "mw_version": config.linker_version,
        "cflags": cflags_cttr,
        # "progress_category": "game", # Leave commented until split
        "objects": [
            Object(NonMatching, "CTTR/Controller.cpp"),
            # Auto splits using sinit functions as the boundaries
            Object(NonMatching, "auto/auto_8000B0BC.cpp"),
            Object(NonMatching, "auto/auto_8000B3E4.cpp"),
            Object(NonMatching, "auto/auto_8000CAF8.cpp"),
            Object(NonMatching, "auto/auto_8000DC50.cpp"),
            Object(NonMatching, "auto/auto_80012620.cpp"),
            Object(NonMatching, "auto/auto_80013F40.cpp"),
            Object(NonMatching, "auto/auto_8001DD24.cpp"),
            Object(NonMatching, "auto/auto_8001FAA8.cpp"),
            Object(NonMatching, "auto/auto_8001FF04.cpp"),
            Object(NonMatching, "auto/auto_80023334.cpp"),
            Object(NonMatching, "auto/auto_80024240.cpp"),
            Object(NonMatching, "auto/auto_80024B94.cpp"),
            Object(NonMatching, "auto/auto_8002F92C.cpp"),
            Object(NonMatching, "auto/auto_80031E1C.cpp"),
            Object(NonMatching, "auto/auto_80035978.cpp"),
            Object(NonMatching, "auto/auto_80036718.cpp"),
            Object(NonMatching, "auto/auto_8004B5A4.cpp"),
            Object(NonMatching, "auto/auto_8004DF6C.cpp"),
            Object(NonMatching, "auto/auto_8004E164.cpp"),
            Object(NonMatching, "auto/auto_8004EDEC.cpp"),
            Object(NonMatching, "auto/auto_8005A9F0.cpp"),
            Object(NonMatching, "auto/auto_8005B1EC.cpp"),
            Object(NonMatching, "auto/auto_8005E998.cpp"),
            Object(NonMatching, "auto/auto_8005F290.cpp"),
            Object(NonMatching, "auto/auto_8006C5C8.cpp"),
            Object(NonMatching, "auto/auto_8006D5A8.cpp"),
            Object(NonMatching, "auto/auto_8006EBF0.cpp"),
            Object(NonMatching, "auto/auto_80070AA4.cpp"),
            Object(NonMatching, "auto/auto_800712F4.cpp"),
            Object(NonMatching, "auto/auto_800716F0.cpp"),
            Object(NonMatching, "auto/auto_800735D4.cpp"),
            Object(NonMatching, "auto/auto_800765E4.cpp"),
            Object(NonMatching, "auto/auto_80078488.cpp"),
            Object(NonMatching, "auto/auto_80084DC8.cpp"),
            Object(NonMatching, "auto/auto_80088948.cpp"),
            Object(NonMatching, "auto/auto_80089B58.cpp"),
            Object(NonMatching, "auto/auto_80093964.cpp"),
            Object(NonMatching, "auto/auto_80097254.cpp"),
            Object(NonMatching, "auto/auto_80097E50.cpp"),
            Object(NonMatching, "auto/auto_800A12E4.cpp"),
            Object(NonMatching, "auto/auto_800A7580.cpp"),
            Object(NonMatching, "auto/auto_800A9F3C.cpp"),
            Object(NonMatching, "auto/auto_800AC8F4.cpp"),
            Object(NonMatching, "auto/auto_800AD000.cpp"),
            Object(NonMatching, "CTTR/Mode.cpp"),
            Object(NonMatching, "auto/auto_800B0748.cpp"),
            Object(NonMatching, "auto/auto_800B9498.cpp"),
            Object(NonMatching, "auto/auto_800BA7BC.cpp"),
            Object(NonMatching, "auto/auto_800BB074.cpp"),
            Object(NonMatching, "auto/auto_800BBD94.cpp"),
            Object(NonMatching, "auto/auto_800C10E8.cpp"),
            Object(NonMatching, "auto/auto_800C570C.cpp"),
            Object(NonMatching, "auto/auto_800C7320.cpp"),
            Object(NonMatching, "auto/auto_800C8BB0.cpp"),
            Object(NonMatching, "auto/auto_800CA2BC.cpp"),
            Object(NonMatching, "auto/auto_800CB4CC.cpp"),
            Object(NonMatching, "auto/auto_800CD628.cpp"),
            Object(NonMatching, "auto/auto_800CFC84.cpp"),
            Object(NonMatching, "auto/auto_800FF950.cpp"),
            Object(NonMatching, "auto/auto_80109A64.cpp"),
            Object(NonMatching, "auto/auto_801179BC.cpp"),
            Object(NonMatching, "auto/auto_80128B50.cpp"),
            Object(NonMatching, "auto/auto_8012D4E8.cpp"),
            Object(NonMatching, "auto/auto_8012E678.cpp"),
            Object(NonMatching, "auto/auto_8012F770.cpp"),
            Object(NonMatching, "auto/auto_8012F930.cpp"),
            Object(NonMatching, "auto/auto_801338FC.cpp"),
            Object(NonMatching, "auto/auto_80138744.cpp"),
            Object(NonMatching, "auto/auto_80139514.cpp"),
            Object(NonMatching, "auto/auto_80148090.cpp"),
            Object(NonMatching, "auto/auto_8014C208.cpp"),
            Object(NonMatching, "auto/auto_8014DA60.cpp"),
            Object(NonMatching, "auto/auto_8014E6E4.cpp"),
            Object(NonMatching, "auto/auto_801556B0.cpp"),
            Object(NonMatching, "auto/auto_80155F68.cpp"),
            Object(NonMatching, "auto/auto_8015679C.cpp"),
            Object(NonMatching, "auto/auto_80156B30.cpp"),
            Object(NonMatching, "auto/auto_80158570.cpp"),
            Object(NonMatching, "auto/auto_801599C0.cpp"),
            Object(NonMatching, "auto/auto_801605A0.cpp"),
            Object(NonMatching, "auto/auto_80166A88.cpp"),
            Object(NonMatching, "auto/auto_80168E04.cpp"),
            Object(NonMatching, "auto/auto_8016AE44.cpp"),
            Object(NonMatching, "auto/auto_80173820.cpp"),
            Object(NonMatching, "auto/auto_80174DEC.cpp"),
            Object(NonMatching, "auto/auto_801779E4.cpp"),
            Object(NonMatching, "auto/auto_80179F5C.cpp"),
            Object(NonMatching, "auto/auto_8017A1DC.cpp"),
            Object(NonMatching, "auto/auto_8017D28C.cpp"),
            Object(NonMatching, "auto/auto_80181A40.cpp"),
            Object(NonMatching, "auto/auto_80182C70.cpp"),
            Object(NonMatching, "auto/auto_80183568.cpp"),
            Object(NonMatching, "auto/auto_80184038.cpp"),
            Object(NonMatching, "auto/auto_801860E8.cpp"),
            Object(NonMatching, "auto/auto_80189AAC.cpp"),
            Object(NonMatching, "auto/auto_8018BB4C.cpp"),
            Object(NonMatching, "CTTR/Player.cpp"),
            Object(NonMatching, "CTTR/Skin.cpp"),
            Object(NonMatching, "auto/auto_801908E0.cpp"),
            Object(NonMatching, "auto/auto_80190DF0.cpp"),
            Object(NonMatching, "auto/auto_801947D0.cpp"),
            Object(NonMatching, "auto/auto_80195DD0.cpp"),
            Object(NonMatching, "auto/auto_80196100.cpp"),
            Object(NonMatching, "auto/auto_80199338.cpp"),
            Object(NonMatching, "auto/auto_801AA510.cpp"),
            Object(NonMatching, "auto/auto_801AD70C.cpp"),
            Object(NonMatching, "auto/auto_801B31F8.cpp"),
            Object(NonMatching, "auto/auto_801B58E4.cpp"),
            Object(NonMatching, "auto/auto_801BF138.cpp"),
            Object(NonMatching, "auto/auto_801C2108.cpp"),
            Object(NonMatching, "auto/auto_801C45F4.cpp"),
            Object(NonMatching, "auto/auto_801C6460.cpp"),
            Object(NonMatching, "auto/auto_801C6630.cpp"),
            Object(NonMatching, "auto/auto_801C7360.cpp"),
            Object(NonMatching, "auto/auto_801C762C.cpp"),
            Object(NonMatching, "auto/auto_801C7758.cpp"),
            Object(NonMatching, "auto/auto_801C8400.cpp"),
            Object(NonMatching, "auto/auto_801C9BBC.cpp"),
            Object(NonMatching, "auto/auto_801C9CE8.cpp"),
            Object(NonMatching, "auto/auto_801CAE5C.cpp"),
            Object(NonMatching, "auto/auto_801CB50C.cpp"),
            Object(NonMatching, "auto/auto_801CB820.cpp"),
            Object(NonMatching, "auto/auto_801CD2AC.cpp"),
            Object(NonMatching, "auto/auto_801CDCCC.cpp"),
            Object(NonMatching, "auto/auto_801CE3B0.cpp"),
            Object(NonMatching, "auto/auto_801CEDB4.cpp"),
            Object(NonMatching, "auto/auto_801CFB10.cpp"),
            Object(NonMatching, "auto/auto_801D0AD4.cpp"),
            Object(NonMatching, "auto/auto_801D46C4.cpp"),
            Object(NonMatching, "auto/auto_801D5FA0.cpp"),
            Object(NonMatching, "auto/auto_801D7A9C.cpp"),
            Object(NonMatching, "auto/auto_801D85AC.cpp"),
            Object(NonMatching, "auto/auto_801DA638.cpp"),
            Object(NonMatching, "auto/auto_801DAC18.cpp"),
            Object(NonMatching, "auto/auto_801DC760.cpp"),
            Object(NonMatching, "auto/auto_801E1154.cpp"),
            Object(NonMatching, "auto/auto_801E1A14.cpp"),
            Object(NonMatching, "auto/auto_801E2328.cpp"),
            Object(NonMatching, "auto/auto_801E39A0.cpp"),
            Object(NonMatching, "auto/auto_801E4B64.cpp"),
            Object(NonMatching, "auto/auto_801E6774.cpp"),
            Object(NonMatching, "auto/auto_801E7CA4.cpp"),
            Object(NonMatching, "auto/auto_801E84C4.cpp"),
            Object(NonMatching, "auto/auto_801E9114.cpp"),
            Object(NonMatching, "auto/auto_801EEF5C.cpp"),
            Object(NonMatching, "auto/auto_801F009C.cpp"),
            Object(NonMatching, "auto/auto_801F0B08.cpp"),
            Object(NonMatching, "auto/auto_801F1074.cpp"),
            Object(NonMatching, "auto/auto_801F3530.cpp"),
            Object(NonMatching, "auto/auto_801F43E8.cpp"),
            Object(NonMatching, "auto/auto_801F7180.cpp"),
            Object(NonMatching, "auto/auto_801F9754.cpp"),
            Object(NonMatching, "auto/auto_801FD890.cpp"),
            Object(NonMatching, "auto/auto_801FE7A0.cpp"),
            Object(NonMatching, "auto/auto_80200044.cpp"),
            Object(NonMatching, "auto/auto_80202520.cpp"),
            Object(NonMatching, "auto/auto_80203D30.cpp"),
            Object(NonMatching, "auto/auto_80208FF8.cpp"),
            Object(NonMatching, "auto/auto_8020C474.cpp"),
            Object(NonMatching, "auto/auto_8020C978.cpp"),
            Object(NonMatching, "auto/auto_8020D550.cpp"),
            Object(NonMatching, "auto/auto_80211B1C.cpp"),
            Object(NonMatching, "auto/auto_80213138.cpp"),
            Object(NonMatching, "auto/auto_8021727C.cpp"),
            Object(NonMatching, "auto/auto_8021A3EC.cpp"),
            Object(NonMatching, "auto/auto_8021D748.cpp"),
            Object(NonMatching, "auto/auto_8022BC60.cpp"),
            Object(NonMatching, "auto/auto_8022D6A4.cpp"),
            Object(NonMatching, "auto/auto_802329B4.cpp"),
            Object(NonMatching, "auto/auto_80232CC0.cpp"),
            Object(NonMatching, "auto/auto_80233F00.cpp"),
            Object(NonMatching, "auto/auto_80234DAC.cpp"),
            Object(NonMatching, "auto/auto_80235848.cpp"),
            Object(NonMatching, "auto/auto_8023E3C4.cpp"),
            Object(NonMatching, "auto/auto_80244CF4.cpp"),
            Object(NonMatching, "auto/auto_80252C38.cpp"),
            Object(NonMatching, "auto/auto_802537D0.cpp"),
            Object(NonMatching, "auto/auto_802546F4.cpp"),
            Object(NonMatching, "auto/auto_80254F4C.cpp"),
            Object(NonMatching, "auto/auto_80255A18.cpp"),
            Object(NonMatching, "auto/auto_80257694.cpp"),
            Object(NonMatching, "auto/auto_8025AC64.cpp"),
            Object(NonMatching, "auto/auto_8025AF90.cpp"),
            Object(NonMatching, "auto/auto_8025B3B4.cpp"),
            Object(NonMatching, "auto/auto_8025FFEC.cpp"),
            Object(NonMatching, "auto/auto_80260238.cpp"),
            Object(NonMatching, "auto/auto_80260D98.cpp"),
            Object(NonMatching, "auto/auto_802610A8.cpp"),
            Object(NonMatching, "auto/auto_80261EC4.cpp"),
            Object(NonMatching, "auto/auto_80263220.cpp"),
            Object(NonMatching, "auto/auto_80263978.cpp"),
            Object(NonMatching, "auto/auto_802643E0.cpp"),
            Object(NonMatching, "auto/auto_80264D6C.cpp"),
            Object(NonMatching, "auto/auto_802665B0.cpp"),
            Object(NonMatching, "auto/auto_80267C3C.cpp"),
            Object(NonMatching, "auto/auto_8026893C.cpp"),
            Object(NonMatching, "auto/auto_80269B80.cpp"),
            Object(NonMatching, "auto/auto_8026A34C.cpp"),
            Object(NonMatching, "auto/auto_8026B238.cpp"),
            Object(NonMatching, "auto/auto_8026BBE0.cpp"),
            Object(NonMatching, "auto/auto_8026C334.cpp"),
            Object(NonMatching, "auto/auto_8026CA34.cpp"),
            Object(NonMatching, "auto/auto_8026CECC.cpp"),
            Object(NonMatching, "auto/auto_8026D790.cpp"),
            Object(NonMatching, "auto/auto_8026DF64.cpp"),
            Object(NonMatching, "auto/auto_8026E904.cpp"),
            Object(NonMatching, "auto/auto_8026FB30.cpp"),
            Object(NonMatching, "auto/auto_80270260.cpp"),
            Object(NonMatching, "auto/auto_802709F4.cpp"),
            Object(NonMatching, "auto/auto_80271218.cpp"),
            Object(NonMatching, "auto/auto_80271A9C.cpp"),
            Object(NonMatching, "auto/auto_802721B0.cpp"),
            Object(NonMatching, "auto/auto_80272944.cpp"),
            Object(NonMatching, "auto/auto_80273108.cpp"),
            Object(NonMatching, "auto/auto_802738FC.cpp"),
            Object(NonMatching, "auto/auto_802744C0.cpp"),
            Object(NonMatching, "auto/auto_80274940.cpp"),
            Object(NonMatching, "auto/auto_802756B4.cpp"),
            Object(NonMatching, "auto/auto_80275858.cpp"),
            Object(NonMatching, "auto/auto_802758E4.cpp"),
            Object(NonMatching, "auto/auto_80275D58.cpp"),
            Object(NonMatching, "auto/auto_80277718.cpp"),
            Object(NonMatching, "auto/auto_8027AA58.cpp"),
            Object(NonMatching, "auto/auto_8027C148.cpp"),
            Object(NonMatching, "auto/auto_8027CAC0.cpp"),
            Object(NonMatching, "auto/auto_8027D970.cpp"),
            Object(NonMatching, "auto/auto_8027EE5C.cpp"),
            Object(NonMatching, "auto/auto_80280960.cpp"),
            Object(NonMatching, "auto/auto_80286364.cpp"),
            Object(NonMatching, "auto/auto_802886E8.cpp"),
            Object(NonMatching, "auto/auto_8028BF44.cpp"),
            Object(NonMatching, "auto/auto_8028DCF4.cpp"),
            Object(NonMatching, "auto/auto_8029B4A4.cpp"),
            Object(NonMatching, "auto/auto_8029E3C0.cpp"),
            Object(NonMatching, "auto/auto_8029E940.cpp"),
            Object(NonMatching, "auto/auto_802A03C4.cpp"),
            Object(NonMatching, "auto/auto_802A1CB8.cpp"),
            Object(NonMatching, "auto/auto_802A7188.cpp"),
            Object(NonMatching, "auto/auto_802AB098.cpp"),
            Object(NonMatching, "auto/auto_802AB698.cpp"),
            Object(NonMatching, "auto/auto_802ABD80.cpp"),
            Object(NonMatching, "auto/auto_802AC424.cpp"),
            Object(NonMatching, "auto/auto_802ACB78.cpp"),
            Object(NonMatching, "auto/auto_802ADBD8.cpp"),
            Object(NonMatching, "auto/auto_802AE390.cpp"),
            Object(NonMatching, "auto/auto_802AE5A0.cpp"),
            Object(NonMatching, "auto/auto_802AED84.cpp"),
            Object(NonMatching, "auto/auto_802AFEBC.cpp"),
            Object(NonMatching, "auto/auto_802B14F4.cpp"),
            Object(NonMatching, "auto/auto_802B26A8.cpp"),
            Object(NonMatching, "auto/auto_802B2A94.cpp"),
            Object(NonMatching, "auto/auto_802B3174.cpp"),
            Object(NonMatching, "auto/auto_802B3610.cpp"),
            Object(NonMatching, "auto/auto_802B3878.cpp"),
            Object(NonMatching, "auto/auto_802B3E54.cpp"),
            Object(NonMatching, "auto/auto_802B4240.cpp"),
            Object(NonMatching, "auto/auto_802B462C.cpp"),
            Object(NonMatching, "auto/auto_802B487C.cpp"),
            Object(NonMatching, "auto/auto_802B4E58.cpp"),
            Object(NonMatching, "auto/auto_802B59F8.cpp"),
            Object(NonMatching, "auto/auto_802B66E0.cpp"),
            Object(NonMatching, "auto/auto_802B7B20.cpp"),
            Object(NonMatching, "auto/auto_802D3FFC.cpp"),
            Object(NonMatching, "auto/auto_80330E6C.cpp"),
            Object(NonMatching, "auto/auto_803324AC.cpp"),
            Object(NonMatching, "auto/auto_803327B4.cpp"),
            Object(NonMatching, "auto/auto_8033C898.cpp"),
        ],
    },
    {
        "lib": "Lua 5.0.2",
        "mw_version": "GC/2.6",
        "cflags": cflags_lua,
        "progress_category": "lua",
        "objects": [
            Object(NonMatching, "lua/src/lapi.c"),
            Object(NonMatching, "lua/src/lib/lauxlib.c"),
            Object(NonMatching, "lua/src/lib/lbaselib.c"),
            Object(NonMatching, "lua/src/lcode.c"),
            Object(NonMatching, "lua/src/lib/ldblib.c"),
            Object(NonMatching, "lua/src/ldebug.c"),
            Object(NonMatching, "lua/src/ldo.c"),
            Object(Matching, "lua/src/ldump.c"),
            Object(NonMatching, "lua/src/lfunc.c"),
            Object(NonMatching, "lua/src/lgc.c"),
            Object(Matching, "lua/src/llex.c"),
            Object(NonMatching, "lua/src/lmem.c"),
            Object(NonMatching, "lua/src/lobject.c"),
            Object(NonMatching, "lua/src/lparser.c"),
            Object(NonMatching, "lua/src/lstate.c"),
            Object(Matching, "lua/src/lstring.c"),
            Object(NonMatching, "lua/src/lib/lstrlib.c"),
            Object(NonMatching, "lua/src/ltable.c"),
            Object(NonMatching, "lua/src/lib/ltablib.c"),
            Object(NonMatching, "lua/src/ltm.c"),
            Object(NonMatching, "lua/src/lundump.c"),
            Object(NonMatching, "lua/src/lvm.c"),
            Object(Matching, "lua/src/lzio.c"),
        ],
    },
    {
        "lib": "Libpng 1.2.8",
        "mw_version": "GC/2.6",
        "cflags": cflags_libpng,
        # "progress_category": "libpng",  # Leave commented until split
        "objects": [
            Object(NonMatching, "libpng/png.c"),
        ],
    },
    DolphinLib(
        "os",
        [
            Object(NonMatching, "dolphin/os/OS.c"),
            Object(NonMatching, "dolphin/os/OSAlarm.c"),
            Object(NonMatching, "dolphin/os/OSAlloc.c"),
            Object(NonMatching, "dolphin/os/OSArena.c"),
            Object(NonMatching, "dolphin/os/OSAudioSystem.c"),
            Object(NonMatching, "dolphin/os/OSCache.c"),
            Object(Matching, "dolphin/os/OSContext.c"),
            Object(NonMatching, "dolphin/os/OSError.c"),
            Object(NonMatching, "dolphin/os/OSExec.c"),
            Object(NonMatching, "dolphin/os/OSFatal.c"),
            Object(NonMatching, "dolphin/os/OSFont.c"),
            Object(Matching, "dolphin/os/OSInterrupt.c"),
            Object(NonMatching, "dolphin/os/OSLink.c"),
            Object(Matching, "dolphin/os/OSMemory.c"),
            Object(Matching, "dolphin/os/OSMessage.c"),
            Object(NonMatching, "dolphin/os/OSMutex.c"),
            Object(NonMatching, "dolphin/os/OSReboot.c"),
            Object(NonMatching, "dolphin/os/OSReset.c"),
            Object(NonMatching, "dolphin/os/OSResetSW.c"),
            Object(NonMatching, "dolphin/os/OSRtc.c"),
            Object(NonMatching, "dolphin/os/OSThread.c"),
            Object(NonMatching, "dolphin/os/OSTime.c"),
            Object(NonMatching, "dolphin/os/OSSync.c"),
            Object(NonMatching, "dolphin/os/init/__start.c"),
            Object(NonMatching, "dolphin/os/init/__ppc_eabi_init.cpp")
        ]
    ),
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        # "progress_category": "sdk",  # str | List[str]  # Leave commented until split
        "objects": [
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/__mem.c"),
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/__va_arg.c"),
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/global_destructor_chain.c"),
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/CPlusLibPPC.cp"),
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/NMWException.cp", extra_cflags=["-Cpp_exceptions on"]),
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/ptmf.c"),
            Object(Matching, "PowerPC_EABI_Support/Runtime/Src/runtime.c"),
            Object(Matching, "PowerPC_EABI_Support/Runtime/Src/__init_cpp_exceptions.cpp"),
            Object(Matching, "PowerPC_EABI_Support/Runtime/Src/Gecko_ExceptionPPC.cp"),
            Object(NonMatching, "PowerPC_EABI_Support/Runtime/Src/GCN_mem_alloc.c", extra_cflags=["-str reuse,nopool,readonly"]),
        ],
    },
    {
        "lib": "MSL_C",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        # "progress_category": "sdk",  # Leave commented until split
        "objects": [
            Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/abort_exit.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/alloc.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/errno.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/ansi_files.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Src/ansi_fp.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Src/math_sun.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/arith.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/buffer_io.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/char_io.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Src/critical_regions.gamecube.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/ctype.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/locale.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/direct_io.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/file_io.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/FILE_POS.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/mbstring.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/mem.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/mem_funcs.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/math_api.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/misc_io.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/printf.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/scanf.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/float.c"),
            Object(Matching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/signal.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/string.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/strtold.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/wcstoul.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/wctype.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/wmem.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/wprintf.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/wscanf.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/strtoul.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/wstring.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/wchar_io.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/secure_error.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/math_double.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Src/uart_console_io_gcn.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_acos.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_asin.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_atan2.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_exp.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_fmod.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_log.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_log10.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_pow.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_rem_pio2.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/k_cos.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/k_rem_pio2.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/k_sin.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/k_tan.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_atan.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_ceil.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_copysign.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_cos.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_floor.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_frexp.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_ldexp.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_modf.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_sin.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/s_tan.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/w_acos.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/w_asin.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/w_atan2.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/w_exp.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/w_fmod.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/w_log10.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/w_pow.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/e_sqrt.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Src/abort_exit_ppc_eabi.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Src/math_ppc.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/w_sqrt.c"),
            Object(NonMatching, "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/extras.c"),
        ],
    },
]


# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects


# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
    ProgressCategory("lua", "Lua Code"),
]
config.progress_each_module = args.verbose
# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
