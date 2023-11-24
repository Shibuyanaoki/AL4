#pragma once
#include "BaseCharacter.h"
#include "Input.h"
#include "Model.h"
#include "WorldTransform.h"

#include <cassert>
class Player : public BaseCharacter {
public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(const std::vector<Model*>& models) override;

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Updata() override;

	

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(const ViewProjection& viewProjection) override;

	/// <summary>
	///  ワールド座標を取得
	/// </summary>
	/// <returns></returns>
	Vector3 GetWorldPosition();
	const WorldTransform& GetWorldTransform();

	void SetViewProjection(const ViewProjection* viewProjection) {
		viewProjection_ = viewProjection;
	}

	/// <summary>
	/// 浮遊ギミック初期化
	/// </summary>
	void InitializeFloatingGimmick();

	/// <summary>
	/// 浮遊ギミック更新
	/// </summary>
	void UpdateFlotingGimmick();

	void UpdataArmAnimation();

	void SetParent(const WorldTransform* parent) { worldTransform_.parent_ = parent; }

private:
	Input* input_ = nullptr;

	// ワールド変換データ
	WorldTransform worldTransform_;

	enum PlayerNum {
		kModeIndexBody,
		kModeIndexHead,
		kModeIndexL_arm,
		kModeIndexR_arm,
	};

	WorldTransform worldTransformBody_;
	WorldTransform worldTransformHead_;
	WorldTransform worldTransformL_arm_;
	WorldTransform worldTransformR_arm_;

	// 浮遊ギミックの媒介変数
	float floatingParameter_ = 0.0f;

	// カメラのビュープロジェクション
	const ViewProjection* viewProjection_ = nullptr;
};
