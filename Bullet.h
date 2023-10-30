#pragma once

#include "Vector2.h"
class Bullet
{
public:
	void Initialize(Vector2 position);
	void Update();
	void Draw();
	bool GetIsActive() { return isActive_; }
	void OnCollision() { isActive_ = false; }
	Vector2 GetPosition() { return position_; }
	float GetRadius() { return radius_; }
private:
	Vector2 position_;
	const float radius_ = 5.0f;
	bool isActive_ = false;
};

