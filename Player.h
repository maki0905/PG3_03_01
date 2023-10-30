#pragma once

#include <list>

#include "Vector2.h"
#include "Bullet.h"
class Player
{
public:
	void Initialize();
	void Update();
	void Draw();

	std::list<Bullet*> GetBullets() { return bullets_; }
private:
	Vector2 position_;

	std::list<Bullet*> bullets_;

	const Vector2 startPosition_ = { 640.0f, 360.0f };
	const Vector2 area_ = { 640.0f, 360.0f };
	const float movementSpeed_ = 10.0f;
	const float width_ = 20.0f;
	const float height_ = 20.0f;
};

