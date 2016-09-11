#include "Enemy.h"
#include "EntityManager.h"
#include "EnemyLaser.h"
#include "Player.h"

Enemy::Enemy(EntityManager* entityManager)
	: Character(entityManager)
{
	m_name = "Enemy";
	m_speed = sf::Vector2f(.025f, .025f);
	m_direction = Direction::Up;
	m_entityType = EntityType::Enemy;
	m_size = sf::Vector2f(.5f, .5f);
	m_lives = 1;
	m_onCollisionDamage = 1;
	m_nextFireTime = 0.75f;
	m_timeBetweenFire = 3.5f;
	m_timeElasped = 0;
	m_onDestroyPoint = 1;
	Entity::applyTexture();
}

Enemy::~Enemy()
{}

void Enemy::onEntityCollision(Entity * collision)
{
	if (collision->getType() == EntityType::Player)
	{
		Player* player = (Player*)collision;
		player->reduceLivesAmount(m_onCollisionDamage);
		player->addScore(m_onDestroyPoint);
	}

	m_entityManager->removeEntity(m_ID);
}

void Enemy::update(const float deltaTime)
{
	m_timeElasped += deltaTime;
	Character::move(m_direction);
	Entity::update(deltaTime);

	sf::Vector2u mapSize = m_entityManager->getSharedContext()->m_window->getSize();
	if (m_position.y <= 0)
	{
		m_entityManager->removeEntity(m_ID);
	}
	
	if (m_timeElasped >= m_nextFireTime)
	{
		fireProjectile();
		m_nextFireTime += m_timeBetweenFire;
	}
}

void Enemy::fireProjectile()
{
	Entity* projectile = new EnemyLaser(m_entityManager);
	projectile->setStartPos(getFirePos());
	m_entityManager->addEntity(EntityType::EnemyProjectile, projectile);
}