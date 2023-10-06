#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::Initialize(Model* model) {
	assert(model);

	//引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	//ワールド変換の初期化
	worldTransform_.Initialize();
}

void Player::Update() {
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Player::Draw(const ViewProjection& viewProjection) {

	//3Dモデルを描画
	model_->Draw(worldTransform_, viewProjection);

}
