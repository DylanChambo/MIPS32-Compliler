#ifndef TYPE_H
#define TYPE_H

#include <vector>

enum BASE_TYPE
{
    TYPE_INT,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_ARRAY,
    TYPE_FUNCTION,
    TYPE_POINTER
};

class Dimensions
{
private:
    std::vector<int> dimensions;

public:
    Dimensions();
    void addDimension(int dimension);
    std::vector<int> getDimensions();
    int getNumDimensions();
};

class Type
{
private:
    BASE_TYPE base_type;
    Dimensions *dimensions;

public:
    Type(BASE_TYPE base_type) : base_type(base_type){};
    void setDimensions(Dimensions *dimensions);
};

#endif