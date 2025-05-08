#include "ConfigReader.h"


namespace fs = std::filesystem;

ConfigReader& ConfigReader::GetInstance()
{
        static ConfigReader instance;
        return instance;
    
}
bool ConfigReader::RunTestorApp(const std::string& objKey)
{
    fs::path exePath = fs::current_path();

    std::cout << exePath << std::endl;
    fs::path configPath = exePath.parent_path() / "BowlingGame" / "Config" / "config.txt";
    std::ifstream config(configPath.string());

    if (!config.is_open()) 
    {
        std::cerr << "Could not open config file at: " << configPath << "\n";
        
    }
    else
    { 
        std::string line;
        while (std::getline(config, line))
        {
            std::istringstream iss(line);
            std::string key, equalSign, value;
            if (iss >> key >> equalSign >> value)
            {
                objConfigMap[key] = value;
            }
        }

        try
        {
            SetMaxFrameValue();        //Setting max frame value
        }
        catch (const std::exception& ex)
        {
            std::cout << "settting fallback value of 10 in catch block  " <<ex.what()<< std::endl;
            iMaxFrameValue = 10;
        }

        const std::string isTestorApp = GetAppOrTestValue(objKey);
        
        //here key is ModeOfGame

        if (isTestorApp == "Test")       //Run test
            return true;
        else if (isTestorApp == "App")
            return false;

    }
   return false;
}

std::string ConfigReader::GetAppOrTestValue(const std::string& key)
{
    if (objConfigMap.size() > 0)
    {
        for (auto i : objConfigMap)
        {
            std::cout <<"Key = " << i.first<< "   "<<" Value= "<<i.second << std::endl;
        }
        return objConfigMap[key];
    }
}

int ConfigReader::GetMaxFrameValue() const
{
    return iMaxFrameValue;
}

void ConfigReader::SetMaxFrameValue() 
{
    std::cout << "Inside SetMaxFrameValue" << std::endl;
    std::string strValue;

    try {
        strValue = objConfigMap.at("MaxBowlingFrame");
        iMaxFrameValue = std::stoi(strValue);
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        std::cout << "Setting fallback value of 10\n";
        iMaxFrameValue = 10;
    }
}

ConfigMap ConfigReader::getConfigMap()const
{
    return objConfigMap;
}
