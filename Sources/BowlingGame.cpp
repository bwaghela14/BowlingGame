// BowlingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <gtest/gtest.h>

#include "BowlingGameFacade.h"
#include "ConfigReader.h"

int main(int argc, char** argv) 
{
    auto& objConfig = ConfigReader::GetInstance();     //Getting ConfigReader singleton istnace

    if (objConfig.RunTestorApp("ModeOfGame"))  //If true then run gtest
    {
        std::cout << "Run test called" << std::endl;
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
    else 
    {
        BowlingGameFacade objFacade;
        objFacade.play();
        return 0;
    }
}
