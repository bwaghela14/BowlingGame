#pragma once
#include "ExceptionRolls.h"
class InvalidInputException : public ExceptionRolls
{
public:
	explicit InvalidInputException(const std::string& objExceptionString);
};

