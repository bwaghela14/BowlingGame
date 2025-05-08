#pragma once
#include "ExceptionRolls.h"
class InvalidFrameCalculationException : public ExceptionRolls
{
public:

	explicit InvalidFrameCalculationException(const std::string& objExceptionString);
private:

	
};

