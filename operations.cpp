#include "operations.hpp"

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <format>
#include <algorithm>
#include <cctype>

void Operations::PerformOperation(EMenuSelection selection) const
{
    //Backup ItemsPurchased data before any operations.
    WriteToBackUpFile(ItemFrequencyAndMaxLength().first);

    switch (selection)
    {
    case EMenuSelection::ItemLookup:
        this->ItemLookup();
        break;
    case EMenuSelection::DisplayInventory:
        this->PrintItemFrequencies();
        break;
    case EMenuSelection::DisplayHistogram:
        this->DisplayHistogram();
        break;
    case EMenuSelection::InsertItem:
        this->InsertItem();
        break;
    case EMenuSelection::Exit:
        this->Exit();
        break;
    }
}

void Operations::ItemLookup() const
{
    //clear the input buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //get the user input
    std::string item = "";
    std::cout << "Enter the name of the item: ";
    getline(std::cin, item);
    StringToLower(item);
    MFrequencyMap frequency = ItemFrequencyAndMaxLength(item).first;
    std::cout << item << " " << frequency[item] << std::endl;
}

std::pair<MFrequencyMap, int> Operations::ItemFrequencyAndMaxLength(const std::string& item) const
{
    MFrequencyMap frequencyMap;
    int t_max = 0;
    std::ifstream file;
    file.open(INPUT_FILE_PATH);

    if (file.is_open())
    {
        //read the file
        std::string line;
        while (getline(file, line) && !file.eof())
        {
            //convert the string to lowercase...
            StringToLower(line);

            //Cache the max name length for formatting output..
            if (line.size() > t_max)
            {
                t_max = line.size();
            }
            //if the item is in the map already increment its frequency
            if (frequencyMap.contains(line))
            {
				frequencyMap[line]++;
            }
            //else add it to the map
            else
            {
				frequencyMap[line] = 1;
            }
        }
    }
    else
    {
		std::cout << "Unable to open " << INPUT_FILE_PATH << std::endl;
    }

    //close the file
    file.close();

    std::pair<MFrequencyMap, int> temp;

    if (item != "")
    {
        MFrequencyMap result;
        result[item] = frequencyMap[item];
        temp.first = result;
        temp.second = item.size();
        return temp;
    }
    else
    {
        temp.first = frequencyMap;
        temp.second = t_max;
        return temp;
    }
}

void Operations::PrintItemFrequencies() const
{
    MFrequencyMap frequencyMap = ItemFrequencyAndMaxLength().first;
    //print the sales data...
    for(auto it = frequencyMap.begin(); it != frequencyMap.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

void Operations::DisplayHistogram() const
{
	//get the frequency map from data file
    std::pair<MFrequencyMap, int> t = ItemFrequencyAndMaxLength();
    MFrequencyMap frequencyMap = t.first;
    int maxLength = t.second;
    //loop the map print the value of the key as the box, and print '*' for the frequency
    for (auto it : frequencyMap)
    {
        std::string fre = "";
        for (int i = 0; i < it.second; ++i)
        {
            fre += "*"; 
        }
        std::cout << std::format("{:<{}}{:>}{:<{}}", it.first, maxLength, "|", fre, maxLength, maxLength);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Operations::Exit() const
{
    //Write the current contents of the Frequency map to a back up file before exiting the program.
    WriteToBackUpFile(ItemFrequencyAndMaxLength().first);

    std::cout << "Goodbye" << std::endl;
    std::exit(0);
}

void Operations::StringToLower(std::string& OUT) const
{
    std::transform(OUT.begin(), OUT.end(), OUT.begin(), [](unsigned char s){return std::tolower(s);});
}

void Operations::WriteToBackUpFile(const MFrequencyMap& data) const
{
    std::ofstream outFile;
    outFile.open(BACKUP_FILE_PATH);

    if (outFile.is_open())
    {
        for (auto it : data)
        {
            outFile << it.first << " " << it.second << std::endl;
        }
    }
    else
    {
        std::cout << "Program Failed to open " << BACKUP_FILE_PATH << std::endl;
    }

    outFile.close();
}

void Operations::InsertItem() const
{
    std::cout << "InsertItem is not Implemented." << std::endl;
}
