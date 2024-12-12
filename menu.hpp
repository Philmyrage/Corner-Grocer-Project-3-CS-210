/*
	Created By: Phillip Wood
	Date: 12/12/2024
	GitHub: https://github.com/Philmyrage/Corner-Grocer-Project-3-CS-210
*/

#pragma once

#include "EMenuSelection.hpp"

#include <iosfwd>

/**
 * @headerfile menu.h
 * @brief This file contains the menu class and enum class declarations for menu options
 * @details This class is responsible for displaying the menu and getting user input for the desired 
 * operation.
 * @author Phillip Wood
 * @date 12/7/2024
 */

class Menu
{
public:

	Menu() : menuSelection(EMenuSelection::None) {}

	//Getters
	/**
	 * @brief Gets the menu selection
	 * \return menuSelection of	type EMenuSelection
	 */
	inline EMenuSelection GetMenuSelection() { return menuSelection; }

	//Prints menu
	/**
	 * @brief Displays the menu.
	 * 
	 */
	void DisplayMenu();

	/**
	 * @brief Prints the menu selection.
	 * @details This function is a debugging function and is not used in the program.
	 */
	void PrintSelection();



protected:


private:

	/**
	 * @brief The menu selection.
	 * @details This variable is used to store the menu selection, and is of type EMenuSelection and is private.
	 */
	EMenuSelection menuSelection;

	/**
	 * @brief Prompts the user for a menu selection.
	 * @details This function is responsible for prompting the user for a menu selection.
	 */
	void PromptMenuSelection();
};

/** Overloaded operators */
std::istream& operator>>(std::istream& is, EMenuSelection& selection);
std::ostream& operator<<(std::ostream& os, EMenuSelection& selection);