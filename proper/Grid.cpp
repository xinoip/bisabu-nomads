#include "Grid.h"

Grid::Grid()
{
    for (int i = 0; i < SIZE; i++)
    {
        id[i] = i;
    }
}

void Grid::unionPair(int p, int q)
{
    int pid = id[p];
    int qid = id[q];
    for (int i = 0; i < SIZE; i++)
    {
        if (id[i] == pid)
        {
            id[i] = qid;
        }
    }
}

bool Grid::isConnected(int p, int q)
{
    return (id[p] == id[q]);
}