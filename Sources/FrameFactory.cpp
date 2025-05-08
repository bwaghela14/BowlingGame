#include "FrameFactory.h"
#include "InputValidator.h"

void FrameFactory::InsertFrame(std::vector<std::shared_ptr<IFrame>>& objFrames,const std::vector<std::vector<int>>& objRolls)
{
        size_t  iSize = objRolls.size();

            for (int i = 0;i < iSize;i++)
            {
                std::vector<int>objPins = objRolls.at(i);

                if (i == 9)
                {
                    objFrames.push_back(std::make_shared<TenthFrame>(objPins));
                }
                else if (objPins.size() == 1 && objPins.at(0) == 10)
                {

                    objFrames.push_back(std::make_shared<StrikeFrame>());
                }
                else if (objPins.size() == 2)
                {
                    if ((objPins.at(0) + objPins.at(1) == 10))
                    {
                        objFrames.push_back(std::make_shared<SpareFrame>(objPins[0], objPins[1]));
                    }
                    else
                    {
                        objFrames.push_back(std::make_shared<NormalFrame>(objPins[0], objPins[1]));
                    }
                }
                //else if (objPins.size() == 1)  //Newly added after gtest
                //{
                //    objFrames.push_back(std::make_shared<NormalFrame>(objPins[0], 0));
                //}

            }
        
}
