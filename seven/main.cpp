//-----------------------------------------------------------
//  Purpose:    Implementing selection sort and quick sort
//  Author:     Ismail Mokoena
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include "real_estate.h"
#include "real_estatedb.h"

int main()
{
    RealEstateDB datab;
    int option;
    std::string file;
    std::smatch match;
    std::cout << "Sort Data by\n1 - Price\n2-Sqft\nEnter:";
    std::cin >> option;

    std::cout << "Enter File name:";
    std::cin >> file;
    regex txt(".txt");
    regex csv(".csv");

    if (regex_search(file, match, txt))
    {
        datab.readtxt(file);
    }
    if (regex_search(file, match, csv))
    {
        datab.readcsv(file);
    }

    if (option == 1)
    {
        datab.selection_sort();
    }
    if (option == 2)
    {
        datab.quick_sort(0, datab.getSize());
    }
    if (regex_search(file, match, txt))
    {
        datab.writetxt("sorted_house.txt");
    }
    if (regex_search(file, match, csv))
    {
        datab.writecsv("sorted_house.csv");
    }
   
   
    return 0;
}