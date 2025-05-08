#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <unordered_map>

//Sigleton ConfigReader Class

using ConfigMap = std::unordered_map<std::string, std::string>;

class ConfigReader
{
public:
	static ConfigReader& GetInstance();

	 bool RunTestorApp(const std::string& objKey);

	 std::string GetAppOrTestValue(const std::string& key);

	ConfigReader(const ConfigReader&) = delete;

	ConfigReader& operator = (const ConfigReader&) = delete;

	int GetMaxFrameValue()const;
	void SetMaxFrameValue();

	ConfigMap getConfigMap()const;

private:
	ConfigReader() = default;
	ConfigMap objConfigMap;
	int iMaxFrameValue = 0;
};

