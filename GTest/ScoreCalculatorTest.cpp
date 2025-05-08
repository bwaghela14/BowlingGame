#include "gtest/gtest.h"
#include "IFrame.h"
#include "IScoreCalculator.h"
#include "StrikeFrameScoreCalculator.h"
#include "TenthFrameScoreCalculator.h"
#include "NormalFrameScoreCalculator.h"
#include "SpareFrameScoreCalculator.h"
#include "NormalFrame.h"
#include "StrikeFrame.h"
#include "SpareFrame.h"
#include "TenthFrame.h"

class ScoreCalculatorTest : public ::testing::Test
{
protected:
    void SetUp() override {
        std::cout << std::endl;
    }

    void TearDown() override {
        std::cout << std::endl;
    }
};

template<typename T>
bool IsScoreCalculator(const std::unique_ptr<IScoreCalculator>& objScoreCalc) 
{
    return dynamic_cast<T*>(objScoreCalc.get()) != nullptr;
}

TEST_F(ScoreCalculatorTest, CreateScoreCalculatorCorrectFrame)
{
    std::vector<int>objVec{ 10,10,10 };
    std::vector<std::shared_ptr<IFrame>>frames = {

    std::make_shared<NormalFrame>(1,1),
    std::make_shared<NormalFrame>(2,2),
    std::make_shared<NormalFrame>(3,3),
    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(4,6),
    std::make_shared<SpareFrame>(7,3),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),

    std::make_shared<TenthFrame>(objVec),
    };

    std::vector<std::unique_ptr<IScoreCalculator>>objScoreVec;
    for (auto i : frames)
    {
        objScoreVec.emplace_back(i->CreateScoreCalculator());
    }

    EXPECT_TRUE(IsScoreCalculator<NormalFrameScoreCalculator>(objScoreVec[0])) << "Expected objScoreVec[0] to be NormalFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<NormalFrameScoreCalculator>(objScoreVec[1])) << "Expected objScoreVec[1] to be NormalFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<NormalFrameScoreCalculator>(objScoreVec[2])) << "Expected objScoreVec[2] to be NormalFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<SpareFrameScoreCalculator>(objScoreVec[3])) << "Expected objScoreVec[3] to be SpareFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<SpareFrameScoreCalculator>(objScoreVec[4])) << "Expected objScoreVec[4] to be SpareFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<SpareFrameScoreCalculator>(objScoreVec[5])) << "Expected objScoreVec[5] to be SpareFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<StrikeFrameScoreCalculator>(objScoreVec[6])) << "Expected objScoreVec[6] to be StrikeFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<StrikeFrameScoreCalculator>(objScoreVec[7])) << "Expected objScoreVec[7] to be StrikeFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<StrikeFrameScoreCalculator>(objScoreVec[8])) << "Expected objScoreVec[8] to be StrikeFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<TenthFrameScoreCalculator>(objScoreVec[9])) << "Expected objScoreVec[9] to be TenthFrameScoreCalculator, but it was not.";

}

TEST_F(ScoreCalculatorTest, CreateScoreCalculatorIncorrectFrame)
{
    std::cout << std::endl;
    std::vector<int>objVec{ 10,10,10 };
    std::vector<std::shared_ptr<IFrame>>frames = {

    std::make_shared<NormalFrame>(1,1),
    std::make_shared<NormalFrame>(2,2),
    std::make_shared<NormalFrame>(3,3),
    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(4,6),
    std::make_shared<SpareFrame>(7,3),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),

    std::make_shared<TenthFrame>(objVec),
    };

    std::vector<std::unique_ptr<IScoreCalculator>>objScoreVec;
    for (auto i : frames)
    {
        objScoreVec.emplace_back(i->CreateScoreCalculator());
    }

    EXPECT_TRUE(IsScoreCalculator<NormalFrameScoreCalculator>(objScoreVec[0])) << "Expected objScoreVec[0] to be NormalFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<NormalFrameScoreCalculator>(objScoreVec[1])) << "Expected objScoreVec[1] to be NormalFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<NormalFrameScoreCalculator>(objScoreVec[2])) << "Expected objScoreVec[2] to be NormalFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<SpareFrameScoreCalculator>(objScoreVec[3])) << "Expected objScoreVec[3] to be SpareFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<SpareFrameScoreCalculator>(objScoreVec[4])) << "Expected objScoreVec[4] to be SpareFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<SpareFrameScoreCalculator>(objScoreVec[5])) << "Expected objScoreVec[5] to be SpareFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<StrikeFrameScoreCalculator>(objScoreVec[6])) << "Expected objScoreVec[6] to be StrikeFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<StrikeFrameScoreCalculator>(objScoreVec[7])) << "Expected objScoreVec[7] to be StrikeFrameScoreCalculator, but it was not.";
    EXPECT_TRUE(IsScoreCalculator<SpareFrameScoreCalculator>(objScoreVec[8])) << "Expected objScoreVec[8] to be StrikeFrameScoreCalculator, but it was not.";       //Wrong frame got added here.
    EXPECT_TRUE(IsScoreCalculator<TenthFrameScoreCalculator>(objScoreVec[9])) << "Expected objScoreVec[9] to be TenthFrameScoreCalculator, but it was not.";

}

TEST_F(ScoreCalculatorTest, CalculateScore1)
{

    std::vector<int>objVec{ 10,10,10 };
    std::vector<std::shared_ptr<IFrame>>frames = {

    std::make_shared<NormalFrame>(1,1),
    std::make_shared<NormalFrame>(2,2),
    std::make_shared<NormalFrame>(3,3),
    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(4,6),
    std::make_shared<SpareFrame>(7,3),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),

    std::make_shared<TenthFrame>(objVec),
    };

    int total = 0;
    std::vector<std::unique_ptr<IScoreCalculator>>objScoreVec;

    for (size_t index = 0; index < frames.size(); ++index)
    {
        objScoreVec.emplace_back(frames[index]->CreateScoreCalculator());
        total += objScoreVec.at(index)->CalculateScore(frames, index);
    }

    EXPECT_EQ(total, 183); 

}

TEST_F(ScoreCalculatorTest, CalculateScore2)
{

    std::vector<int>objVec{ 5,5,5};
    std::vector<std::shared_ptr<IFrame>>frames = {

    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(5,5),
    std::make_shared<SpareFrame>(5,5),

    std::make_shared<TenthFrame>(objVec),
    };

    int total = 0;
    std::vector<std::unique_ptr<IScoreCalculator>>objScoreVec;

    for (size_t index = 0; index < frames.size(); ++index)
    {
        objScoreVec.emplace_back(frames[index]->CreateScoreCalculator());
        total += objScoreVec.at(index)->CalculateScore(frames, index);
    }

    EXPECT_EQ(total, 150); 

}

TEST_F(ScoreCalculatorTest, CalculateScore3)
{

    std::vector<int>objVec{ 10,10,10 };
    std::vector<std::shared_ptr<IFrame>>frames = {

    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),
    std::make_shared<StrikeFrame>(),

    std::make_shared<TenthFrame>(objVec),
    };

    int total = 0;
    std::vector<std::unique_ptr<IScoreCalculator>>objScoreVec;

    for (size_t index = 0; index < frames.size(); ++index)
    {
        objScoreVec.emplace_back(frames[index]->CreateScoreCalculator());
        total += objScoreVec.at(index)->CalculateScore(frames, index);
    }

    EXPECT_EQ(total, 300); 
    std::cout << std::endl;
}
