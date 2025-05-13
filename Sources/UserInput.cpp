#include "UserInput.h"
#include "ConfigReader.h"
#include "NonNumericException.h"

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
    catch (const ExceptionRolls& ex)
    {
        std::cerr << "Frame value greater than 10 ,putting frame value to 10 manually" << std::endl;
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
                    FirstRoll = InputValidator::ReadIntegerInput("Enter first Roll Score for Frame Number", 0,i);

                    InputValidator::ValidateInputRolls(FirstRoll);

                    objPins.emplace_back(FirstRoll);

                    if (FirstRoll != 10)
                    {
                        while (retryCount < maxRetries) 
                        {
                            try 
                            {
                                SecondRoll = InputValidator::ReadIntegerInput("Enter 2nd Roll Score for Frame Number", 0,i);

                                InputValidator::ValidateInputRolls(SecondRoll);             
                                InputValidator::ValidateInputFrameSum(FirstRoll, SecondRoll); 
                                objPins.emplace_back(SecondRoll);
                                break; // Valid input, exit loop
                            }
                            catch (const NonNumericException& ex)
                            {
                                std::cerr << "Too many invalid attempts for non numeric input. Exiting...\n";
                                throw std::runtime_error("Failed to get valid nin numberic input after multiple retries.");
                            }
                            catch (const InvalidInputException& e)
                            {
                                std::cerr << "Invalid roll value: " << e.what() << std::endl;
                                retryCount++;
                            }
                            catch (const InvalidFrameCalculationException& e) 
                            {
                                std::cerr << "Invalid frame score: " << e.what() << std::endl;
                                retryCount++;
                            }
                            catch (const std::exception& e) 
                            {
                                std::cerr << "Unexpected error: " << e.what() << std::endl;
                                retryCount++;
                            }

                            if (retryCount >= maxRetries)
                            {
                                std::cerr << "Too many invalid attempts. Exiting...\n";
                                throw std::runtime_error("Failed to get valid 2nd roll input after multiple retries.");
                            }
                        }

                    }

                    objRolls.emplace_back(objPins);
                    break;
                }
                else if (i == 10)
                {
                    //std::cout << "Inside 10th Frame" << std::endl;
                    int thirdRoll = 0;

                    FirstRoll = InputValidator::ReadIntegerInput("Enter first Roll Score for Frame Number", 0,i);

                    InputValidator::ValidateInputRolls(FirstRoll);

                    while (retryCount < maxRetries)
                    {
                        try
                        {
                            SecondRoll = InputValidator::ReadIntegerInput("Enter 2nd Roll Score for Frame Number", 0,i);

                            InputValidator::ValidateInputRolls(SecondRoll);             
                            
                            if (FirstRoll!=10)
                            {
                                InputValidator::ValidateInputFrameSum(FirstRoll, SecondRoll); 
                            }
                            
                            break; // Valid input, exit loop
                        }
                        catch (const NonNumericException& ex)
                        {
                            std::cerr << "Too many invalid attempts for non numeric input. Exiting...\n";
                            throw std::runtime_error("Failed to get valid nin numberic input after multiple retries.");
                        }
                        catch (const InvalidInputException& e)
                        {
                            std::cerr << "Invalid roll value: " << e.what() << std::endl;
                            retryCount++;
                        }
                        catch (const InvalidFrameCalculationException& e)
                        {
                            std::cerr << "Invalid frame score: " << e.what() << std::endl;
                            retryCount++;
                        }
                        catch (const std::exception& e)
                        {
                            std::cerr << "Unexpected error: " << e.what() << std::endl;
                            retryCount++;
                        }

                        if (retryCount >= maxRetries)
                        {
                            std::cerr << "Too many invalid attempts. Exiting...\n";
                            throw std::runtime_error("Failed to get valid 2nd roll input after multiple retries.");
                        }
                    }


                    if (FirstRoll == 10 || (FirstRoll + SecondRoll == 10))
                    {
                        thirdRoll = InputValidator::ReadIntegerInput("Enter 3rd Roll Score for Frame Number", 0,i);

                        InputValidator::ValidateInputRolls(thirdRoll);

                    }
                    objRolls.insert(objRolls.end(), { FirstRoll,SecondRoll,thirdRoll });
                    break;
                }

            }
            catch (const NonNumericException& ex)
            {
                std::cerr << "Too many invalid attempts for non numeric input. Exiting...\n";
                throw std::runtime_error("Failed to get valid nin numberic input after multiple retries.");
            }
            catch (const ExceptionRolls& ex)
            {
                //std::cerr << ex.what() << std::endl;
                retryCount++;
                if (retryCount == maxRetries)
                {
                    std::cerr << "Too many invalid attempts. Exiting the game.\n";
                    throw;
                }

            }


        }
        objPins.clear();
        retryCount = 0;
        i++;
    }

    //std::cout << "All 10 frames rolls input taken" <<std::endl;
}