#pragma once
#include <string>
#include <format>
#include <Windows.h>

// ログ出力
namespace Logger {

	void Log(const std::string& message);
	void Log(const std::wstring& message);
	void Log(std::ostream& os, const std::string& message);
};
//class Logger
//{
//public:
//private:
//};

