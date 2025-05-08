#include "TenthFrameScoreCalculator.h"

TenthFrameScoreCalculator::TenthFrameScoreCalculator()
{
}

int TenthFrameScoreCalculator::CalculateScore(const std::vector<std::shared_ptr<IFrame>>& objFrames, int index)
{
    //std::cout << "10th Frame" << std::endl;
    int iReturnTenthFrameSocre = 0;


    iReturnTenthFrameSocre += objFrames[index]->rolls[0] + objFrames[index]->rolls[1];

    if (objFrames[index]->rolls.size() == 3)
    {
        iReturnTenthFrameSocre += objFrames[index]->rolls[2];
    }
       
    //std::cout << "iReturnTenthFrameSocre = " << iReturnTenthFrameSocre << std::endl;
    return iReturnTenthFrameSocre;
}
