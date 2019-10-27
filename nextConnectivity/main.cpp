#include "Network.hpp"
#include <iostream>

using namespace std;

int main() {

	Network network(10);

	int p, q;
    char mode;
    
    while (true)
    {
        cin >> p >> q >> mode;

        if (mode == 'C' || mode == 'c')
        {
            cout << "isConnected(" << p << "," << q << ") = " << network.isConnected(network.getNode(p), network.getNode(q)) << endl;
        }
        else if (mode == 'U' || mode == 'u')
        {
            cout << "Connecting " << p << " with " << q << endl;
            network.connectNodes(network.getNode(p), network.getNode(q));
        } 
        else if (mode == 'Q' || mode == 'q')
        {
            cout << "exit\n";
            break;
        }
    }

	return 0;
}