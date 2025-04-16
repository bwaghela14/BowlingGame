#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;


#define NORMAL 1
#define SPARE 2
#define STRIKE 3
#define TENTH_FRAME 4

class IFrame
{
    private:


     
 public:
 
    std::vector<int>rolls;
    int iFrameTotalScore;
    int b_IsType;

    virtual int UpdateFrameScore(std::vector<IFrame*>&objFrames,int index) = 0;
    
    int getFrameTotalSocre()const
    {
        return iFrameTotalScore;
    }
    virtual ~IFrame()
{
cout <<"delete"<<endl;
}
};




class NormalFrame : public IFrame
{
    public:
    
    NormalFrame(int firstRoll = 0, int secondRoll = 0)
    {
        rolls.push_back(firstRoll);
        rolls.push_back(secondRoll);
    }
    
    int UpdateFrameScore(std::vector<IFrame*>&objFrames,int index)override
    {
        cout<<"Normal Fram"<<endl;
        int iReturnNormalFrameSocre = 0;
        
        if(index < 10)
        {
            iReturnNormalFrameSocre = objFrames[index]->rolls[0] + objFrames[index]->rolls[1];
        }
        cout<< "iReturnNormalFrameSocre = "<<iReturnNormalFrameSocre<<endl;
        return iReturnNormalFrameSocre ;
    }
};

class SpareFrame : public IFrame
{
    public:
        
    SpareFrame(int firstRoll = 0, int secondRoll = 0)
    {
        rolls.push_back(firstRoll);
        rolls.push_back(secondRoll);
    }
    
    
        int UpdateFrameScore(std::vector<IFrame*>&objFrames,int index)
    {
        cout<<"Spare Frame"<<endl;
        int iReturnSpareFrameSocre = 10;
        
        if((index + 1) < 10)
        {
            cout<<"Spare bonus = "<<objFrames[index+1]->rolls[0]<<endl;
            iReturnSpareFrameSocre += objFrames[index+1]->rolls[0];
        }
        cout<<"iReturnSpareFrameSocre"<<iReturnSpareFrameSocre<<endl;
        return iReturnSpareFrameSocre;
    }
};

class StrikeFrame : public IFrame
{
    public:
        
    StrikeFrame(int firstRoll = 0,int secondRoll = 0)
    {
        rolls.push_back(firstRoll);
        rolls.push_back(0);
    }
    
    int UpdateFrameScore(std::vector<IFrame*>&objFrames,int index)
    {
        int iReturnStrikeFrameSocre = 10;
       
    cout<<"strike Frame"<<endl;
        
        if (index + 1 < objFrames.size()) 
        {
            iReturnStrikeFrameSocre += objFrames[index + 1]->rolls[0];
            
            if (objFrames[index + 1]->rolls[0]!=10) 
            {
                
                iReturnStrikeFrameSocre += objFrames[index + 1]->rolls[1];
            } 
            else if (index + 2 < objFrames.size())
            {
                iReturnStrikeFrameSocre += objFrames[index + 2]->rolls[0];
            }
            else if(index +2 ==10)
            {
             iReturnStrikeFrameSocre +=objFrames[index + 1]->rolls[1];   
            }
        }
        cout<<"iReturnStrikeFrameSocre"<<iReturnStrikeFrameSocre<<endl;
         return iReturnStrikeFrameSocre;
    }
};

class TenthFrame : public IFrame
{
    public:
    TenthFrame(int firstRoll = 0,int secondRoll = 0,int thirdRoll=0)
    {
        rolls.push_back(firstRoll);
        rolls.push_back(secondRoll);
        rolls.push_back(thirdRoll);
    }
    
    int UpdateFrameScore(std::vector<IFrame*>&objFrames,int index)
    {
        cout<<"10th Frame"<<endl;
        int iReturnTenthFrameSocre = 0;
        

        iReturnTenthFrameSocre+= objFrames[index]->rolls[0] + objFrames[index]->rolls[1] 
               +objFrames[index]->rolls[2];
                       cout<<"iReturnTenthFrameSocre = "<<iReturnTenthFrameSocre<<endl;
               return iReturnTenthFrameSocre;
    }
};

class BowlingGame    //
{
    private : 
    std::vector<IFrame*>objFrames;

public :
int CalculateTotalScore()
{
    cout<<"CalculateTotalScore"<<endl;
    int total = 0;
    
    for (int i = 0; i < objFrames.size(); ++i) 
    {
        total+=objFrames[i]->UpdateFrameScore(objFrames,i);
    }
    return total;
}

void deleteObject()
{

    for (int i = 0; i < objFrames.size(); ++i) 
    {
        delete objFrames[i];
    }
}
    virtual ~BowlingGame() = default;
    
    // bool isSpare()
    // {
    //     return 
    // }am
    
    void insertFrame(IFrame *frame)
    {
        objFrames.push_back(frame);
        
    for(auto frame : objFrames)
    {
        if(frame->b_IsType == SPARE || frame->b_IsType == NORMAL)
        cout<<frame->rolls[0]<<"\t"<<frame->rolls[1]<<endl;
        else if(frame->b_IsType == STRIKE)
        cout<<"Strike = "<<frame->rolls[0]<<"\t"<<frame->rolls[1]<<endl;
        else if(frame->b_IsType == TENTH_FRAME)
        cout<<"Strike = "<<frame->rolls[0]<<"\t"<<frame->rolls[1]<<"\t"<<frame->rolls[2]<<endl;
    }
    }
    
};


int main()
{
    std::cout<<"Hello World"<<endl;
    
    
int i =1 ;

    BowlingGame objBowlingGame;
    while(i>0 && i<=10)
    {
        int FirstRoll = 0 , SecondRoll = 0;

        IFrame *ptrFrame = nullptr;
        
       if(i<=9)
       {
        cout<<"Enter first Roll Score"<<endl;
        cin>>FirstRoll;
        

        
        if(FirstRoll == 10)
        {
            ptrFrame = new StrikeFrame(FirstRoll,0); 
            ptrFrame->b_IsType = STRIKE;
        }
        else
        {
        cout<<"Enter 2nd Roll Score"<<endl;
        cin>>SecondRoll;
        
        if(FirstRoll + SecondRoll == 10)
        {
        ptrFrame = new SpareFrame(FirstRoll , SecondRoll);
        ptrFrame->b_IsType = SPARE;
        }
        else
        {
            ptrFrame = new NormalFrame(FirstRoll , SecondRoll);
            ptrFrame->b_IsType = NORMAL;
        }
        
        }
       }
       else if(i==10)
       {
           cout<<"Inside 10th Frame"<<endl;
        int thirdRoll = 0;
        cout<<"Enter first Roll Score"<<endl;
        cin>>FirstRoll;

        cout<<"Enter 2nd Roll Score"<<endl;
        cin>>SecondRoll;
        
        if(FirstRoll == 10 || (FirstRoll + SecondRoll == 10))
        {
        cout<<"Enter 3rd Roll Score"<<endl;
        cin>>thirdRoll;

        }

        ptrFrame = new TenthFrame(FirstRoll , SecondRoll,thirdRoll);
        ptrFrame->b_IsType = TENTH_FRAME;        
        }
        
        
        objBowlingGame.insertFrame(ptrFrame);
        i++;
        
        
       }
       
       int total = objBowlingGame.CalculateTotalScore();
        

    cout<<"All 10 frames added"<<"\t"<<"total =  "<<total<<endl;

objBowlingGame.deleteObject();


    return 0;
}