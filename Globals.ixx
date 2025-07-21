export module Globals;

import sfml;

export sf::RenderWindow g_MainWindow(sf::VideoMode::getDesktopMode(), "Tank Striker");
export constexpr int64_t g_MovementCoef = 1000 * 60;
export constexpr bool isDebugModeEnabled = true;