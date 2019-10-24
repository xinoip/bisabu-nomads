#include "Grid.h"

Grid::Grid()
{
    for (int i = 0; i < SIZE; i++)
    {
        id[i] = i;
    }
}

int Grid::rootOf(int i)
{
    while (i != id[i])
        i = id[i];
    return i;
}

void Grid::unionPair(int p, int q)
{
    int i = rootOf(p);
    int j = rootOf(q);

    if (i == j)
        return;

    if (weight[i] < weight[j])
    {
        id[i] = j;
        weight[j] += weight[i];
    }
    else
    {
        id[j] = i;
        weight[i] += weight[j];
    }
}

bool Grid::isConnected(int p, int q)
{
    return (rootOf(p) == rootOf(q));
}