#include "game.h"
#include <random>

Game::Game()
{
    graph = Graph();
    // L,J,I,O,S,T,Z
    alltypes = allblocks();
    current = randomtile();
    next = randomtile();
}

Tiles Game::randomtile()
{
    if (alltypes.empty())
        alltypes = allblocks();

    int randpos = rand() % alltypes.size();
    Tiles tile = alltypes[randpos];
    alltypes.erase(alltypes.begin() + randpos);

    return tile;
}

vector<Tiles> Game::allblocks()
{
    return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

// when void draw() showed no error
// cause thought new declaration of function
// bt when game::draw its error cause not in in class declaration

void Game::draw()
{
    graph.drawgraph();
    current.drawTile();
}