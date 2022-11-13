#ifndef REAL_ESTATE_H
#define REAL_ESTATE_H

//-----------------------------------------------------------
//  Purpose:    Declaration of RealEstate class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class RealEstate
{
public:
	// Constructors
	RealEstate();
	RealEstate(const RealEstate& real_estate);
	~RealEstate();

	// Get methods
	int getHouseNum();
	string getStreet();
	string getCity();
	string getState();
	int getZipCode();
	int getPrice();
	int getBed();
	float getBath();
	int getSqFt();
	float getLotSize();

	// Set methods
	void setHouseNum(int house_num);
	void setStreet(string street);
	void setCity(string city);
	void setState(string state);
	void setZipCode(int zipcode);
	void setPrice(int price);
	void setBed(int bed);
	void setBath(float bath);
	void setSqFt(int sqft);
	void setLotSize(float lot_size);

	// I/O methods
	void print();
	void read_txt(ifstream& din);
	void read_csv(ifstream& din);
	void write_txt(ofstream& dout);
	void write_csv(ofstream& dout);

private:
	int HouseNum;
	string Street;
	string City;
	string State;
	int ZipCode;
	int Price;
	int Bed;
	float Bath;
	int SqFt;
	float LotSize;
};

#endif