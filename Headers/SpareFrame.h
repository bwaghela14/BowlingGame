#pragma once
#include "IFrame.h"

#include "SpareFrameScoreCalculator.h"
class SpareFrame : public IFrame
{

public:

	SpareFrame(int roll1 = 0 ,int roll2 = 0);
	std::vector<int> getRolls()override;
	FrameType getFrameType()override;

	std::unique_ptr<IScoreCalculator>CreateScoreCalculator()override;

	~SpareFrame() = default;
private:

};

