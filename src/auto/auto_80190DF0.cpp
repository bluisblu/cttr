

struct Script {};

struct LoadSet {};

struct ScriptPlayer {
    void SetScript(Script *pScript);
    void SetScriptNative(LoadSet *pScript);
    void PlaySync();
    void PlayAsync();
    void Stop();
    void Relinquish();
    void Pause();
    void Resume();
    bool IsStopped();
    bool IsPlaying();
    bool IsPaused();
};

void ScriptPlayer::SetScript(Script *pScript) {}

void ScriptPlayer::SetScriptNative(LoadSet *pScript) {}

void ScriptPlayer::PlaySync() {}

void ScriptPlayer::PlayAsync() {}

void ScriptPlayer::Stop() {}

void ScriptPlayer::Relinquish() {}

void ScriptPlayer::Pause() {}

void ScriptPlayer::Resume() {}

bool ScriptPlayer::IsStopped() {
    return true;
}

bool ScriptPlayer::IsPlaying() {
    return true;
}

bool ScriptPlayer::IsPaused() {
    return true;
}
