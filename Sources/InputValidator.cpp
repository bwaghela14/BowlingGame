#include "InputValidator.h"

#define MAX_BOWLING_FRAME                           10

void InputValidator::ValidateInputRolls(int pin)
{
	if (pin < 0 || pin > 10)
		throw InvalidInputException("Pins cannot be less than 0 or greater than 10");
}

void InputValidator::ValidateInputFrameSum(int firstball, int secondball)
{
	if ((firstball + secondball) > 10)
		throw InvalidFrameCalculationException("Sum of 2 pins cannot be greter than 10 you have enter" + std::to_string(firstball + secondball));
}

void InputValidator::ValidateFrameIndexReadFromConfig(int index)
{
    if (index < 0 || index > MAX_BOWLING_FRAME)
    {
		throw InvalidGameConfig("Frames cannot go beyond minimum 0 or max 10 index");
    }

}

void InputValidator::ValidateActualFrameCreated(int FrameSize,int ConfigFrameSize)
{
	if (FrameSize!= ConfigFrameSize)
	{
		throw InvalidGameConfig("Frames created is not equal to configured frame size");
	}
}

