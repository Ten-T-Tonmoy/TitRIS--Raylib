#pragma once
#include <iostream>
#include <raylib.h>

using namespace std;

class Position
{
public:
    Position(int row, int cols);
    int row;
    int cols;
};