#pragma once
#include "IScoreCalculator.h"

class SpareFrameScoreCalculator : public IScoreCalculator
{
public:

	SpareFrameScoreCalculator();
	int CalculateScore(const std::vector<std::shared_ptr<IFrame>>& objFrames, int index)override;

private:

};

