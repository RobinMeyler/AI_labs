#include "NPC.h"


void NPC::load()
{
	m_npcTexture.loadFromFile("blob.png");
	m_npcSprite.setTexture(m_npcTexture);
	m_npcSprite.setPosition(1200, 800);
	m_npcSprite.setScale(2, 2);
}

void NPC::update()
{
	m_npcSprite.move(m_direction, 0);

	if (m_npcSprite.getPosition().x > 1600)
	{
		m_npcSprite.setPosition(-128, m_npcSprite.getPosition().y);
	}
	else if (m_npcSprite.getPosition().x < -128)
	{
		m_npcSprite.setPosition(1600, m_npcSprite.getPosition().y);
	}
}

void NPC::draw(sf::RenderWindow* t_win)
{
	t_win->draw(m_npcSprite);
}