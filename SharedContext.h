#ifndef SHARED_CONTEXT_H
#define SHARED_CONTEXT_H

#include "Window.h"
#include "EventSystem.h"
#include "TextureManager.h"
#include "SoundManager.h"
class EntityManager;
class StateManager;
struct SharedContext
{
	SharedContext() :
		m_stateManager(nullptr),
		m_window(nullptr),
		m_eventSystem(nullptr),
		m_entityManager(nullptr),
		m_textureManager(nullptr) {}
		//m_soundManager(nullptr) {}

	StateManager* m_stateManager;
	TextureManager* m_textureManager;
	//SoundManager* m_soundManager;
	EntityManager* m_entityManager;
	EventSystem* m_eventSystem;
	Window* m_window;
};
#endif // !SHARED_CONTEXT_H

