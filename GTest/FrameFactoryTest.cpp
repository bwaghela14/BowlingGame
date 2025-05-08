#include "gtest/gtest.h"
#include "FrameFactory.h"
#include "IFrame.h"
#include "StrikeFrame.h"
#include "TenthFrame.h"
#include "NormalFrame.h"
#include "SpareFrame.h"
#include "InvalidGameConfig.h"
#include "ConfigReader.h"
#include "InputValidator.h"


class FrameFactoryTest : public ::testing::Test 
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
bool IsFrameType(const std::shared_ptr<IFrame> &frame) {
    return std::dynamic_pointer_cast<T>(frame) != nullptr;
}

TEST_F(FrameFactoryTest, InsertFrameCorrectFrameTypes)
{
    std::vector<std::shared_ptr<IFrame>>frames;

    std::vector<std::vector<int>> inputRolls = {
        {10},          // Strike
        {5, 5},        // Spare
        {10},          //Strike 
        {4, 4},        // Normal
        {6, 4},        // Spare
        {10},          // Strike
        {2, 2},        // Normal
        {3, 3},        // Normal
        {3, 7},        // spare
        {10, 10, 10}   // Tenth frame
    };

    FrameFactory::InsertFrame(frames, inputRolls);


    EXPECT_TRUE(IsFrameType<StrikeFrame>(frames[0])) << "Expected frame[0] to be StrikeFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<SpareFrame>(frames[1])) << "Expected frame[1] to be SpareFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<StrikeFrame>(frames[2])) << "Expected frame[2] to be StrikeFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<NormalFrame>(frames[3])) << "Expected frame[3] to be NormalFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<SpareFrame>(frames[4])) << "Expected frame[4] to be SpareFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<StrikeFrame>(frames[5])) << "Expected frame[5] to be StrikeFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<NormalFrame>(frames[6])) << "Expected frame[6] to be NormalFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<NormalFrame>(frames[7])) << "Expected frame[7] to be NormalFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<SpareFrame>(frames[8])) << "Expected frame[8] to be SpareFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<TenthFrame>(frames[9])) << "Expected frame[9] to be TenthFrame, but it was not.";
    
    std::cout << std::endl;
}

TEST_F(FrameFactoryTest, InsertFrameIncorrectFrameTypes)
{
    std::vector<std::shared_ptr<IFrame>>frames;

    std::vector<std::vector<int>> inputRolls = {
        {10},          // Strike
        {5, 5},        // Spare
        {10},          //Strike 
        {4, 4},        // Normal
        {6, 4},        // Spare
        {10},          // Strike
        {2, 2},        // Normal
        {3, 3},        // Normal
        {3, 7},        // spare
        {10, 10, 10}   // Tenth frame
    };

    FrameFactory::InsertFrame(frames, inputRolls);


    EXPECT_TRUE(IsFrameType<StrikeFrame>(frames[0])) << "Expected frame[0] to be StrikeFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<SpareFrame>(frames[1])) << "Expected frame[1] to be SpareFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<StrikeFrame>(frames[2])) << "Expected frame[2] to be StrikeFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<NormalFrame>(frames[3])) << "Expected frame[3] to be NormalFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<SpareFrame>(frames[4])) << "Expected frame[4] to be SpareFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<StrikeFrame>(frames[5])) << "Expected frame[5] to be StrikeFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<NormalFrame>(frames[6])) << "Expected frame[6] to be NormalFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<NormalFrame>(frames[7])) << "Expected frame[7] to be NormalFrame, but it was not.";
    EXPECT_TRUE(IsFrameType<StrikeFrame>(frames[8])) << "Expected frame[8] to be SpareFrame, but it was not.";        //Wrong frame got added here.
    EXPECT_TRUE(IsFrameType<TenthFrame>(frames[9])) << "Expected frame[9] to be TenthFrame, but it was not.";

}


TEST_F(FrameFactoryTest, FramesCreatedAndConfigValueSameNoThrow)
{
    std::vector<std::shared_ptr<IFrame>>frames;

    std::vector<std::vector<int>> inputRolls = {
        {10},          // Strike
        {5, 5},        // Spare
        {10},          //Strike 
        {4, 4},        // Normal
        {6, 4},        // Spare
        {10},          // Strike
        {2, 2},        // Normal
        {3, 3},        // Normal
        {3, 7},        // spare
        {10, 10, 10}   // Tenth frame
    };

    FrameFactory::InsertFrame(frames, inputRolls);

    try
    {
        InputValidator::ValidateActualFrameCreated(frames.size(), ConfigReader::GetInstance().GetMaxFrameValue());

        FAIL() << "Expected InvalidGameConfig to be thrown";
    }
    catch (const InvalidGameConfig& ex)
    {
        EXPECT_STREQ("Frames created is not equal to configured frame size", ex.what());
    }
    catch (...) {
        FAIL() << "Expected InvalidGameConfig, but caught a different exception";
    }

}

TEST_F(FrameFactoryTest, FramesCreatedAndConfigValueNotSameThrows)
{
    std::vector<std::shared_ptr<IFrame>>frames;

    std::vector<std::vector<int>> inputRolls = {
        {10},          // Strike
        {5, 5},        // Spare
        {10},          //Strike 
        {4, 4},        // Normal
        {6, 4},        // Spare
        {10},          // Strike
        {2, 2},        // Normal
        {3, 3},        // Normal
        {3, 7},        // spare
    };

    FrameFactory::InsertFrame(frames, inputRolls);

    try
    {
        InputValidator::ValidateActualFrameCreated(frames.size(), ConfigReader::GetInstance().GetMaxFrameValue());

        FAIL() << "Expected InvalidGameConfig to be thrown";
    }
    catch (const InvalidGameConfig& ex)
    {
        EXPECT_STREQ("Frames created is not equal to configured frame size", ex.what());
    }
    catch (...) {
        FAIL() << "Expected InvalidGameConfig, but caught a different exception";
    }

    std::cout << std::endl;
}