#ifndef Grid_h
#define Grid_h

class Grid
{
public:
    Grid();
    bool isConnected(int p, int q);
    void connectPair(int p, int q);
    int rootOf(int i);

private:
    const static int N = 23;
    int id[N];
    int weight[N];
};

#endif