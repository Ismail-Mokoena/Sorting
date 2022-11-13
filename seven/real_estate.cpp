//-----------------------------------------------------------
//  Purpose:    Implementation of RealEstate class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include "real_estate.h"

string trim(const string str)
{
    int start = 0;
    int end = str.length() - 1;
    while ((start < int(str.length())) && (isspace(str[start]))) start++;
    while ((end > start) && (isspace(str[end]))) end--;
    return str.substr(start, (end - start + 1));
}

RealEstate::RealEstate()
{
    HouseNum = 0;
    Street = "";
    City = "";
    State = "";
    ZipCode = 0;
    Price = 0;
    Bed = 0;
    Bath = 0.0;
    SqFt = 0;
    LotSize = 0.0;
}

RealEstate::RealEstate(const RealEstate& real_estate)
{
    HouseNum = real_estate.HouseNum;
    Street = real_estate.Street;
    City = real_estate.City;
    State = real_estate.State;
    ZipCode = real_estate.ZipCode;
    Price = real_estate.Price;
    Bed = real_estate.Bed;
    Bath = real_estate.Bath;
    SqFt = real_estate.SqFt;
    LotSize = real_estate.LotSize;
}

RealEstate::~RealEstate()
{
}

int    RealEstate::getHouseNum() { return HouseNum; }
string RealEstate::getStreet() { return Street; }
string RealEstate::getCity() { return City; }
string RealEstate::getState() { return State; }
int    RealEstate::getZipCode() { return ZipCode; }
int    RealEstate::getPrice() { return Price; }
int    RealEstate::getBed() { return Bed; }
float  RealEstate::getBath() { return Bath; }
int    RealEstate::getSqFt() { return SqFt; }
float  RealEstate::getLotSize() { return LotSize; }

void RealEstate::setHouseNum(int house_num) { HouseNum = house_num; }
void RealEstate::setStreet(string street) { Street = street; }
void RealEstate::setCity(string city) { City = city; }
void RealEstate::setState(string state) { State = state; }
void RealEstate::setZipCode(int zipcode) { ZipCode = zipcode; }
void RealEstate::setPrice(int price) { Price = price; }
void RealEstate::setBed(int bed) { Bed = bed; }
void RealEstate::setBath(float bath) { Bath = bath; }
void RealEstate::setSqFt(int sqft) { SqFt = sqft; }
void RealEstate::setLotSize(float lot_size) { LotSize = lot_size; }

void RealEstate::print()
{
    cout << "HouseNum:  " << HouseNum << endl
        << "Street:    " << Street << endl
        << "City:      " << City << endl
        << "State:     " << State << endl
        << "ZipCode:   " << ZipCode << endl
        << "Price:     " << Price << endl
        << "Bed:       " << Bed << endl
        << "Bath:      " << Bath << endl
        << "SqFt:      " << SqFt << endl
        << "LotSize:   " << LotSize << endl << endl;
}

void RealEstate::read_txt(ifstream& din)
{
    string extra = "";
    din >> HouseNum;
    getline(din, Street, ','); Street = trim(Street);
    getline(din, City, ','); City = trim(City);
    din >> State;
    din >> ZipCode;
    din >> Price;
    din >> Bed; getline(din, extra);
    din >> Bath; getline(din, extra);
    din >> SqFt; getline(din, extra);
    din >> LotSize; getline(din, extra);
}

void RealEstate::read_csv(ifstream& din)
{
    string input = "";
    getline(din, input, ','); HouseNum = atoi(input.c_str());
    getline(din, input, ','); Street = trim(input);
    getline(din, input, ','); City = trim(input);
    getline(din, input, ','); State = trim(input);
    getline(din, input, ','); ZipCode = atoi(input.c_str());
    getline(din, input, ','); Price = atof(input.c_str());
    getline(din, input, ','); Bed = atoi(input.c_str());
    getline(din, input, ','); Bath = atof(input.c_str());
    getline(din, input, ','); SqFt = atoi(input.c_str());
    getline(din, input, ','); LotSize = atof(input.c_str());
}

void RealEstate::write_txt(ofstream& dout)
{
    dout << HouseNum << " "
        << Street << ", "
        << City << ", "
        << State << " "
        << ZipCode << "\n"
        << Price << "\n"
        << Bed << " bed\n"
        << Bath << " bath\n"
        << SqFt << " sqft\n"
        << LotSize << " acre lot\n" << endl;
}

void RealEstate::write_csv(ofstream& dout)
{
    dout << HouseNum << ","
        << Street << ","
        << City << ","
        << State << ","
        << ZipCode << ","
        << Price << ","
        << Bed << ","
        << Bath << ","
        << SqFt << ","
        << LotSize << "," << endl;
}

