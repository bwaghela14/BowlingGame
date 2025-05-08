#pragma once
#include "ExceptionRolls.h"
class InvalidGameConfig : public ExceptionRolls
{
public:

	explicit InvalidGameConfig(const std::string& objString);
private:

};

