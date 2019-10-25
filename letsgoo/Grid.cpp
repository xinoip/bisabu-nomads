#include "Grid.h"

Grid::Grid()
{
    for (int i = 0; i < N; i++)
    {
        id[i] = i;
    }
}

bool Grid::isConnected(int p, int q) const
{
    return (id[p] == id[q]);
}

void Grid::connectPair(int p, int q)
{
    int pValue = id[p];
    int qValue = id[q]; 
    for (int i = 0; i < N; i++)
    {
        if (id[i] == pValue) 
            id[i] = qValue;
    }
}