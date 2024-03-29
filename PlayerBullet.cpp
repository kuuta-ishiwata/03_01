﻿#include "PlayerBullet.h"
#include "Novice.h"


void PlayerBullet::Initialize(float speed, Vector2& position, const char* keys, const char* preKeys)
{
	position_ = position;

	saveposition_ = position;

	radius_ = { 15.0f,15.0f };

	keys_ = keys;

	preKeys_ = preKeys;

	speed_ = speed;

}

void PlayerBullet::Update(Vector2& position)
{
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE])
	{
		isShot_ = true;
	}
	if (isShot_ == true)
	{
		position_.y = position_.y - speed_;
	}
	if (position_.y + radius_.y <= -100)
	{
		position_ = position;
		isShot_ = false;
	}

}

void PlayerBullet::Draw()
{
	if (isShot_ == true)
	{
		Novice::DrawBox((int)position_.x, (int)position_.y, (int)radius_.x, (int)radius_.y, 0.0f, RED, kFillModeSolid);
	}
}

void PlayerBullet::OnCollision(Vector2& position)
{
	position_ = position;
	isShot_ = false;

}

Vector2 PlayerBullet::GetRadius()
{
	Vector2 radius;
	radius.x = radius_.x;
	radius.y = radius_.y;
	return radius;
}

Vector2 PlayerBullet::GetPosition()
{
	Vector2 pos;

	pos.x = position_.x;
	pos.y = position_.y;
	return pos;
}
