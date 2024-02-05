#pragma once
#include "Vector2.h"
#include "PlayerBullet.h"
#include<memory>
#include<list>

class Player
{
	
public:

	~Player();

	void Initialize(const char* keys, const char* preKeys);

	void Update();

	void Draw();

    void Attack();

	const std::list<PlayerBullet*>& GetBullet() const { return playerbullets_; }

	Vector2 GetPosiiton();

private:


	Vector2 Position_;
	Vector2 Radius_;
	const char* keys_;
	const char* preKeys_;
	float Speed_;
	std::list<PlayerBullet*> playerbullets_;


};

