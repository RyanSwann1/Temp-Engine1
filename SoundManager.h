//#pragma once
//#include "ResourceManager.h"
//#include <SFML\Audio.hpp>
//class SoundManager
//	: public ResourceManager<sf::SoundBuffer>
//{
//public:
//	SoundManager() 
//	{
//		loadIn();
//	}
//	~SoundManager() {}
//
//	sf::SoundBuffer* loadFromFilePath(const std::string& id) override
//	{
//		sf::SoundBuffer* soundBuffer = new sf::SoundBuffer;
//		auto iter = m_filePath.find(id);
//		if (iter != m_filePath.cend())
//		{
//			if (!soundBuffer->loadFromFile(iter->second))
//			{
//				delete soundBuffer;
//				soundBuffer = nullptr;
//				return nullptr;
//			}
//			return soundBuffer;
//		}
//		return nullptr;
//	}
//
//private:
//	void loadIn()
//	{
//		m_filePath["PLayer_Fire"] = "Audio/Player_Fire.ogg";
//	}
//};