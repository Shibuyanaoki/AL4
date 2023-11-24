#pragma once
#include "BaseCharacter.h"

class Enemy : public BaseCharacter{

/// <summary>
	/// ‰Šú‰»ˆ—
	/// </summary>
	virtual void Initialize(const std::vector<Model*>& models);

	/// <summary>
	/// XVˆ—
	/// </summary>
	virtual void Updata();

	/// <summary>
	/// •`‰æˆ—
	/// </summary>
	virtual void Draw(const ViewProjection& viewProjection);


};
