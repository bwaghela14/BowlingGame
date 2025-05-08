#include "UserInput.h"
#include "ConfigReader.h"


UserInput::UserInput()
{
	//std::cout << "User input cstr Called" << std::endl;
}


void UserInput::InputRolls(std::vector<std::vector<int>>& objRolls)
{
    //std::cout << "InputRolls Called" << std::endl;

    int i = 1;

    std::vector<int>objPins;
    int iMaxFrameValue;

    try
    {
        iMaxFrameValue = ConfigReader::GetInstance().GetMaxFrameValue();

        std::cout << "iMaxFrameValue=" << iMaxFrameValue << std::endl;
        InputValidator::ValidateFrameIndexReadFromConfig(iMaxFrameValue);
    }
    catch(const ExceptionRolls& ex)
    {
        std::cerr << "Frame value greater than 10 ,putting frame value to 10 manually"<< std::endl;
        iMaxFrameValue = 10;
    }

    while (i > 0 && i <= iMaxFrameValue)
    {
        int FirstRoll = 0, SecondRoll = 0, retryCount = 0, maxRetries = 5;;

        while (retryCount < maxRetries)
        {
            try
            {
                if (i <= 9)
                {

                    std::cout << "Enter first Roll Score" << std::endl;
                    std::cin >> FirstRoll;

                    InputValidator::ValidateInputRolls(FirstRoll);

                    objPins.emplace_back(FirstRoll);

                    if (FirstRoll != 10)
                    {
                        std::cout << "Enter 2nd Roll Score" << std::endl;
                        std::cin >> SecondRoll;

                        InputValidator::ValidateInputRolls(SecondRoll);

                        InputValidator::ValidateInputFrameSum(FirstRoll, SecondRoll);

                        //objValidator.ValidateRollSizeForFrame(objPins.size()); //To check if frame has 2 rolls proper

                        objPins.emplace_back(SecondRoll);
                    }

                    objRolls.emplace_back(objPins);
                    break;
                }
                else if (i == 10)
                {
                    std::cout << "Inside 10th Frame" << std::endl;
                    int thirdRoll = 0;

                    std::cout << "Enter first Roll Score" << std::endl;
                    std::cin >> FirstRoll;

                    InputValidator::ValidateInputRolls(SecondRoll);

                    std::cout << "Enter 2nd Roll Score" << std::endl;
                    std::cin >> SecondRoll;

                    InputValidator::ValidateInputRolls(SecondRoll);

                    //objValidator.ValidateInputFrameSum(FirstRoll,SecondRoll);

                    if (FirstRoll == 10 || (FirstRoll + SecondRoll == 10))
                    {
                        std::cout << "Enter 3rd Roll Score" << std::endl;
                        std::cin >> thirdRoll;

                        InputValidator::ValidateInputRolls(thirdRoll);

                    }
                    objRolls.insert(objRolls.end(), { FirstRoll,SecondRoll,thirdRoll });
                    break;
                }

            }

        catch (const ExceptionRolls& ex)
        {
            //std::cerr << ex.what() << std::endl;
            retryCount++;
            if (retryCount == maxRetries)
            {
                std::cerr << "Too many invalid attempts. Exiting the game.\n";
                throw;
            };

        }

        }
            objPins.clear();

        i++;
    }
    
    //std::cout << "All 10 frames rolls input taken" <<std::endl;
}
