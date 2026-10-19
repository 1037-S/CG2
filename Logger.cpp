#include "Logger.h"

void Logger::Log(const std::string& message)
{
	OutputDebugStringA(message.c_str());

}
void Logger::Log(const std::wstring& message)
{
	Log(ConvertString(message));
}

void Logger::Log(std::ostream& os, const std::string& message)
{
	os << message << std::endl;
	OutputDebugStringA(message.c_str());
}
