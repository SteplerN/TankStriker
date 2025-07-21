export module Usings;

import std;
import sfml;

import HitBox;

export using TimeListCollection = std::vector<std::shared_ptr<sf::Time>>;
export using FrameListCollection = std::vector<std::shared_ptr<sf::Sprite>>;
export using HitBoxCollection = std::vector<std::vector<std::shared_ptr<HitBox>>>;