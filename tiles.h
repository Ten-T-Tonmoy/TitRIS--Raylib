#pragma once
#include <iostream>
#include <raylib.h>
#include <vector>
#include <map>
#include "position.h"

using namespace std;

class Tiles
{
public:
    Tiles();
    int id;
    map<int, vector<Position>> cells;
    void drawTile();
    void move(int row, int col);
    vector<Color> combocolor();
    vector<Position> newpos();
    void rotate();

private:
    int cellsize;
    int roation;
    vector<Color> colors;
    int rowoff; // row offset
    int coloff; // coloumn offset
};
