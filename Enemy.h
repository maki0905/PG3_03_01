#pragma once

#include "Vector2.h"
class Enemy
{
public:
	void Initialize(Vector2 position);
	void Update();
	void Draw();
	void OnCollision() { isActive_ = false; }
	bool GetIsActive() { return isActive_; }
	Vector2 GetPosition() { return position_; }
	float GetRadius() { return radius_; }
private:
	Vector2 position_;
	bool isActive_ = false;
	const float radius_ = 25.0f;
	const float width_ = 50.0f;
	const float height_ = 50.0f;
};

