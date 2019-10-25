#ifndef Grid_h
#define Grid_h

class Grid
{
public:
    Grid();
    bool isConnected(int p, int q) const;
    void connectPair(int p, int q);

private:
    const static int N = 23;
    int id[N];
};

#endif