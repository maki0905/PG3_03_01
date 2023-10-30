#include "StageScene.h"

void StageScene::Initialize()
{
	player_ = std::make_unique<Player>();
	player_->Initialize();

	for (int i = 0; i < 3; i++) {
		Enemy* enemy = new Enemy();
		Vector2 position = { 540.0f + (i * 100.0f) ,100.0f };
		enemy->Initialize(position);
		enemys_.push_back(enemy);
		remaining_++;
	}

}

void StageScene::Update()
{
	player_->Update();

	std::list < Bullet*> bullets = player_->GetBullets();
	for (auto& enemy : enemys_) {
		for (auto& bullet : bullets) {
			Vector2 subPos = { enemy->GetPosition().x - bullet->GetPosition().x, enemy->GetPosition().y - bullet->GetPosition().y };
			float distance = sqrtf((subPos.x * subPos.x) + (subPos.y * subPos.y));
			if (distance <= enemy->GetRadius() + bullet->GetRadius()) {
				enemy->OnCollision();
				bullet->OnCollision();
				remaining_--;
			}
		}
	}

	enemys_.remove_if([](Enemy* enemy) {
		if (!enemy->GetIsActive()) {
			delete enemy;
			return true;
		}
		return false;
		});

	

	if (remaining_ == 0) {
		sceneNo_ = CLEAR;
	}
}

void StageScene::Draw()
{
	player_->Draw();
	for (auto& enemy : enemys_) {
		enemy->Draw();
	}
}
