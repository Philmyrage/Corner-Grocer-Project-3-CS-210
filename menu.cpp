#include "menu.hpp"

#include <iostream>
#include <format>

void Menu::DisplayMenu()
{
	std::cout << std::format("{:#^{}}", " MENU OPTIONS ", 100) << std::endl;
	std::cout << std::format("{:<15} {:<15} {:<15} {:<15} {:<15}",
							 " 1. Item Lookup\n", "2. Display Inventory\n",
							 "3. Display Histogram\n", "4. Insert Item\n", "5. Exit\n")
			  << std::endl;

	PromptMenuSelection();
}

void Menu::PrintSelection()
{
	std::cout << menuSelection << std::endl;
}

void Menu::PromptMenuSelection()
{
	std::cout << "Select an option: ";
	std::cin >> menuSelection;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Invalid input. Please try again." << std::endl;
		PromptMenuSelection();
	}
}

std::istream &operator>>(std::istream &is, EMenuSelection &selection)
{
	//if input is within range ie. greater than 1 and less than or equal to enum max set selection.
	//else set input stream state to fail.
	int max = static_cast<int>(EMenuSelection::MAX_VALUE);
	int value = 0;
	is >> value;
	if (value > 0 && value <= max)
	{
		selection = static_cast<EMenuSelection>(value);
	}
	else
	{
		is.setstate(std::ios_base::failbit);
	}
	return is;
}

std::ostream &operator<<(std::ostream &os, EMenuSelection &selection)
{
	
	switch (selection)
	{
	case EMenuSelection::ItemLookup:
		os << "Item Lookup";
		break;
	case EMenuSelection::DisplayInventory:
		os << "Display Inventory";
		break;
	case EMenuSelection::DisplayHistogram:
		os << "Display Histogram";
		break;
	case EMenuSelection::Exit:
		os << "Exit";
		break;
	default:
		os.setstate(std::ios_base::failbit);
		break;
	}
	return os;
}