#pragma once
#include "tiles.h"
#include "graphgrid.h"
#include "blocks.cpp"

using namespace std;

class Game
{
public:
    Game();
    Tiles randomtile();
    vector<Tiles> allblocks();
    void draw();
    void InputManage();
    void moveleft();
    void moveright();
    void movedown();
    Graph graph;

private:
    vector<Tiles> alltypes;
    Tiles current;
    bool istileout();
    Tiles next;
};
