#include "Player.h"
#include "Game.h"

void Player::load()
{
	m_playerTexture.loadFromFile("sword.png");
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setPosition(200, 800);
	
	m_playerSprite.setScale(2, 2);
	m_playerSprite.setOrigin(m_playerSprite.getGlobalBounds().width / 4, m_playerSprite.getGlobalBounds().height / 4);

	m_positionVector = { 200, 800 };
	m_directionVector = { 90, 0 };
	m_velocityVector = { 2, 0 };
	m_accelerationVector = { 0,0 };
}

void Player::update(sf::Time t_deltaTime)
{
	if (m_doAccerlerate == true)
	{
		m_accelerationVector = m_directionVector * 2.f;
	}
	else if (m_doBrake == true)
	{
		m_accelerationVector = (-1.f)*(m_directionVector*2.f);
	}
	else
	{
		m_accelerationVector = { 0,0 };
	}

	float current_speed = std::sqrt(m_velocityVector.x * m_velocityVector.x + m_velocityVector.y * m_velocityVector.y); // Length

	if (current_speed < 800)	// MaxSpeed
	{
		m_velocityVector = m_velocityVector + (m_accelerationVector * t_deltaTime.asSeconds());
	}

	m_positionVector = m_positionVector + (m_velocityVector * t_deltaTime.asSeconds());
	m_playerSprite.setPosition(m_positionVector);



	checkScreenWrap();

	m_doAccerlerate = false;
	m_doBrake = false;
}

void Player::draw(sf::RenderWindow* t_win)
{
	t_win->draw(m_playerSprite);
}

void Player::setDirection(int t_direction)
{
	m_direction = t_direction;
}

void Player::increaseSpeed()
{
	m_doAccerlerate = true;
}

void Player::decreaseSpeed()
{
	m_doBrake = true;
}

void Player::checkScreenWrap()
{
	// Top / Bottom
	if (m_playerSprite.getPosition().y > Game::m_screenDimensions.y)
	{
		m_positionVector = { m_playerSprite.getPosition().x, -m_playerSprite.getGlobalBounds().height / 2 };
	}
	else if (m_playerSprite.getPosition().y < -m_playerSprite.getGlobalBounds().height / 2)
	{
		m_positionVector = { m_playerSprite.getPosition().x, Game::m_screenDimensions.y };
	}

	// Right / Left
	if (m_playerSprite.getPosition().x > Game::m_screenDimensions.x)
	{
		m_positionVector = { -m_playerSprite.getGlobalBounds().width / 4, m_playerSprite.getPosition().y };
	}
	else if (m_playerSprite.getPosition().x < -m_playerSprite.getGlobalBounds().width / 4)
	{
		m_positionVector = { Game::m_screenDimensions.x, m_playerSprite.getPosition().y };
	}
}

void Player::changeDirection(int t_direction)
{
	if (t_direction < 0)
	{
		m_velocityVector = { -abs(m_velocityVector.x), -abs(m_velocityVector.y) };
		m_directionVector = { -abs(m_directionVector.x), -abs(m_directionVector.y) };
		m_playerSprite.setScale(-abs(m_playerSprite.getScale().x), m_playerSprite.getScale().y);
	}
	else
	{
		m_velocityVector = { abs(m_velocityVector.x), abs(m_velocityVector.y) };
		m_directionVector = { abs(m_directionVector.x), abs(m_directionVector.y) };
		m_playerSprite.setScale(abs(m_playerSprite.getScale().x), m_playerSprite.getScale().y);
	}
}
