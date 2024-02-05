#include "Player.h"
#include "Novice.h"
#include "MATH.h"

Player::~Player()
{
	for (PlayerBullet* bullet : playerbullets_)
	{
		delete bullet;
	}
}

void Player::Initialize(const char* keys, const char* preKeys)
{
	posiiton_ = { 500.0f,350.0f };

	radius_ = { 40.0f,40.0f };
	keys_ = keys;
	preKeys_ = preKeys;
	speed_ = 4.0f;
}

void Player::Update()
{
	if (keys_[DIK_D])
	{
		posiiton_.x += speed_;
	}
	else if (keys_[DIK_A])
	{
		posiiton_.x -= speed_;
	}
	if (keys_[DIK_S])
	{
		posiiton_.y += speed_;
	}
	else if (keys_[DIK_W])
	{
		posiiton_.y -= speed_;
	}

	Attack();
	for (PlayerBullet* bullet : playerbullets_)
	{
		bullet->Update(posiiton_);
	}

}

void Player::Draw()
{
	Novice::DrawBox((int)posiiton_.x, (int)posiiton_.y, (int)radius_.x, (int)radius_.y, 0.0f, WHITE, kFillModeSolid);

	for (PlayerBullet* bullet : playerbullets_)
	{
		bullet->Draw();
	}
}

void Player::Attack()
{
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE])
	{

		const float bulletspeed = 8.0f;
		PlayerBullet* newbullet = new PlayerBullet();
		newbullet->Initialize(bulletspeed, posiiton_, keys_, preKeys_);

		playerbullets_.push_back(newbullet);
	}
}

Vector2 Player::GetPosiiton()
{

	Vector2 position;

	position.x = posiiton_.x;
	position.y = posiiton_.y;
	return position;
}
