#include "StrikeFrameScoreCalculator.h"

StrikeFrameScoreCalculator::StrikeFrameScoreCalculator()
{
}

int StrikeFrameScoreCalculator::CalculateScore(const std::vector<std::shared_ptr<IFrame>>& objFrames, int index)
{
    int iReturnStrikeFrameSocre = 10;

    //std::cout << "strike Frame" << std::endl;

    int nextRollsCounted = 0;

    for (int i = index + 1; i < objFrames.size() && nextRollsCounted < 2; ++i)
    {
        for (int pins : objFrames[i]->rolls)
        {
            iReturnStrikeFrameSocre += pins;
            ++nextRollsCounted;
            if (nextRollsCounted == 2)
                break;
        }
    }

    //std::cout << "iReturnStrikeFrameSocre" << iReturnStrikeFrameSocre << std::endl;
    return iReturnStrikeFrameSocre;
}
