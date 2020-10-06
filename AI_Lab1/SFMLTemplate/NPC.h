#pragma once

#include "SFML/Graphics.hpp"

class NPC
{
public:
	void load();
	void update(sf::Time t_deltaTime);
	void draw(sf::RenderWindow* t_win);

	void checkScreenWrap();
	
private:
	double m_direction{ 6 };
	sf::Texture m_npcTexture;
	sf::Sprite m_npcSprite;
};

