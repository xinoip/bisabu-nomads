#include <iostream>

using namespace std;

class foo
{
public:
    int x;
    const int y;
    foo(int x, int y) : x(x), y(y) {}
};


int main(int argc, char const *argv[])
{
    foo a(5,4);
    cout << a.x << " " << a.y << "\n";
    return 0;
}
