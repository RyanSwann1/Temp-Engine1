#include "StateGame.h"
#include "StateManager.h"
#include "EntityManager.h"
#include "EnemySpawner.h"
#include "PowerUpSpawner.h"
#include "PowerUpWeapon.h"
#include <iostream>
#include <assert.h>

StateGame::StateGame(StateManager* stateManager)
	: StateBase(stateManager),
	m_timeElasped(0),
	m_gamePaused(false)
{}

StateGame::~StateGame()
{
	for (auto &i : m_spawners)
	{
		delete i;
		i = nullptr;
	}
	m_spawners.clear();
}

void StateGame::onCreate()
{
	std::cout << "StateGame Created." << "\n";
	EntityManager* entityManager = m_stateManager->getSharedContext()->m_entityManager;
	entityManager->addEntity(EntityType::Player);
	m_spawners.emplace_back(new EnemySpawner(entityManager));
	m_spawners.emplace_back(new PowerUpSpawner(entityManager));
	m_stateManager->getSharedContext()->m_eventSystem->addCallback<StateGame>(StateType::Game, "Pause", &StateGame::reactToInput, this);
}

void StateGame::onDestroy()
{
	for (auto &i : m_spawners)
	{
		delete i;
		i = nullptr;
	}
	m_spawners.clear();
	m_stateManager->getSharedContext()->m_entityManager->purgeEntities();
	m_stateManager->getSharedContext()->m_eventSystem->removeCallback(StateType::Game, "Pause");
}

void StateGame::onEnter()
{
	m_gamePaused = false;
}

void StateGame::onExit()
{
	m_gamePaused = true;
}

void StateGame::update(const float deltaTime)
{
	if (!m_gamePaused)
	{
		m_timeElasped += deltaTime;
		for (auto &i : m_spawners)
		{
			i->update(m_timeElasped);
		}
		m_stateManager->getSharedContext()->m_entityManager->update(deltaTime);
	}

}

void StateGame::draw(sf::RenderWindow & window)
{
	m_stateManager->getSharedContext()->m_entityManager->draw(window);
	
	//Draw paused UI
	if (m_gamePaused)
	{

	}
}

void StateGame::reactToInput(EventDetails * eventDetails)
{
	if (eventDetails->m_name == "Pause")
	{
		m_gamePaused = !m_gamePaused;
	}
}


