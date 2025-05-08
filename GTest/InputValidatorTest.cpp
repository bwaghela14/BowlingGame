#include "gtest/gtest.h"
#include "InputValidator.h"  


class InputValidatorTest : public ::testing::Test
{
protected:
    void SetUp() override {
        std::cout << std::endl;
    }

    void TearDown() override {
        std::cout << std::endl;
    }
};

   TEST_F(InputValidatorTest, InvalidRollThrowsNegative)
   {
       try 
       {

           // This should throw because -1 is invalid
           InputValidator::ValidateInputRolls(-1);

           // If no exception is thrown, test should fail
           FAIL() << "Expected InvalidInputException to be thrown";
       }
       catch (const InvalidInputException& ex) {
           // Validate the exception message
           EXPECT_STREQ("Pins cannot be less than 0 or greater than 10", ex.what());
       }
       catch (...) {
           // Catch any other exception and fail
           FAIL() << "Expected InvalidInputException, but caught a different exception";
       }
   }

   TEST_F(InputValidatorTest, InvalidRollThrowsGreatorThan10)
   {
       try
       {
           InputValidator::ValidateInputRolls(11);

           FAIL() << "Expected InvalidInputExce ption to be thrown";
       }
       catch (const InvalidInputException &ex)
       {
           EXPECT_STREQ("Pins cannot be less than 0 or greater than 10", ex.what());
       }
       catch (...) {

           FAIL() << "Expected InvalidInputException, but caught a different exception";
       }
   }

   TEST_F(InputValidatorTest, ValidRollNoThrow)
   {
       try
       {
           InputValidator::ValidateInputRolls(5);

           FAIL() << "Expected InvalidInputException to be thrown";
       }
       catch (const InvalidInputException& ex)
       {
           EXPECT_STREQ("Pins cannot be less than 0 or greater than 10", ex.what());
       }
       catch (...) {
           FAIL() << "Expected InvalidInputException, but caught a different exception";
       }
   }

   TEST_F(InputValidatorTest, InValidPinsGreaterThan10SumThrow)
   {
       try
       {
           InputValidator::ValidateInputFrameSum(5,10);

           FAIL() << "Expected InvalidFrameCalculationException to be thrown";
       }
       catch (const InvalidFrameCalculationException& ex)
       {
           
           std::string objString = "Sum of 2 pins cannot be greter than 10 you have enter" + std::to_string(5 + 10);
           EXPECT_STREQ(objString.c_str(), ex.what());
       }
       catch (...) {
           FAIL() << "Expected InvalidFrameCalculationException, but caught a different exception";
       }
   }

   TEST_F(InputValidatorTest, ValidPinsLessThan10SumNoThrow)
   {
       try
       {
           InputValidator::ValidateInputFrameSum(5,5);

           FAIL() << "Expected InvalidFrameCalculationException to be thrown";
       }
       catch (const InvalidFrameCalculationException& ex)
       {
           std::string objString = "Sum of 2 pins cannot be greter than 10 you have enter" + std::to_string(5 + 10);
           EXPECT_STREQ(objString.c_str(), ex.what());
       }
       catch (...) {
           FAIL() << "Expected InvalidFrameCalculationException, but caught a different exception";
       }

   }

   
   TEST_F(InputValidatorTest, InvalidGameConfigThrows)
   {
       try
       {
           InputValidator::ValidateFrameIndexReadFromConfig(11);

           FAIL() << "Expected InvalidGameConfig to be thrown";
       }
       catch (const InvalidGameConfig& ex)
       {
           EXPECT_STREQ("Frames cannot go beyond minimum 0 or max 10 index", ex.what());
       }
       catch (...) {
           FAIL() << "Expected InvalidGameConfig, but caught a different exception";
       }
   }

   TEST_F(InputValidatorTest, ValidGameConfigNoThrows)
   {
       try
       {
           InputValidator::ValidateFrameIndexReadFromConfig(10);

           FAIL() << "Expected InvalidGameConfig to be thrown";
       }
       catch (const InvalidGameConfig& ex)
       {
           EXPECT_STREQ("Frames cannot go beyond minimum 0 or max 10 index", ex.what());
       }
       catch (...) {
           FAIL() << "Expected InvalidGameConfig, but caught a different exception";
       }

       std::cout << std::endl;
   }
