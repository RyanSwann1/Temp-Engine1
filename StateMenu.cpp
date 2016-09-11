#include "StateMenu.h"
#include "StateManager.h"


StateMenu::StateMenu(StateManager* stateManager)
	:StateBase(stateManager)
{
	m_stateManager->getSharedContext()->m_eventSystem->addCallback<StateMenu>(StateType::MainMenu, "Next_Level", &StateMenu::reactToInput, this);
}

StateMenu::~StateMenu()
{
	m_stateManager->getSharedContext()->m_eventSystem->removeCallback(StateType::MainMenu, "Next_Level");
}

void StateMenu::onEnter()
{
	std::cout << "Press enter to continue." << "\n";
}

void StateMenu::update(const float deltaTime)
{
	
}

void StateMenu::draw(sf::RenderWindow & window)
{
	
}

void StateMenu::reactToInput(EventDetails * eventDetails)
{
	if (eventDetails->m_name == "Next_Level")
	{
		m_stateManager->switchTo(StateType::Game);
		m_stateManager->remove(StateType::MainMenu);
	}
}
