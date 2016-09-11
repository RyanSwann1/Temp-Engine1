#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <vector>
struct EventDetails;
class Player :
	public Character
{
public:
	Player(EntityManager* entityManager);
	~Player();

	void onEntityCollision(Entity* collider) override;
	void update(const float deltaTime) override;
	void addUpgradedAmmoCount(const unsigned int i) { m_upgradedAmmoCount += i; }
	void addScore(const unsigned int i) { m_score += i; }

private:

	void reactToInput(EventDetails* eventDetails);
	void fireLaser();
	bool m_weaponUpgrade;
	unsigned int m_upgradedAmmoCount;
	unsigned int m_score;
	inline sf::Vector2f getFirePos() const { return sf::Vector2f(m_position.x, m_position.y); }
};
#endif // !PLAYER_H
