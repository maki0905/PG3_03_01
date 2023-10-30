#include "Enemy.h"
#include <Novice.h>


void Enemy::Initialize(Vector2 position)
{
	position_ = position;
	isActive_ = true;
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Novice::DrawBox(int(position_.x - width_ / 2.0f), int(position_.y - height_ / 2.0f), int(width_), int(height_), 0.0f, BLUE, kFillModeSolid);

}
