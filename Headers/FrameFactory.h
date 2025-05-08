#pragma once

#include "IFrame.h"
#include "StrikeFrame.h"
#include "NormalFrame.h"
#include "SpareFrame.h"
#include "TenthFrame.h"
class FrameFactory
{
public:
	static void InsertFrame(std::vector<std::shared_ptr<IFrame>>&objFrames,const std::vector<std::vector<int>>& objRolls);
private:

};

