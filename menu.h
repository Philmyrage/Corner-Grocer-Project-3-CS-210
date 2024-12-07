#pragma once

#include <istream>
#include <fstream>
#include <iostream>
#include <utility>

enum class EMenuSelection
{
	None = 0,
	ItemLookup = 1,
	DisplayInventory = 2,
	DisplayHistogram = 3,
	Exit = 4,

};

class Menu
{
public:

	Menu() : menuSelection(EMenuSelection::None) {}

	//Getters
	inline EMenuSelection GetMenuSelection() { return menuSelection; }

	//Prints menu
	void DisplayMenu();

	void PrintSelection();



protected:


private:

	EMenuSelection menuSelection;


	void PromptMenuSelection();
};

std::istream& operator>>(std::istream& is, EMenuSelection& selection);
std::ostream& operator<<(std::ostream& os, EMenuSelection& selection);