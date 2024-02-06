#include "Player.h"
#include "Novice.h"

Player::~Player()
{
	for (PlayerBullet* Bullet : playerbullets_)
	{
		delete Bullet;
	}
}

void Player::Initialize(const char* keys, const char* preKeys)
{
	Position_ = { 500.0f,350.0f };

	Radius_ = { 40.0f,40.0f };
	keys_ = keys;
	preKeys_ = preKeys;
	Speed_ = 4.0f;
}

void Player::Update()
{
	if (keys_[DIK_D])
	{
		Position_.x += Speed_;
	}
	else if (keys_[DIK_A])
	{
		Position_.x -= Speed_;
	}
	if (keys_[DIK_S])
	{
		Position_.y += Speed_;
	}
	else if (keys_[DIK_W])
	{
		Position_.y -= Speed_;
	}

	Attack();
	for (PlayerBullet* Bullet : playerbullets_)
	{
		Bullet->Update(Position_);
	}

}

void Player::Draw()
{
	Novice::DrawBox((int)Position_.x, (int)Position_.y, (int)Radius_.x, (int)Radius_.y, 0.0f, WHITE, kFillModeSolid);

	for (PlayerBullet* Bullet : playerbullets_)
	{
		Bullet->Draw();
	}
}

void Player::Attack()
{
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE])
	{

		const float BulletSpeed = 8.0f;
		PlayerBullet* newbullet = new PlayerBullet();
		newbullet->Initialize(BulletSpeed, Position_, keys_, preKeys_);

		playerbullets_.push_back(newbullet);
	}
}

Vector2 Player::GetPosiiton()
{

	Vector2 Position;

	Position.x = Position_.x;
	Position.y = Position_.y;
	return Position;
}
