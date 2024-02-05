#include "Enemy.h"
#include"Novice.h"
#include"MATH.h"

void Enemy::Initialize()
{
	position_ = { 650.0f,150.0f };
	radius_ = { 40.0f,40.0f };
	speed_ = 3.0f;
}

void Enemy::Update()
{
	position_.x = position_.x += speed_;
	if (position_.x + radius_.x >= 1280 || position_.x <= 0)
	{
		speed_ = speed_ * -1;
	}

}

void Enemy::Draw()
{
	Novice::DrawBox((int)position_.x, (int)position_.y, (int)radius_.x, (int)radius_.y, 0.0f, BLACK, kFillModeSolid);

}

void Enemy::OnCollision()
{
	isActive_ = true;
}

Vector2 Enemy::GetRadius()
{
	Vector2 radius;

	radius.x = radius_.x;
	radius.y = radius_.y;
	return radius;

}

Vector2 Enemy::GetPosition()
{
	Vector2 postion;

	postion.x = position_.x;
	postion.y = position_.y;
	return postion;
}
