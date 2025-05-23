#pragma once

//Input Validator ---->used for validatig user rolls
#include <iostream>
#include <vector>
#include "ExceptionRolls.h"
#include "InvalidFrameCalculationException.h"
#include "InvalidInputException.h"
#include "InvalidGameConfig.h"
#include "NonNumericException.h"

class InputValidator
{
public:

	static void ValidateInputRolls(int pin);	//Input inout
	static void ValidateInputFrameSum(int firstball, int secondball); //Invalid frame calculation
	static void ValidateFrameIndexReadFromConfig(int index); //Invalid game config
	static void ValidateActualFrameCreated(int FrameSize, int ConfigFrameSize); //Invalid input
	static int  ReadIntegerInput(const std::string& prompt,int retryNumericCount, int index);

	//static int ValidateSecondRoll(int pin);

	

	
private:

};

