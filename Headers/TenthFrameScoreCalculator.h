#pragma once
#include "IScoreCalculator.h"

class TenthFrameScoreCalculator : public IScoreCalculator
{
public:
	TenthFrameScoreCalculator();
	int CalculateScore(const std::vector<std::shared_ptr<IFrame>>& objFrames, int index)override;
private:

};

