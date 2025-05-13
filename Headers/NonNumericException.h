#pragma once
#include "ExceptionRolls.h"
class NonNumericException : public ExceptionRolls
{
public:
	explicit NonNumericException(const std::string& objExceptionString);
};

