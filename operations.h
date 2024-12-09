#pragma once

/**
 * @headerfile operations.h
 * @brief Header file for operations.cpp
 * @details This class will contain all the operations for the program.
 * @author Phillip Wood
 * @date 12/7/2024
 */

#include "menu.h" // For EMenuSelection

class Operations
{
public:
    // Public function that takes the menuselction as a parameter
    // and conducts the desired operation.
    void PerformOperation(EMenuSelection selection) const;

protected:
private:
    /**
     * @brief Looks up an item and returns the frequency of the item.
     * @param name Name of the item to be looked up.
     *
     * @return frequency of the item
     */
    int ItemLookup() const;

    /**
     * @brief Prints all items and their frequencies in the inventory.
     *
     */
    void DisplayInventory() const;

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
};
