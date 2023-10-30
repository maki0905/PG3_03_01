#include "Player.h"
#include <Novice.h>
#include "InputManager.h"

void Player::Initialize()
{
	position_ = startPosition_;

}

void Player::Update()
{
	Vector2 velocity_ = { 0.0f, 0.0f };

	if (InputManager::GetInstance()->PushKey(DIK_A)) {
		velocity_.x -= movementSpeed_;
	}
	if (InputManager::GetInstance()->PushKey(DIK_D)) {
		velocity_.x += movementSpeed_;
	}
	if (InputManager::GetInstance()->PushKey(DIK_W)) {
		velocity_.y -= movementSpeed_;
	}
	if (InputManager::GetInstance()->PushKey(DIK_S)) {
		velocity_.y += movementSpeed_;
	}
	if (InputManager::GetInstance()->TriggerKey(DIK_SPACE)) {
		Bullet* bullet = new Bullet();
		bullet->Initialize(position_);
		bullets_.push_back(bullet);
	}
	position_.x += velocity_.x;
	position_.y += velocity_.y;

	for (auto& bullet : bullets_) {
		bullet->Update();
	}

	bullets_.remove_if([](Bullet* bullet) {
		if (!bullet->GetIsActive()) {
			delete bullet;
			return true;
		}
		return false;
	});

}

void Player::Draw()
{
	for (auto& bullet : bullets_) {
		bullet->Draw();
	}
	Novice::DrawBox(int(position_.x - width_ / 2.5f), int(position_.y - height_ / 2.5f), int(width_), int(height_), 0.0f, WHITE, kFillModeSolid);
}
