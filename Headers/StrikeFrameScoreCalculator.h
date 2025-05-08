#pragma once
#include "IScoreCalculator.h"

class StrikeFrameScoreCalculator : public IScoreCalculator
{
public:

	StrikeFrameScoreCalculator();
	int CalculateScore(const std::vector<std::shared_ptr<IFrame>>& objFrames, int index)override;
private:

};

