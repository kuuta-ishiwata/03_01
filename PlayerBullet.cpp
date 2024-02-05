#include "PlayerBullet.h"
#include "Novice.h"


void PlayerBullet::Initialize(float speed, Vector2& position, const char* keys, const char* preKeys)
{
	Position_ = position;

	SavePosition_ = position;

	Radius_ = { 15.0f,15.0f };

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
		Position_.y = Position_.y - speed_;
	}
	if (Position_.y + Radius_.y <= -100)
	{
		Position_ = position;
		isShot_ = false;
	}

}

void PlayerBullet::Draw()
{
	if (isShot_ == true)
	{
		Novice::DrawBox((int)Position_.x, (int)Position_.y, (int)Radius_.x, (int)Radius_.y, 0.0f, RED, kFillModeSolid);
	}
}

void PlayerBullet::OnCollision(Vector2& position)
{
	Position_ = position;
	isShot_ = false;

}

Vector2 PlayerBullet::GetRadius()
{
	Vector2 radius;
	radius.x = Radius_.x;
	radius.y = Radius_.y;
	return radius;
}

Vector2 PlayerBullet::GetPosition()
{
	Vector2 pos;

	pos.x = Position_.x;
	pos.y = Position_.y;
	return pos;
}
