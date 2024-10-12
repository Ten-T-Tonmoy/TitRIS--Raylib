#include "tiles.h"
#include <iostream>
#include <raylib.h>

using namespace std;

Tiles::Tiles()
{
    colors = combocolor();
    cellsize = 30;
    roation = 0;
    rowoff = 0;
    coloff = 0;
}

void Tiles::drawTile()
{
    vector<Position> boxes = newpos();
    for (Position box : boxes)
    {
        DrawRectangle(box.cols * cellsize + 1, box.row * cellsize + 1, cellsize - 1, cellsize - 1, colors[id]);
    }
}

vector<Color> Tiles::combocolor()
{
    Color darkGrey = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

    Color lightBlue = {59, 85, 162, 255};
    Color darkBlue = {44, 44, 127, 255};

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

// cells hold key to pos for each block
void Tiles::move(int row, int col)
{
    // ctrl+. quite handy
    rowoff += row;
    coloff += col;
}

vector<Position> Tiles::newpos()
{
    vector<Position> boxes = cells[roation];
    vector<Position> movedstate;
    for (Position box : boxes)
    {
        Position newp = Position(box.row + rowoff, box.cols + coloff);
        movedstate.push_back(newp);
    }
    return movedstate;
}