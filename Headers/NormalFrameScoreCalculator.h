#pragma once
#include "IScoreCalculator.h"

class NormalFrameScoreCalculator : public IScoreCalculator
{
public:

	NormalFrameScoreCalculator();

	int CalculateScore(const std::vector<std::shared_ptr<IFrame>>& objFrames, int index)override;


private:

};

