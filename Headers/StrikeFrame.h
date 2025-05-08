#pragma once
#include "IFrame.h"
#include "StrikeFrameScoreCalculator.h"
class StrikeFrame : public IFrame
{
public:

	StrikeFrame();
	std::vector<int> getRolls()override;
	FrameType getFrameType()override;
	std::unique_ptr<IScoreCalculator> CreateScoreCalculator()override;

	~StrikeFrame() = default;
private:

};

