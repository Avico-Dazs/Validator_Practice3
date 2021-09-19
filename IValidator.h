#pragma once
#include "ValidationResult.h"

class IValidator
{
public:
	virtual bool Eval(const char* sz , ValidationResult& result) = 0;
	virtual ~IValidator() {};
};
