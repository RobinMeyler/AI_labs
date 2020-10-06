#pragma once

#include "SFML/Graphics.hpp"

class NPC
{
public:
	void load();
	void update();
	void draw(sf::RenderWindow* t_win);


private:
	double m_direction{ 6 };
	sf::Texture m_npcTexture;
	sf::Sprite m_npcSprite;
};

