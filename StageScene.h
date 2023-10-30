#pragma once
#include "IScene.h"
#include <memory>
#include "Player.h"
#include "Enemy.h"
class StageScene : public IScene
{
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
private:
	std::unique_ptr<Player> player_;
	std::list<Enemy*> enemys_;
	int remaining_;

};

