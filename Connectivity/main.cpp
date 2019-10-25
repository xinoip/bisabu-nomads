#include <iostream>
#include "Grid.h"

using namespace std;

int main()
{
    Grid grid;

    int p, q;
    char mode;
    while (true)
    {
        cin >> p >> q >> mode;

        if (mode == 'C' || mode == 'c')
        {
            cout << "isConnected(" << p << "," << q << ") = " << grid.isConnected(p, q) << endl;
        }
        else if (mode == 'U' || mode == 'u')
        {
            cout << "Connecting " << p << " with " << q << endl;
            grid.connectPair(p, q);
        }
        else if (mode == 'Q' || mode == 'q')
        {
            cout << "exit\n";
            break;
        }
    }

    return 0;
}