/*
	Created By: Phillip Wood
	Date: 12/12/2024
	GitHub: https://github.com/Philmyrage/Corner-Grocer-Project-3-CS-210
*/

#pragma once

enum class EMenuSelection
{
	None = 0,
	ItemLookup = 1,
	DisplayInventory = 2,
	DisplayHistogram = 3,
	InsertItem = 4,
	RemoveItem = 5,
	Exit = 6, //Exit should always be max when adding to options.
	MAX_VALUE = Exit
};
