export module Globals;

import sfml;

export sf::RenderWindow g_MainWindow(sf::VideoMode::getDesktopMode(), "Tank Striker");
export constexpr int64_t g_MillisecondsInSeconds = 1000 * 60;
export constexpr bool isDebugModeEnabled = false;