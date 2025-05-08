#include "ExceptionRolls.h"

ExceptionRolls::ExceptionRolls(const std::string& objExceptionString)
	: std::runtime_error(objExceptionString)
{
	std::cout<<"Exception cnstr called"<<std::endl;
}




