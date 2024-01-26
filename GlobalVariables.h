#pragma once
#include "WorldTransform.h"

#include <iostream>
#include <map>
#include <string>
#include <variant>
class GlobalVariables {

	struct Item {
		// 項目の値
		std::variant<int32_t, float, Vector3> value;
	};

	struct Group {
		std::map<std::string, Item> items;
	};

public:
	static GlobalVariables* GetInstance();

	void CreateGroup(const std::string& groupName);

	// 値のセット(int)
	void SetValue(const std::string& groupName, const std::string& key, int32_t value);

	// 値のセット(float)
	void SetValue(const std::string& groupName, const std::string& key, float value);

	// 値のセット(Vector3)
	void SetValue(const std::string& groupName, const std::string& key, Vector3 value);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

private:
	GlobalVariables() = default;

	~GlobalVariables() = default;

	GlobalVariables(const GlobalVariables& obj) = delete;

	GlobalVariables& operator=(const GlobalVariables& obj) = delete;

	// 全データ
	std::map<std::string, Group> datas_;
};
