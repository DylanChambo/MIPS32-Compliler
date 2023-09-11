#include "type.h"
#include <iostream>

using namespace std;

void Type::setDimensions(Dimensions *dimensions)
{
    this->dimensions = dimensions;
}

void Dimensions::addDimension(int dimension)
{
    if (dimension <= 0)
    {
        cerr << "Error: Dimension must be greater than 0" << endl;
        exit(1);
    }
    this->dimensions.push_back(dimension);
}
std::vector<int> Dimensions::getDimensions()
{
    return this->dimensions;
}

int Dimensions::getNumDimensions()
{
    return this->dimensions.size();
}

Dimensions::Dimensions()
{
    this->dimensions = {};
}