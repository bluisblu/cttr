#include "CTTR/GameObject.h"
#include "CTTR/NISManager.h"

struct TriggerPropMotif : GameObject {
    virtual ~TriggerPropMotif() {}
};

struct DynamicPropMotif : TriggerPropMotif {
    virtual ~DynamicPropMotif() {}
};

struct Prop : GameObject {
    virtual ~Prop() {}
};

struct PropWithDrawFunction : Prop {
    virtual ~PropWithDrawFunction() {}
};

struct TriggerProp : PropWithDrawFunction {
    virtual ~TriggerProp() {}
};

struct StateProp : TriggerProp {
    virtual ~StateProp() {}
};

struct StatePropMotif : TriggerPropMotif {
    virtual ~StatePropMotif() {}
};

struct StaticProp : Prop {
    virtual ~StaticProp() {}
};

struct NISPresentationElement {
    virtual ~NISPresentationElement() {}
};

struct CameraPresentationElement : NISPresentationElement {
    virtual ~CameraPresentationElement() {}
};

struct AnimatedCameraPresentationElement : CameraPresentationElement {
    virtual ~AnimatedCameraPresentationElement() {}
};

struct AnimationPresentationElement : NISPresentationElement {
    virtual ~AnimationPresentationElement() {}
};

struct BlockControllerPresentationElement : NISPresentationElement {
    virtual ~BlockControllerPresentationElement() {}
};

struct BlockOnDialogPresentationElement : NISPresentationElement {
    virtual ~BlockOnDialogPresentationElement() {}
};

struct PositionedCameraPresentationElement : CameraPresentationElement {
    virtual ~PositionedCameraPresentationElement() {}
};

struct ConversationCameraPresentationElement : PositionedCameraPresentationElement {
    virtual ~ConversationCameraPresentationElement() {}
};

struct CuedSoundPresentationElement : NISPresentationElement {
    virtual ~CuedSoundPresentationElement() {}
};

struct DrawablePresentationElement : NISPresentationElement {
    virtual ~DrawablePresentationElement() {}
};

struct FadeToBlackPresentationElement : NISPresentationElement {
    virtual ~FadeToBlackPresentationElement() {}
};

struct LetterboxPresentationElement : NISPresentationElement {
    virtual ~LetterboxPresentationElement() {}
};

struct LipSyncPresentationElement : NISPresentationElement {
    virtual ~LipSyncPresentationElement() {}
};

struct LocatorCameraPresentationElement : PositionedCameraPresentationElement {
    virtual ~LocatorCameraPresentationElement() {}
};

struct PausePresentationElement : NISPresentationElement {
    virtual ~PausePresentationElement() {}
};

// Temporary function to grab mangled symbols for destructors
void __deadstripped_80013F40() {
    DynamicPropMotif* motif = new DynamicPropMotif();
    delete motif;

    Prop* prop = new Prop();
    delete prop;

    StateProp* stateProp = new StateProp();
    delete stateProp;

    StatePropMotif* statePropMotif = new StatePropMotif();
    delete statePropMotif;

    StaticProp* staticProp = new StaticProp();
    delete staticProp;

    AnimatedCameraPresentationElement* animatedCameraPresentationElement =
        new AnimatedCameraPresentationElement();
    delete animatedCameraPresentationElement;

    AnimationPresentationElement* animationPresentationElement = new AnimationPresentationElement();
    delete animationPresentationElement;

    BlockControllerPresentationElement* blockControllerPresentationElement =
        new BlockControllerPresentationElement();
    delete blockControllerPresentationElement;

    BlockOnDialogPresentationElement* blockOnDialogPresentationElement =
        new BlockOnDialogPresentationElement();
    delete blockOnDialogPresentationElement;

    ConversationCameraPresentationElement* conversationCameraPresentationElement =
        new ConversationCameraPresentationElement();
    delete conversationCameraPresentationElement;

    CuedSoundPresentationElement* cuedSoundPresentationElement = new CuedSoundPresentationElement();
    delete cuedSoundPresentationElement;

    DrawablePresentationElement* drawablePresentationElement = new DrawablePresentationElement();
    delete drawablePresentationElement;

    FadeToBlackPresentationElement* fadeToBlackPresentationElement =
        new FadeToBlackPresentationElement();
    delete fadeToBlackPresentationElement;

    LetterboxPresentationElement* letterboxPresentationElement = new LetterboxPresentationElement();
    delete letterboxPresentationElement;

    LipSyncPresentationElement* lipSyncPresentationElement = new LipSyncPresentationElement();
    delete lipSyncPresentationElement;

    LocatorCameraPresentationElement* locatorCameraPresentationElement =
        new LocatorCameraPresentationElement();
    delete locatorCameraPresentationElement;

    NISManager* nisManager = new NISManager();
    delete nisManager;

    PausePresentationElement* pausePresentationElement = new PausePresentationElement();
    delete pausePresentationElement;
}

