#pragma once
#ifndef REAL_ESTATEDB_H
#define REAL_ESTATEDB_H
#include"real_estate.h"
#include <string>
#include <vector>


class RealEstateDB
{
public:
	RealEstateDB();
	~RealEstateDB();
	void readtxt(std::string file);
	void readcsv(std::string file);
	void writetxt(std::string file);
	void writecsv(std::string file);
	void selection_sort();
	void quick_sort(int low_index, int high_index);
	void print();
	int getSize();
	
private:
	std::vector<RealEstate> estate_obj;
	int partition(int low_index, int high_index);
};


#endif // !REAL_ESTATEDB_H
