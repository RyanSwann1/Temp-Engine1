#include "Character.h"
#include "EntityManager.h"
#include <iostream>


Character::Character(EntityManager* entityManager)
	:Entity(entityManager)
{
}

Character::~Character()
{
}

void Character::move(const Direction dir)
{
	switch (dir)
	{
	case (Direction::Left) :
	{
		setVelocity(-m_speed.x, 0);
		break;
	}
	case (Direction::Right) :
	{
		setVelocity(m_speed.x, 0);
		break;
	}
	case (Direction::Up) :
	{
		setVelocity(0, -m_speed.y);
		break;
	}
	case (Direction::Down) :
	{
		setVelocity(0, m_speed.y);
		break;
	}

	}
}

void Character::reduceLivesAmount(const unsigned int i)
{
	m_lives -= i;
	if (m_lives <= 0) {
		m_entityManager->removeEntity(m_ID);
	}
}

void Character::addLivesAmount(const unsigned int i)
{
	//Do not let 'm_lives' exceed m_maxLives
	((m_lives + i) >= m_maxLives ? m_lives = m_maxLives : m_lives += i);
}
