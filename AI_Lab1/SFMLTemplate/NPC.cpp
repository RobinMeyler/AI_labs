#include "NPC.h"
#include "Game.h"


void NPC::load()
{
	m_npcTexture.loadFromFile("blob.png");
	m_npcSprite.setTexture(m_npcTexture);
	m_npcSprite.setPosition(1200, 800);
	m_npcSprite.setScale(2, 2);
}

void NPC::update(sf::Time t_deltaTime)
{
	m_npcSprite.move(0, m_direction);

	checkScreenWrap();
}

void NPC::draw(sf::RenderWindow* t_win)
{
	t_win->draw(m_npcSprite);
}

void NPC::checkScreenWrap()
{
	// Top / Bottom
	if (m_npcSprite.getPosition().y > Game::m_screenDimensions.y)
	{
		m_npcSprite.setPosition(m_npcSprite.getPosition().x, -m_npcSprite.getGlobalBounds().width);
	}
	else if (m_npcSprite.getPosition().y < -m_npcSprite.getGlobalBounds().height)
	{
		m_npcSprite.setPosition(m_npcSprite.getPosition().x, Game::m_screenDimensions.y);
	}

	// Right / Left
	if (m_npcSprite.getPosition().x > Game::m_screenDimensions.x)
	{
		m_npcSprite.setPosition(-m_npcSprite.getGlobalBounds().width, m_npcSprite.getPosition().y);
	}
	else if (m_npcSprite.getPosition().x < -m_npcSprite.getGlobalBounds().width)
	{
		m_npcSprite.setPosition(Game::m_screenDimensions.x, m_npcSprite.getPosition().y);
	}
}