#pragma once
#include "BaseCharacter.h"

class Enemy : public BaseCharacter{

/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize(const std::vector<Model*>& models);

	/// <summary>
	/// �X�V����
	/// </summary>
	virtual void Updata();

	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw(const ViewProjection& viewProjection);


};
