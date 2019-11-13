#include <iostream>

// post and pre inc overload at the same time

using namespace std;

class Person
{
public:
    int money = 0;

    Person &operator++();
    void operator++(int x);

};

Person &Person::operator++()
{
    money++;
    return *this;
}

void Person::operator++(int x)
{
    money++;
}

int main3()
{
    Person a, b, c;

    ++a;
    ++a;
    a++;
    cout << a.money << "\n";

    cout << "Finished tests!\n";
    return 0;
}
