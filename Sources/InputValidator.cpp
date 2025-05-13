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

int InputValidator::ReadIntegerInput(const std::string& prompt,int retryNonNumericCount,int index)
{
    int value;

    while (retryNonNumericCount < 5)
    {
        std::cout << prompt<<" "<<index<<" : ";
        std::cin >> value;

        if (std::cin.fail()) 
        {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            retryNonNumericCount++;
            std::cout << "Invalid input. Please enter a number only.\n";
        }
        else 
        {
            return value;
        }
    }
    if (retryNonNumericCount == 5)
    {
        throw NonNumericException("Too many invalid attempts for non numeric input. Exiting the game.\n");
    }
}

//int InputValidator::ValidateSecondRoll(int pin)
//{
//
//}
