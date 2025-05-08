#include "StrikeFrame.h"

StrikeFrame::StrikeFrame()
{
    //std::cout << __FUNCSIG__ << std::endl;
    rolls = { 10 };
}

std::vector<int> StrikeFrame::getRolls()
{
    return std::vector<int>();
}

IFrame::FrameType StrikeFrame::getFrameType()
{
    return FrameType();
}

std::unique_ptr<IScoreCalculator> StrikeFrame::CreateScoreCalculator()
{
    return std::make_unique<StrikeFrameScoreCalculator>();
}
