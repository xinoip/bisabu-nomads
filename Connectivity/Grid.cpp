#include "Grid.h"

Grid::Grid()
{
    for (int i = 0; i < N; i++)
    {
        id[i] = i;
        weight[i] = 1;
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

    if (pRoot == qRoot)
        return;

    if (weight[pRoot] < weight[qRoot])
    {
        id[pRoot] = qRoot;
        weight[qRoot] += weight[pRoot];
    }
    else
    {
        id[qRoot] = pRoot;
        weight[pRoot] += weight[qRoot];
    }
}

int Grid::rootOf(int i)
{
    while (i != id[i])
    {
        // PATH COMPRESSION
        // LAST IMPROVEMENT
        id[i] = id[id[i]];
        // LAST IMPROVEMENT
        i = id[i];
    }
    return i;
}