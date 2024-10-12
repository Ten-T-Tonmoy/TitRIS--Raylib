#include <iostream>
#include <raylib.h>
#include "graphgrid.h"

using namespace std;

Graph::Graph()
{

    rows = 20;
    cols = 10;
    size = 30;
    buildgraph();
    colors = combocolor();
}

void Graph::buildgraph()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            graph[i][j] = 0;
        }
    }
}
void Graph::showgraph()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

std::vector<Color> Graph::combocolor()
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

void Graph::drawgraph()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int value = graph[i][j];
            // value will be color decider
            DrawRectangle(j * size + 1, i * size + 1, size - 1, size - 1, colors[value]);
        }
    }
}

bool Graph::isoutside(int row, int col)
{
    // row and col are cell position
    // so its checking cells
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return false;
    }
    return true;
}
