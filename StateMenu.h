#pragma once
#include "StateBase.h"
#include "EventSystem.h"
class StateMenu :
	public StateBase
{
public:
	StateMenu(StateManager* stateManager);
	~StateMenu();


	void onEnter() override;
	void update(const float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

private:
	void reactToInput(EventDetails* eventDetails);

};

