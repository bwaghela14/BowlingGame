#pragma once

#include "IFrame.h"

class IScoreCalculator
{
public:
	IScoreCalculator();
	virtual int CalculateScore(const std::vector<std::shared_ptr<IFrame>>&objFrames,int index) = 0;
	virtual ~IScoreCalculator() = default;
private:

};

