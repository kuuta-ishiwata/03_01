#include "Enemy.h"
#include"Novice.h"

void Enemy::Initialize()
{
	Position_ = { 650.0f,150.0f };
	Radius = { 40.0f,40.0f };
	speed_ = 3.0f;
}

void Enemy::Update()
{
	Position_.x = Position_.x += speed_;
	if (Position_.x + Radius.x >= 1280 || Position_.x <= 0)
	{
		speed_ = speed_ * -1;
	}

}

void Enemy::Draw()
{
	Novice::DrawBox((int)Position_.x, (int)Position_.y, (int)Radius.x, (int)Radius.y, 0.0f, BLACK, kFillModeSolid);

}

void Enemy::OnCollision()
{
	isActive_ = true;
}

Vector2 Enemy::GetRadius()
{
	Vector2 radius;

	radius.x = Radius.x;
	radius.y = Radius.y;
	return radius;

}

Vector2 Enemy::GetPosition()
{
	Vector2 postion;

	postion.x = Position_.x;
	postion.y = Position_.y;
	return postion;
}
