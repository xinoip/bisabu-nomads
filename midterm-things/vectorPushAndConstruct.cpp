#include <iostream>
#include <vector>

// when pushing to vector, class contructor behaviour

using namespace std;

class Person
{
public:
    Person();
    int x = 0;
};

Person::Person() {
    cout << "CONSTRUCTOR CALLED!\n";
}

int main()
{
    Person a;
    vector<Person> myVector;

    cout << "VECTOR CREATED NOW PUSHING\n\n";

    myVector.push_back(a);
    myVector.push_back(a);


    cout << "Finished tests!\n";
    return 0;
}
