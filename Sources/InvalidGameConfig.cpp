#include "InvalidGameConfig.h"

InvalidGameConfig::InvalidGameConfig(const std::string& objString)
	:ExceptionRolls(objString)
{
	std::cout << "InvalidGameConfig called" << std::endl;
}
