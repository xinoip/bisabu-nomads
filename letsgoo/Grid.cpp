#include "Grid.h"

Grid::Grid()
{
    for (int i = 0; i < N; i++)
    {
        id[i] = i;
    }
}

bool Grid::isConnected(int p, int q)
{
    return (rootOf(p) == rootOf(q));
}

void Grid::connectPair(int p, int q)
{
    int pRoot = rootOf(p);
    int qRoot = rootOf(q);
    id[pRoot] = qRoot;
}

int Grid::rootOf(int i)
{
    while(i != id[i]) {
        i = id[i];
    }
    return i;
}