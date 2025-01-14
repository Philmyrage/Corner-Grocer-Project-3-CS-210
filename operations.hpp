/*
    Created By: Phillip Wood
    Date: 12/12/2024
    GitHub: https://github.com/Philmyrage/Corner-Grocer-Project-3-CS-210
*/

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
    void PerformOperation(const EMenuSelection& selection) const;

protected:

private:
    //** The input file name */
    const std::string INPUT_FILE_PATH = "ItemsPurchased.txt";

    //** The backup data file path*/
    const std::string BACKUP_FILE_PATH = "frequency.dat";

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

    /**
     * @details used to make sure that the program is case insensitive.
     * @warning this function may be const but mutates a variable passed as an out parameter, use caution when using.
     * \param OUT string needing to be mutated to remove all upper case letters.
     */
    void StringToLower(std::string& OUT) const;

    /**
     * @details This function checks for a current backup, if one doesn't exist, it creates one and writes 
     * the contents of the current frequency map.
     * 
     */
    void WriteToBackUpFile(const MFrequencyMap& data) const;

    /**
     * @details Lets the user input a new item and appends the input to end of the items purchased file...
     * 
     */
    void InsertItems() const;

    /**
    * @details Lets the user remove a quantity of chosen items from the file
    */
    void RemoveItems() const;
};
