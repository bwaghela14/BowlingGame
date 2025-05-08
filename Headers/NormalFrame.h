#pragma once
#include "IFrame.h"
#include "NormalFrameScoreCalculator.h"
class NormalFrame : public IFrame
{
public:

	NormalFrame(int roll1 = 0 , int roll2 = 0);
	std::vector<int> getRolls()override;
	FrameType getFrameType()override;
	std::unique_ptr<IScoreCalculator> CreateScoreCalculator()override;

	~NormalFrame() = default;
private:
};

