#pragma once
#include <string>

class ValidationResult
{
// Attributes
public:
	int id;
	char message[256];
// Implements
public:
	void SetMessage(std::string str)
	{
		memset(message, 0, 256);
		strcpy_s(message ,256, str.c_str());
	}
};

