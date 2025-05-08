#include "SpareFrameScoreCalculator.h"

SpareFrameScoreCalculator::SpareFrameScoreCalculator()
{
	//std::cout << __FUNCSIG__ << std::endl;
}

int SpareFrameScoreCalculator::CalculateScore(const std::vector<std::shared_ptr<IFrame>>& objFrames, int index)
{
    //std::cout << "Spare Frame" << std::endl;
    int iReturnSpareFrameSocre = 10;

    if ((index + 1) < 10)
    {
        //std::cout << "Spare bonus = " << objFrames[index + 1]->rolls[0] << std::endl;
        iReturnSpareFrameSocre += objFrames[index + 1]->rolls[0];
    }
    //std::cout << "iReturnSpareFrameSocre" << iReturnSpareFrameSocre << std::endl;
    return iReturnSpareFrameSocre;

}
