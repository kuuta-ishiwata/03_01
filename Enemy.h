#pragma once
#include "Vector2.h"
class Enemy
{
public:

	void Initialize();

	void Update();

	void Draw();

	void OnCollision();

	Vector2 GetRadius();

	Vector2 GetPosition();

	bool IsActive() { return isActive_; }

private:

	Vector2 Position_;
	Vector2 Radius;
	float speed_;
	bool isActive_ = false;



};

