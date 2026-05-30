#include "CTTR/GameObject.h"
#include "CTTR/Player.h"

#include "types.h"

struct Car : GameObject {
    Car() {}
    ~Car() {}
};

struct Character : GameObject {
    Character() {}
    ~Character() {}
};

struct AIRaceMotifManifest : GameObject {
    AIRaceMotifManifest() {}
    ~AIRaceMotifManifest() {}
};

struct AIBattleMotifManifest : GameObject {
    AIBattleMotifManifest() {}
    ~AIBattleMotifManifest() {}
};

struct NPCObject : GameObject {
    NPCObject() {}
    ~NPCObject() {}
};

struct Avatar : GameObject {
    Avatar() {}
    ~Avatar() {}

    void InitializeForDriving();
    void InitializeForWalking();
    void InitializeForBattleMode();
    void InitializeForStuntMode();
    void InitializeForMiniGame();
    void Clear();
    void Reset();
    Player* GetPlayer();
    void SetPlayer(Player* p);
    void SetVehicle(Car* vehicle);
    void SetClashedVehicle(Car* vehicle);
    Car* GetVehicle();
    void SetCharacter(Character* character);
    Character* GetCharacter();
    bool IsAI();
    void SetAIRaceMotifManifestEntry(AIRaceMotifManifest* manifest, const char* charName,
                                     const char* carName);
    void SetAIBattleMotifManifestEntry(AIBattleMotifManifest* manifest, const char* charName,
                                       const char* carName);
    NPCObject* GetNPCObject();
};

void __deadstripped() {
    Avatar* avatar = new Avatar();
    delete avatar;
}

void Avatar::InitializeForDriving() {}
void Avatar::InitializeForWalking() {}
void Avatar::InitializeForBattleMode() {}
void Avatar::InitializeForStuntMode() {}
void Avatar::InitializeForMiniGame() {}
void Avatar::Clear() {}
void Avatar::Reset() {}
Player* Avatar::GetPlayer() {
    return NULL;
}
void Avatar::SetPlayer(Player* p) {}
void Avatar::SetVehicle(Car* vehicle) {}
void Avatar::SetClashedVehicle(Car* vehicle) {}
Car* Avatar::GetVehicle() {
    return NULL;
}
void Avatar::SetCharacter(Character* character) {}
Character* Avatar::GetCharacter() {
    return NULL;
}
bool Avatar::IsAI() {
    return false;
}
void Avatar::SetAIRaceMotifManifestEntry(AIRaceMotifManifest* manifest, const char* charName,
                                         const char* carName) {}
void Avatar::SetAIBattleMotifManifestEntry(AIBattleMotifManifest* manifest, const char* charName,
                                           const char* carName) {}
NPCObject* Avatar::GetNPCObject() {
    return NULL;
}
