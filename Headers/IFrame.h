#pragma once


#include<vector>
#include<iostream>
#include<memory>

//#include "IScoreCalculator.h"
//#include "SpareFrameScoreCalculator.h"
//#include "StrikeFrameScoreCalculator.h"
//#include "NormalFrameScoreCalculator.h"
//#include "TenthFrameScoreCalculator.h"

class IScoreCalculator;		//Forward Delcare

//#define NORAMAL_FRAME									1
//#define SPARE_FRAME										2
//#define STRIKE_FRAME									3
//#define TENTH_FRAME										4


class IFrame
{
public:

	IFrame();
	std::vector<int>rolls;
	int iFrameType;

	enum FrameType {
		NORMAL,
		SPARE,
		STRIKE,
		LAST
	};

	virtual std::vector<int> getRolls() = 0;
	virtual FrameType getFrameType() = 0;

	virtual std::unique_ptr<IScoreCalculator> CreateScoreCalculator() = 0;

	virtual ~IFrame() = default;

private:

};


