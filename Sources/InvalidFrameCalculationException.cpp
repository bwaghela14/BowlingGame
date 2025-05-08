#include "InvalidFrameCalculationException.h"

InvalidFrameCalculationException::InvalidFrameCalculationException(const std::string& objExceptionString)
	:ExceptionRolls(objExceptionString)
{
	std::cout << "Invlaid Frame Calculation exception CAlled" << std::endl;
}
