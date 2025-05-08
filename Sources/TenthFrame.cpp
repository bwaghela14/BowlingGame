#include "TenthFrame.h"

TenthFrame::TenthFrame(std::vector<int>& objPins)
{
    //std::cout << __FUNCSIG__ << std::endl;
    rolls = objPins;
}

std::vector<int> TenthFrame::getRolls()
{
    return std::vector<int>();
}

IFrame::FrameType TenthFrame::getFrameType()
{
    return FrameType();
}

std::unique_ptr<IScoreCalculator> TenthFrame::CreateScoreCalculator()
{
    return std::make_unique<TenthFrameScoreCalculator>();
}
