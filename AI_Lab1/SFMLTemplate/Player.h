#pragma once

#include "SFML/Graphics.hpp"

class Player
{
public:
	void load();
	void update(sf::Time t_deltaTime);
	void draw(sf::RenderWindow* t_win);
	void setDirection(int t_direction);
	void increaseSpeed();
	void decreaseSpeed();


	void checkScreenWrap();
	void changeDirection(int t_direction);
private:
	double m_direction{ 6 };

	sf::Vector2f m_positionVector;
	sf::Vector2f m_directionVector;
	sf::Vector2f m_velocityVector;
	sf::Vector2f m_accelerationVector;

	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;

	bool m_doAccerlerate{ false };
	bool m_doBrake{ false };
};

