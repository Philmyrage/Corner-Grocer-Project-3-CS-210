#include "operations.hpp"

#include <string>
#include <cstdlib>
#include <iostream>

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

int Operations::ItemLookup() const
{
    int count = 0;
    std::cout << "Item lookup not implemented" << std::endl;
    return count;
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
    std::exit(0);
}
