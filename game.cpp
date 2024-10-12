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

void Game::InputManage()
{
    int input = GetKeyPressed();
    switch (input)
    {
    case KEY_A:
        moveleft();
        break;
    case KEY_D:
        moveright();
        break;
    case KEY_S:
        movedown();
        break;
    case KEY_W:
        current.rotate();
        break;
    }
}
void Game::moveleft()
{
    current.move(0, -1);
    if (istileout())
        current.move(0, 1);
}
void Game::moveright()
{
    current.move(0, 1);
    if (istileout())
        current.move(0, -1);
}
void Game::movedown()
{
    current.move(1, 0);
    if (istileout())
        current.move(-1, 0);
}

bool Game::istileout()
{
    vector<Position> boxes = current.newpos();
    for (Position box : boxes)
    {
        if (graph.isoutside(box.row, box.cols))
            return true;
    }
    return false;
}
