#include "Bullet.h"
#include <Novice.h>

void Bullet::Initialize(Vector2 position)
{
	position_ = position;
	isActive_ = true;
}

void Bullet::Update()
{
	position_.y -= 20.0f;

	if (position_.y + radius_ < 0) {
		isActive_ = false;
	}

}

void Bullet::Draw()
{
	Novice::DrawEllipse(int(position_.x), int(position_.y), int(radius_), int(radius_), 0.0f, RED, kFillModeSolid);
}
