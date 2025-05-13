#include "BowlingGameFacade.h"
#include "InvalidGameConfig.h"
#include "ConfigReader.h"

BowlingGameFacade::BowlingGameFacade()
{
	//std::cout << "Bowling Facade Called" << std::endl;
}

void BowlingGameFacade::play()
{
	std::cout << "BowlingGameFacade Play called" << std::endl;

	std::vector<std::vector<int>>objRolls;

	int run = 0,GameNumber = 0;

	do
	{
		GameNumber++;
		std::cout << "***************LOADING GAME NUMBER    " << GameNumber <<" ****************" <<std::endl;
	//Taking input
	UserInput objInput;
	objInput.InputRolls(objRolls);


	//Inserting frame
	std::vector<std::shared_ptr<IFrame>>objFrames;

	try
	{
		FrameFactory::InsertFrame(objFrames, objRolls);
		InputValidator::ValidateActualFrameCreated(objFrames.size(), ConfigReader::GetInstance().GetMaxFrameValue());
	}
	catch (const InvalidGameConfig& ex)
	{
		std::cerr << "Wrong number of frame created wrt Config frame. Exiting the game.\n";
		throw;
	}

	std::cout << "Frame size = " << objFrames.size() << std::endl;


	//Calculate score
	int total = 0;
	for (int i = 0;i < objFrames.size();i++)
	{
		//std::cout << "Before frame->CalculateSocre" << std::endl;
		auto frame = objFrames.at(i)->CreateScoreCalculator();
		total+= frame->CalculateScore(objFrames, i);
		//std::cout << "After frame->CalculateSocre" << std::endl;
	}

	std::cout << "Total score is = " << total << std::endl;

	std::cout << "\nEnter non zero number(Positive) to continue calculate score for 10 frames/1 Game" << std::endl;
	std::cin >> run;

	if (std::cin.fail()) {
		std::cout << "Invalid input. Exiting the game.\n";
		break;
	}

	objFrames.clear();
	objRolls.clear();

	} while (run > 0);

#if 0
	for (auto pins : objRolls)
	{
		if (pins.size() ==1)
		{
			//std::cout << "size =1 " << pins.size() << std::endl;
			std::cout << pins[0]<<std::endl;
		}
		else if(pins.size() == 2)
		{
			//std::cout << "size =2 " << pins.size() << std::endl;
			std::cout << pins[0] <<"\t" <<pins[1]<< std::endl;
		}
		else if (pins.size() == 3)
		{
			//std::cout << "size =3" << pins.size() << std::endl;
			std::cout << pins[0] << "\t" << pins[1] <<"\t" << pins[2]<<std::endl;
		}
	}
#endif

#if 0
	for (auto pins : objFrames)
	{
		//std::cout << "Inside for loop of objFrames" << std::endl;
		if (pins->rolls.size() == 1)
		{
			//std::cout << "size =1 " << pins.size() << std::endl;
			std::cout << pins->rolls[0] << std::endl;
		}
		else if (pins->rolls.size() == 2)
		{
			//std::cout << "size =2 " << pins.size() << std::endl;
			std::cout << pins->rolls[0] << "\t" << pins->rolls[1] << std::endl;
		}
		else if (pins->rolls.size() == 3)
		{
			//std::cout << "size =3" << pins.size() << std::endl;
			std::cout << pins->rolls[0] << "\t" << pins->rolls[1] << "\t" << pins->rolls[2] << std::endl;
		}
	}
	std::cout << "Total score is = " << total << std::endl;
#endif
	



}
