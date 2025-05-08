#include "NormalFrameScoreCalculator.h"

NormalFrameScoreCalculator::NormalFrameScoreCalculator()
{
}

int NormalFrameScoreCalculator::CalculateScore(const std::vector<std::shared_ptr<IFrame>>& objFrames, int index)
{
    //std::cout << "Normal Frame" << std::endl;
    int iReturnNormalFrameSocre = 0;

    if (index < 10)
    {
        iReturnNormalFrameSocre = objFrames[index]->rolls[0] + objFrames[index]->rolls[1];
    }
    //std::cout << "iReturnNormalFrameSocre = " << iReturnNormalFrameSocre << std::endl;
    return iReturnNormalFrameSocre;
}
