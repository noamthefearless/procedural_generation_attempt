#include "RandTools.h"
#include <iostream>
#include "Coords.h"
#include <vector>


int main()
{
	std::string a = "\n\n\n\t\t -----------\n\t\t|           |\n\t\t|           |\n\t\t|     *     |\n\t\t|           |\n\t\t|           |\n\t\t|           |\n\t\t|           |\n\t\t|     *     |\n\t\t|           |\n\t\t|           |\n\t\t|           |\n\t\t|           |\n\t\t|     *     |\n\t\t|           |\n\t\t|           |\n\t\t -----------";
    std::string b = "\n\n\n\t\t---------------------------------\n\t       |\t\t\t\t |\n\t       |\t\t\t\t |\n\t       |     *          *          *     |\n\t       |\t\t\t\t |\n\t       |\t\t\t\t |\n\t\t---------------------------------";
    

    std::cout << a << b << std::endl;
   
	return 0;
}


