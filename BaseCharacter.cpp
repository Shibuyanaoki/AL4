﻿#include "BaseCharacter.h"

void BaseCharacter::Initialize(const std::vector<Model*>& models) {

	models_ = models;

	worldTransform_.Initialize();

	worldTransform_.UpdateMatrix();
}

void BaseCharacter::Updata() {}

void BaseCharacter::Draw(const ViewProjection& viewProjection) {
	for (Model* model : models_) {
		model->Draw(worldTransform_, viewProjection);
	}
}