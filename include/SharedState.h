#pragma once

#include "Constants.h"
#include <mutex>
#include <string>

struct SharedState {
    std::mutex mutex;
    bool isRunning = true;
    bool isPaused = false;
    bool requestRestart = false;
    bool requestSave = false;
    bool bgmEnabled = true;
    bool sfxEnabled = true;
    Direction moving = Direction::None;
    Scene scene = Scene::MainMenu;
    int menuIndex = 0;
    int selectedMap = 0;
    std::string playerName = "Player";
};
