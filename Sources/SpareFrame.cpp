#include "SpareFrame.h"

SpareFrame::SpareFrame(int roll1, int roll2)
{
	//std::cout << __FUNCSIG__ << std::endl;
	rolls = {roll1, roll2};

}

std::vector<int> SpareFrame::getRolls()
{
	return std::vector<int>();
}

IFrame::FrameType SpareFrame::getFrameType()
{
	return FrameType();
}

std::unique_ptr<IScoreCalculator> SpareFrame::CreateScoreCalculator()
{
	return std::make_unique<SpareFrameScoreCalculator>();
}
