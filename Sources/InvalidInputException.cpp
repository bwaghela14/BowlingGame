#include "InvalidInputException.h"

InvalidInputException::InvalidInputException(const std::string& objExceptionString)
	:ExceptionRolls(objExceptionString)
{
	std::cout << "InvalidInputException called" << std::endl;
}
