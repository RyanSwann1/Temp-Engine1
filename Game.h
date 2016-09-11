#ifndef GAME_H
#define GAME_H

#include "EntityManager.h"
#include "StateManager.h"
#include "Window.h"
#include "SharedContext.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include <SFML\Graphics.hpp>

//Design patterns to include
//http://gameprogrammingpatterns.com/observer.html

class Game
{
public:
	Game();
	~Game();

	bool isRunning() const { return m_window.isRunning(); }

	void update();
	void render();
	void lateUpdate();

private:
	SharedContext m_sharedContext;
	Window m_window;
	StateManager m_stateManager;
	EntityManager m_entityManager;
	TextureManager m_textureManager;
	//SoundManager m_soundManager;
	sf::Clock m_clock;
	sf::Time m_elaspedTime;
};
#endif // !GAME_H
