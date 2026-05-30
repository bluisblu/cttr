#ifndef __NISMANAGER_H__
#define __NISMANAGER_H__

#include "CTTR/LoadSet.h"
#include "CTTR/Sound.h"
#include "pure3d/Animation.h"
#include "pure3d/CompositeDrawable.h"
#include "pure3d/VectorCamera.h"

#include "types.h"

struct NISManager {
    virtual ~NISManager() {}

    void SetLipSyncDataLoadSet(LoadSet* loadset);
    void ReleaseLipSyncDataLoadSet();
    void StartLetterbox(bool isBlocking);
    void StartSound(bool isBlocking, Sound* soundObj);
    void StartCuedSoundWithLineNumber(Sound* soundObj, int lineNumber, bool playPastEnd);
    void StartCuedSound(Sound* soundObj);
    void StartSoundWithLipSync(bool isBlocking, const char* characterName, Sound* soundName,
                               int lineNumber, const char* lipSyncDataName,
                               const char* animationName, bool loopAnimation);
    void StartTimer(float time);
    void StartConversationCamera();
    void StartLocatorCamera(const char* axisLocatorName);
    void StartLocatorCameraWithLocatorTarget(const char* cameraLocatorName,
                                             const char* targetLocatorName);
    void StartLocatorCameraWithCharacterTarget(const char* cameraLocatorName,
                                               const char* characterName);
    void StartAnimatedCamera(bool isBlocking, pure3d::Animation* anim, bool TransitionIn,
                             bool TransitionOut);
    void StartPure3dCamera(pure3d::VectorCamera* camera);
    void StartPure3dCameraAtCharacter(pure3d::VectorCamera* camera, const char* characterName,
                                      bool TransitionIn, bool TransitionOut);
    void StartDrawable(bool isBlocking, pure3d::CompositeDrawable* drawable,
                       const char* axisLocatorName);
    void StartScreenDrawable(bool isBlocking, pure3d::CompositeDrawable* drawable, float duration,
                             float scale, float yOffset);
    void StartAnimation(const char* characterName, const char* animationName, bool isLooping,
                        int startFrame, int endFrame, bool altModel);
    void StartFadeToBlack(float fadeTimeInSeconds, bool fadeIntoBlack, bool blocking);
    void ShowTutorialHud(int hudNumber, bool useChickIcon);
    void PauseGame();
    void BlockControllerInput();
    void OrientConversers();
    void DisableCharacterRendering();
    void PlaceCharacterOnLocator(const char* characterName, const char* locatorName,
                                 const char* facingLocatorName);
    void ResetAnimation(const char* characterName);
    void ResetCharacter(const char* characterName);
    void MarkCurrentNISAsTutorial();
    void DoLevelShutdown();
    void WaitForOnFootIdle();
    void WaitIfDialogUp();
    bool IsPlaying();
};

#endif
