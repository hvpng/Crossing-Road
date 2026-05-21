#pragma once

#include <SFML/Graphics.hpp>

namespace cfg {
constexpr unsigned WindowWidth = 1280;
constexpr unsigned WindowHeight = 720;
constexpr float SidebarWidth = 260.f;
constexpr float PlayWidth = WindowWidth - SidebarWidth;
constexpr float Tile = 48.f;
constexpr float LaneHeight = 96.f;
constexpr int MaxLevel = 10;
constexpr float TargetFrameSeconds = 1.f / 60.f;
}

enum class Direction { None, Up, Down, Left, Right };
enum class Scene { MainMenu, MapSelect, NameInput, Playing, PauseMenu, LoadGame, Setting, Help, Quit };
enum class LightState { Green, Red };
