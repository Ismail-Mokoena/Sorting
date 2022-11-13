#include "real_estatedb.h"

RealEstateDB::RealEstateDB()
{
	estate_obj = {};
}


RealEstateDB::~RealEstateDB()
{

}

void RealEstateDB::readtxt(std::string file)
{
    // Open input file
    ifstream din;
    din.open(file);
    if (din.fail()) return;
    // Loop reading houses
    RealEstate house;

    while (!din.eof())
    {
        // Read from input file
        house.read_txt(din);
        if (!din.eof())
        {
            // Store in vector
            estate_obj.push_back(house);
           // house.print();
        }
    }
    din.close();

}

void RealEstateDB::readcsv(std::string file) 
{
    // Open input file
    ifstream din;
    din.open(file);
    if (din.fail()) return;
    // Loop reading houses
    RealEstate house;

    while (!din.eof())
    {
        // Read from input file
        house.read_csv(din);
        if (!din.eof())
        {
            // Store in vector
            estate_obj.push_back(house);
            //house.print();
        }
    }
    din.close();

}

void RealEstateDB::writecsv(std::string file)
{
    // Open output file
    ofstream dout;
    dout.open(file);
    if (dout.fail()) return ;

    // Loop writing houses
    for (int i = 0; i < estate_obj.size(); i++)
        estate_obj[i].write_csv(dout);

    // Close files
    dout.close();
}

void RealEstateDB::writetxt(std::string file)
{
    // Open output file
    ofstream dout;
    dout.open(file);
    if (dout.fail()) return;

    // Loop writing houses
    for (int i = 0; i < estate_obj.size(); i++)
        estate_obj[i].write_txt(dout);

    // Close files 
    dout.close();

}

void RealEstateDB::print()
{
    for (int i=0;i<estate_obj.size();i++)
    {
        estate_obj[i].print();
    }
}

void RealEstateDB::selection_sort()
{
    for (int i = 0; i < estate_obj.size() - 1; i++)
    {
        int index_small = i;
        for (int j = i + 1; j < estate_obj.size(); j++)
        {
            if (estate_obj[j].getPrice()< estate_obj[index_small].getPrice())
            {
                index_small = j;
            }
           
        }
        RealEstate temp = estate_obj[i];
        estate_obj[i] = estate_obj[index_small];
        estate_obj[index_small] = temp;
    }
   
}

int RealEstateDB::partition(int low_index, int high_index)
{
    int high = high_index - 1;
    int mid = low_index + (high - low_index) / 2;
    int pivot = estate_obj[mid].getSqFt();
    bool done = false;
    while (!done)
    {
        // Increment lowIndex while estate_obj[lowIndex] < pivot
        while (estate_obj[low_index].getSqFt() < pivot)
        {
            low_index += 1;
        }
        while (pivot < estate_obj[high].getSqFt())
        {
            high -= 1;
        }
        if (low_index >= high)
        {
            done = true;
        }
        else
        {
          
            RealEstate temp = estate_obj[low_index];
            estate_obj[low_index] = estate_obj[high];
            estate_obj[high] = temp;

            low_index += 1;
            high -= 1;
        }
    }


    return high;
}

void RealEstateDB::quick_sort(int low_index, int high_index)
{
    if (low_index >= high_index)
    {
        return;
    }

    int low_end = partition(low_index, high_index);
    quick_sort(low_index, low_end);
    quick_sort(low_end + 1, high_index);
}

int RealEstateDB::getSize()
{
    return estate_obj.size();
}