#include "operations.hpp"

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <format>
#include <algorithm>
#include <cctype>
#include <exception>

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
    case EMenuSelection::RemoveItem:
        this->RemoveItem();
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
    std::ifstream inFile;
    std::ofstream outFile;
    inFile.open(INPUT_FILE_PATH);
    //save the contents of the current itemsPurchased file
    std::vector<std::string> cache;
    if (inFile.is_open())
    {
        std::string line = "";
        while (inFile >> line)
        {
            StringToLower(line);
            cache.resize(cache.size() + 1, line);
        }
    }
    else
    {
        std::cout << "Failed to open " << INPUT_FILE_PATH << std::endl;
    }
    //close the file in preparation to open in output file.
    inFile.close();

    std::cout << "Enter Item Name: ";
    std::string input = "";

    //clear input buffer
    std::cin.ignore();
    std::cin.clear();
    getline(std::cin, input);
    
    //set the input to lowercase
    StringToLower(input);
    //save it to the vector
    cache.resize(cache.size() + 1, input);

    //Write the vector to the itemsPurchased.txt
    outFile.open(INPUT_FILE_PATH);
    if (outFile.is_open())
    {
        for (auto line : cache)
        {
            outFile << line << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to open " << INPUT_FILE_PATH << " for writing..." << std::endl;
    }

    //back up the new data..
    WriteToBackUpFile(ItemFrequencyAndMaxLength().first);
}

void Operations::RemoveItem() const
{
    std::ifstream inFile;
    std::ofstream outFile;
    inFile.open(INPUT_FILE_PATH);
    //save the contents of the current itemsPurchased file
    std::vector<std::string> cache;
    if (inFile.is_open())
    {
        std::string line = "";
        while (inFile >> line)
        {
            StringToLower(line);
            cache.resize(cache.size() + 1, line);
        }
    }
    else
    {
        std::cout << "Failed to open " << INPUT_FILE_PATH << std::endl;
    }
    //close the file in preparation to open in output file.
    inFile.close();

    std::cout << "Enter Item Name: ";
    std::string name = "";
    int quantity = 0;

    //clear input buffer
    std::cin.ignore();
    std::cin.clear();
    getline(std::cin, name);

    try
    {
        //set the exceptions we want to catch.
        std::cin.exceptions(std::ios_base::failbit);

        std::cout << "Enter Quantity: ";
        std::cin >> quantity;
        if (quantity <= 0)
        {
            std::cin.setstate(std::ios_base::failbit);
        }

    }
    catch(const std::ios_base::failure& e){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid Quantity Entered, Defaulting to one Item.\n" << std::endl;
        quantity = 1;
    }

    //set the input to lowercase
    StringToLower(name);

    int count = 1;
    //remove the name of item for given quantity from the vector...
    for (int i = 0; i < cache.size(); ++i)
    {
        if (cache.at(i) == name && count <= quantity)
        {
            cache.erase(cache.begin() + i);
            count++;
        }
    }

    //Write the vector to the itemsPurchased.txt
    outFile.open(INPUT_FILE_PATH);
    if (outFile.is_open())
    {
        for (auto line : cache)
        {
            outFile << line << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to open " << INPUT_FILE_PATH << " for writing..." << std::endl;
    }

    //back up the new data..
    WriteToBackUpFile(ItemFrequencyAndMaxLength().first);
}
