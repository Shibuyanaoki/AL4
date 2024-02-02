﻿#include "TitleScene.h"
void TitleScene::Initialize() {

	worldTransform_.Initialize();
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	// bgmHandle_ = audio_->LoadWave("BGM/TitleBGM.mp3");
	isBGM_ = false;
	// buttonSound_ = audio_->LoadWave("BGM/Button1.mp3");

	position_ = {640, 280};

	// 背景のスプライト
	titleTexHandle_ = TextureManager::Load("title.png");
	titleSprite_ =
	    Sprite::Create(titleTexHandle_, {640, 360}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.5f, 0.5f});

	uint32_t titleLettrTexHandle_ = TextureManager::Load("titleLetter.png");
	titleLetterSprite_ =
	    Sprite::Create(titleLettrTexHandle_, position_, {1.0f, 1.0f, 1.0f, 1.0f}, {0.5f, 0.5f});

	uint32_t fadeTexHandle = TextureManager::Load("fade.png");
	fadeSprite_ = Sprite::Create(fadeTexHandle, {0, 0});

	motionFlag_ = true;
}

void TitleScene::Update() {

	if (motionFlag_ == true) {
		if (position_.x<=0&&position_.y)
		position_


	}

	fadeColor_.w -= 0.005f;
	fadeSprite_->SetColor(fadeColor_);

	// ゲームパッドの状態を得る変数
	XINPUT_STATE joyState;
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		if (joyState.Gamepad.wButtons == XINPUT_GAMEPAD_A) {
			Sleep(1 * 300);
			isSceneEnd = true;
			// audio_->PlayWave(buttonSound_);
		}
	}
}

void TitleScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	titleSprite_->Draw();
	titleLetterSprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	fadeSprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void TitleScene::Reset() {
	audio_->StopWave(playBGM_);
	isBGM_ = false;
	isSceneEnd = false;
}
