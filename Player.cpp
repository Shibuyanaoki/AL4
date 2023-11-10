#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::Initialize(Model* modelBody, Model* modelHead, Model* modelL_arm, Model* modelR_arm) {
	assert(modelBody);
	assert(modelHead);
	assert(modelL_arm);
	assert(modelR_arm);

	input_ = Input::GetInstance();

	// 引数として受け取ったデータをメンバ変数に記録する
	modelFighterBody_ = modelBody;
	modelFighterHead_ = modelHead;
	modelFighterL_arm_ = modelL_arm;
	modelFighterR_arm_ = modelR_arm;
	
	// ワールド変換の初期化
	worldTransform_.Initialize();
}

void Player::Update() {

	// ゲームパッドの状態を得る変数
	XINPUT_STATE joyState;

	// ゲームパッド状態取得、ゲームパッドが有効の場合if文が通る
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {

		// 速さ
		const float speed = 0.3f;

		// 移動量
		Vector3 move = {
		    (float)joyState.Gamepad.sThumbLX / SHRT_MAX * speed, // Lスティックの横成分
		    0.0f,
		    (float)joyState.Gamepad.sThumbLY / SHRT_MAX * speed, // Lスティックの縦成分
		};

		Matrix4x4 rotationXMatrix = MakeRotateXmatrix(viewProjection_->rotation_.x);
		Matrix4x4 rotationYMatrix = MakeRotateYmatrix(viewProjection_->rotation_.y);
		Matrix4x4 rotationZMatrix = MakeRotateZmatrix(viewProjection_->rotation_.z);
		Matrix4x4 rotationXYZMatrix =
		    Multiply(rotationXMatrix, Multiply(rotationYMatrix, rotationZMatrix));

		// 移動量に速さを反映
		move = Multiply(speed, Normalize(move));

		// 移動量に速さを反映(θ度の移動ベクトル)
		// rotation = (viewProjection_->rotation_.y);

		move = Transform(move, rotationXYZMatrix);

		if (move.y != 0 || move.z != 0) {
			worldTransform_.rotation_.y = std::atan2(move.z, move.x);
		}

		// 移動
		worldTransform_.translation_ = Add(worldTransform_.translation_, move);
	}

	// 行列を定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void Player::Draw(const ViewProjection& viewProjection) {

	// 3Dモデルを描画
	modelFighterBody_->Draw(worldTransform_, viewProjection);
	modelFighterHead_->Draw(worldTransform_, viewProjection);
	modelFighterL_arm_->Draw(worldTransform_, viewProjection);
	modelFighterR_arm_->Draw(worldTransform_, viewProjection);
}

Vector3 Player::GetWorldPosition() {
	// ワールド座標を入れる変数
	Vector3 worldPos;

	// ワールド行列の平行移動成分を取得(ワールド座標)
	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos;
}

const WorldTransform& Player::GetWorldTransform() {
	// TODO: return ステートメントをここに挿入します
	return worldTransform_;
}

void Player::InitializeFloatingGimmick() {

	floatingParameter_ = 0.0f;




}

void Player::UpdateFlotingGimmick() {

	//浮遊移動のサイクル<frame>
	const uint16_t period = 30;

	//1フレームでのパラメータ加算値
	const float step = 2.0f * 3.14 / period;

	//パラメータを1ステップ分加算
	floatingParameter_ += step;
	//2πを超えたらθに戻す

}
