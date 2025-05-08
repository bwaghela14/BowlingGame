#include "NormalFrame.h"

NormalFrame::NormalFrame(int roll1, int roll2)
{
	//std::cout << __FUNCSIG__ << std::endl;
	rolls = { roll1,roll2 };
}

std::vector<int> NormalFrame::getRolls()
{
	return std::vector<int>();
}

IFrame :: FrameType NormalFrame::getFrameType()
{
	return FrameType();
}

std::unique_ptr<IScoreCalculator> NormalFrame::CreateScoreCalculator()
{
	//std::cout << "NormalFrameScoreCalculator" << std::endl;
	return std::make_unique<NormalFrameScoreCalculator>();
}
