#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

class ExceptionRolls : public std::runtime_error
{
public:
	explicit ExceptionRolls(const std::string& objExceptionString);
private:

		
};

