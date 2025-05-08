#include "gtest/gtest.h"
#include "IFrame.h"
#include "IScoreCalculator.h"
#include "InputValidator.h"
#include "FrameFactory.h"
#include "ConfigReader.h"

class BowlingGameIntegrationTest : public ::testing::Test
{
protected:
    void SetUp() override {
        std::cout << std::endl;
    }

    void TearDown() override {
        std::cout << std::endl;
    }
};



TEST_F(BowlingGameIntegrationTest, EndToEndFlow1)
{
    std::vector<std::vector<int>>inputRolls = {
        {10},       
        {5, 5},     
        {3, 4},     
        {10},       
        {2, 3},     
        {10},       
        {10},       
        {5, 2},     
        {4, 6},     
        {10, 10, 10} 
    };

    for (int i = 0;i < inputRolls.size();i++)
    {
        std::vector<int> objVec = inputRolls.at(i);

        for(int j=0;j<objVec.size();j++)
        {
            EXPECT_NO_THROW(InputValidator::ValidateInputRolls(objVec.at(j)));
        }

    }


    // Create frames
    std::vector<std::shared_ptr<IFrame>> objFrames;
    FrameFactory::InsertFrame(objFrames, inputRolls);

    // Calculate score

    int total = 0;
    for (int i = 0;i < objFrames.size();i++)
    {
        auto frame = objFrames.at(i)->CreateScoreCalculator();
        total += frame->CalculateScore(objFrames, i);
    }

    EXPECT_EQ(total, 159);

    std::cout << std::endl;
    
}

TEST_F(BowlingGameIntegrationTest, EndToEndFlow2)
{
    std::cout << std::endl;
    std::vector<std::vector<int>>inputRolls = {
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10, 10, 5}
    };

    for (int i = 0;i < inputRolls.size();i++)
    {
        std::vector<int> objVec = inputRolls.at(i);

        for (int j = 0;j < objVec.size();j++)
        {
            EXPECT_NO_THROW(InputValidator::ValidateInputRolls(objVec.at(j)));
        }

    }


    // Create frames
    std::vector<std::shared_ptr<IFrame>> objFrames;
    FrameFactory::InsertFrame(objFrames, inputRolls);

    // Calculate score

    int total = 0;
    for (int i = 0;i < objFrames.size();i++)
    {
        auto frame = objFrames.at(i)->CreateScoreCalculator();
        total += frame->CalculateScore(objFrames, i);
    }

    EXPECT_EQ(total, 295);

    std::cout << std::endl;

}


TEST_F(BowlingGameIntegrationTest, EndToEndFlow3)
{
    std::cout << std::endl;
    std::vector<std::vector<int>>inputRolls = {
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10, 5, 5}
    };

    for (int i = 0;i < inputRolls.size();i++)
    {
        std::vector<int> objVec = inputRolls.at(i);

        for (int j = 0;j < objVec.size();j++)
        {
            EXPECT_NO_THROW(InputValidator::ValidateInputRolls(objVec.at(j)));
        }

    }


    // Create frames
    std::vector<std::shared_ptr<IFrame>> objFrames;
    FrameFactory::InsertFrame(objFrames, inputRolls);

    // Calculate score

    int total = 0;
    for (int i = 0;i < objFrames.size();i++)
    {
        auto frame = objFrames.at(i)->CreateScoreCalculator();
        total += frame->CalculateScore(objFrames, i);
    }

    EXPECT_EQ(total, 285);

    std::cout << std::endl;

}

TEST_F(BowlingGameIntegrationTest, EndToEndFlow4)
{
    std::cout << std::endl;
    std::vector<std::vector<int>>inputRolls = {
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {10},
        {5, 5, 5}
    };

    for (int i = 0;i < inputRolls.size();i++)
    {
        std::vector<int> objVec = inputRolls.at(i);

        for (int j = 0;j < objVec.size();j++)
        {
            EXPECT_NO_THROW(InputValidator::ValidateInputRolls(objVec.at(j)));
        }

    }


    // Create frames
    std::vector<std::shared_ptr<IFrame>> objFrames;
    FrameFactory::InsertFrame(objFrames, inputRolls);

    // Calculate score

    int total = 0;
    for (int i = 0;i < objFrames.size();i++)
    {;
        auto frame = objFrames.at(i)->CreateScoreCalculator();
        total += frame->CalculateScore(objFrames, i);
    }

    EXPECT_EQ(total, 270);

    std::cout << std::endl;

}

TEST_F(BowlingGameIntegrationTest, EndToEndFlow5)
{
    std::cout << std::endl;
    std::vector<std::vector<int>>inputRolls = {
        {5,5},
        {5,5},
        {5,5},
        {5,5},
        {5,5},
        {5,5},
        {5,5},
        {5,5},
        {5,5},
        {5, 5, 5}
    };

    std::cout << "flow 5 size = "<<inputRolls.size() << std::endl;
    for (int i = 0;i < inputRolls.size();i++)
    {
        std::vector<int> objVec = inputRolls.at(i);

        for (int j = 0;j < objVec.size();j++)
        {
            EXPECT_NO_THROW(InputValidator::ValidateInputRolls(objVec.at(j)));
        }

    }


    // Create frames
    std::vector<std::shared_ptr<IFrame>> objFrames;
    FrameFactory::InsertFrame(objFrames, inputRolls);

    // Calculate score

    int total = 0;
    for (int i = 0;i < objFrames.size();i++)
    {
        //std::cout << "Before frame->CalculateSocre" << std::endl;
        auto frame = objFrames.at(i)->CreateScoreCalculator();
        total += frame->CalculateScore(objFrames, i);
        //std::cout << "After frame->CalculateSocre" << std::endl;
    }

    EXPECT_EQ(total, 160);

}

TEST_F(BowlingGameIntegrationTest, AllZero)
{
    std::vector<std::vector<int>> inputRolls(10, { 0, 0 });

    std::vector<std::shared_ptr<IFrame>> frames;
    FrameFactory::InsertFrame(frames, inputRolls);

    int total = 0;
    for (size_t i = 0; i < frames.size(); ++i)
        total += frames[i]->CreateScoreCalculator()->CalculateScore(frames, i);

    EXPECT_EQ(total, 0);

}

//Config Test simulation

TEST_F(BowlingGameIntegrationTest, ConfigChanged)
{
    ConfigReader& objConfigReader = ConfigReader::GetInstance();

    ConfigMap objConfig = objConfigReader.getConfigMap();

    objConfig.erase("MaxBowlingFrame");

    objConfigReader.SetMaxFrameValue();

    EXPECT_EQ(objConfigReader.GetMaxFrameValue(), 10);

    std::cout << std::endl;
}