NISManager* gNISManager;

NISManager* NISManager_Get() {
    return gNISManager;
}

void NISManager::SetLipSyncDataLoadSet(LoadSet* loadset) {}
void NISManager::ReleaseLipSyncDataLoadSet() {}
void NISManager::StartLetterbox(bool isBlocking) {}
void NISManager::StartSound(bool isBlocking, Sound* soundObj) {}
void NISManager::StartCuedSoundWithLineNumber(Sound* soundObj, int lineNumber, bool playPastEnd) {}
void NISManager::StartCuedSound(Sound* soundObj) {}
void NISManager::StartSoundWithLipSync(bool isBlocking, const char* characterName, Sound* soundName,
                                       int lineNumber, const char* lipSyncDataName,
                                       const char* animationName, bool loopAnimation) {}
void NISManager::StartTimer(float time) {}
void NISManager::StartConversationCamera() {}
void NISManager::StartLocatorCamera(const char* axisLocatorName) {}
void NISManager::StartLocatorCameraWithLocatorTarget(const char* cameraLocatorName,
                                                     const char* targetLocatorName) {}
void NISManager::StartLocatorCameraWithCharacterTarget(const char* cameraLocatorName,
                                                       const char* characterName) {}
void NISManager::StartAnimatedCamera(bool isBlocking, pure3d::Animation* anim, bool TransitionIn,
                                     bool TransitionOut) {}
void NISManager::StartPure3dCamera(pure3d::VectorCamera* camera) {}
void NISManager::StartPure3dCameraAtCharacter(pure3d::VectorCamera* camera,
                                              const char* characterName, bool TransitionIn,
                                              bool TransitionOut) {}
void NISManager::StartDrawable(bool isBlocking, pure3d::CompositeDrawable* drawable,
                               const char* axisLocatorName) {}
void NISManager::StartScreenDrawable(bool isBlocking, pure3d::CompositeDrawable* drawable,
                                     float duration, float scale, float yOffset) {}
void NISManager::StartAnimation(const char* characterName, const char* animationName,
                                bool isLooping, int startFrame, int endFrame, bool altModel) {}
void NISManager::StartFadeToBlack(float fadeTimeInSeconds, bool fadeIntoBlack, bool blocking) {}
void NISManager::ShowTutorialHud(int hudNumber, bool useChickIcon) {}
void NISManager::PauseGame() {}
void NISManager::BlockControllerInput() {}
void NISManager::OrientConversers() {}
void NISManager::DisableCharacterRendering() {}
void NISManager::PlaceCharacterOnLocator(const char* characterName, const char* locatorName,
                                         const char* facingLocatorName) {}
void NISManager::ResetAnimation(const char* characterName) {}
void NISManager::ResetCharacter(const char* characterName) {}
void NISManager::MarkCurrentNISAsTutorial() {}
void NISManager::DoLevelShutdown() {}
void NISManager::WaitForOnFootIdle() {}
void NISManager::WaitIfDialogUp() {}
bool NISManager::IsPlaying() {}
