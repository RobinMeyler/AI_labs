#pragma once

#include "SFML/Graphics.hpp"

class Player
{
public:
	void load();
	void update();
	void draw(sf::RenderWindow* t_win);
	void setDirection(int t_direction);
	void increaseSpeed();
	void decreaseSpeed();

private:
	double m_direction{ 6 };
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;
};

