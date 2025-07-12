export module Usings;

import stl;
import sfml;

export using TimeListCollection = std::vector<std::shared_ptr<sf::Time>>;
export using FrameListCollection = std::vector<std::shared_ptr<sf::Sprite>>;