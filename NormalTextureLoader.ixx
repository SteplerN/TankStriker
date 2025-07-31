export module NormalTextureLoader;

import std;
import sfml;

import KillProgram;

export auto& normalTextureLoading(sf::Texture& p_Texture, const std::string& p_FileName)
{
	if (!p_Texture.loadFromFile(p_FileName)) KillProgram();
	return p_Texture;
}