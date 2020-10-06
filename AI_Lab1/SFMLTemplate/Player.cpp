#include "Player.h"

void Player::load()
{
	m_playerTexture.loadFromFile("sword.png");
	m_playerSprite.setTexture(m_playerTexture);
	m_playerSprite.setPosition(200, 800);
	m_playerSprite.setScale(2, 2);
}

void Player::update()
{
	m_playerSprite.move(0, m_direction);

	if (m_playerSprite.getPosition().y > 1600)
	{
		m_playerSprite.setPosition( m_playerSprite.getPosition().x,-128);
	}
	else if (m_playerSprite.getPosition().y < -128)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, 1600);
	}
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
	if(m_direction < 15)
		m_direction += 0.1;
}

void Player::decreaseSpeed()
{
	if (m_direction > 0.1)
		m_direction -= 0.1;
}
