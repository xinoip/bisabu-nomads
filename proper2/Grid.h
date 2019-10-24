#ifndef Grid_h
#define Grid_h

class Grid
{
public:
    Grid();
    void unionPair(int p, int q);
    bool isConnected(int p, int q);
private:
    static const int SIZE = 9;
    int id[SIZE];
};

#endif