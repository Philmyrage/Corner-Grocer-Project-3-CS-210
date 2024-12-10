#include "operations.hpp"

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

void Operations::PerformOperation(EMenuSelection selection) const
{
    // TODO: Open FIle here and pass to functions that need it.
    // it will keep me from having to open a file in every function, less code, and reduncancy.
    switch (selection)
    {
    case EMenuSelection::ItemLookup:
        this->ItemLookup();
        break;
    case EMenuSelection::DisplayInventory:
        this->DisplayInventory();
        break;
    case EMenuSelection::DisplayHistogram:
        this->DisplayHistogram();
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
    std::map<std::string, int> frequency = ItemFrequency(item);
    std::cout << item << " " << frequency[item] << std::endl;
}

std::map<std::string, int> Operations::ItemFrequency(const std::string& item) const
{
    std::map<std::string, int> frequencyMap;
    int frequency = 0;
    std::ifstream file;
    file.open(INPUT_FILE_NAME);

    if (file.is_open())
    {
        //read the file
        std::string line;
        while (getline(file, line) && !file.eof())
        {
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
		std::cout << "Unable to open " << INPUT_FILE_NAME << std::endl;
    }

    if (item != "")
    {
        std::map <std::string, int> result;
        result[item] = frequencyMap[item];
        return result;
    }
    else
    {
        return frequencyMap;
    }
}

void Operations::DisplayInventory() const
{
    std::cout << "Display inventory not implemented" << std::endl;
}

void Operations::DisplayHistogram() const
{
    std::cout << "Display histogram not implemented" << std::endl;
}

void Operations::Exit() const
{
    std::cout << "Goodbye" << std::endl;
    std::exit(0);
}

void Operations::StringToLower(std::string& OUT)
{
}
