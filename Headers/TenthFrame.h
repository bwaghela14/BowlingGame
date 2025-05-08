#pragma once

#include "IFrame.h"
#include "TenthFrameScoreCalculator.h"
class TenthFrame : public IFrame
{
public:

	TenthFrame(std::vector<int>&objPins);
	std::vector<int> getRolls()override;
	FrameType getFrameType()override;
	std::unique_ptr<IScoreCalculator> CreateScoreCalculator()override;

	~TenthFrame() = default;
private:
};

