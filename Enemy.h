#pragma once
#include "BaseCharacter.h"

class Enemy : public BaseCharacter{

/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize(const std::vector<Model*>& models);

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Updata();

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw(const ViewProjection& viewProjection);


};
