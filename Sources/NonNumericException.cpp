#include "NonNumericException.h"

NonNumericException::NonNumericException(const std::string& objExceptionString)
	:ExceptionRolls(objExceptionString)
{
	std::cout << "NonNumericException called" << std::endl;
}
