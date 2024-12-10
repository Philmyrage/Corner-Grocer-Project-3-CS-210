#pragma once

#include "EMenuSelection.hpp"
#include <string>
#include <map>

/**
 * @headerfile operations.h
 * @brief Header file for operations.cpp
 * @details This class will contain all the operations for the program.
 * @author Phillip Wood
 * @date 12/7/2024
 */


 //defining frequencymap type so syntax is much simpliar.
 typedef std::map<std::string, int> MFrequencyMap;

class Operations
{
public:
    // Public function that takes the menuselction as a parameter
    // and conducts the desired operation.
    void PerformOperation(EMenuSelection selection) const;

protected:
    /**
     * @brief member variable to cache user input to print it back to the user...
     * @warning This variable should only be changed by user input.
     */
     std::string item;

private:
    //** The input file name */
    const std::string INPUT_FILE_PATH = "frequency.dat";

    /**
     * @brief prints the item name and its frequency.
     *
     */
     void ItemLookup() const;

     /**
      * @details gets the frequency of the item given by the user also finds the max name length.
      * @param item is optional and is the name of the item the user searches for
      * in item lookup operation. Leave blank to get all items.
      * 
      * 
      * \returns a pair first is map and second is int which represents the maxnamelength.
      */
     std::pair<MFrequencyMap, int> ItemFrequencyAndMaxLength(const std::string& item = "") const;

    /**
     * @brief Prints all items and their frequencies in the inventory.
     *
     */
    void PrintItemFrequencies() const;

    /**
     * @brief prints a histogram of the inventory.
     * @details The histogram boxes are the name of the item.
     * The height of the box is the frequency of the item.
     *
     */
    void DisplayHistogram() const;

    /**
     * @brief Terminate the program.
     *
     */
    void Exit() const;

    void StringToLower(std::string& OUT);
};
