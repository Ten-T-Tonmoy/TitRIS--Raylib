#pragma once
#include <vector>
// to ensure its done once

using namespace std;

class Graph
{
public:
    Graph(); // constructor here
    int graph[20][10];
    void buildgraph();
    void showgraph();
    void drawgraph();

private:
    int rows, cols, size;
    vector<Color> colors;
    vector<Color> combocolor();
};