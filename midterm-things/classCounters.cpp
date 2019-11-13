#include <iostream>

// Static counters for classes
// counting living instances
// counting classes created so far

using namespace std;

class Person
{
public:
    Person();
    ~Person();

    int getCreatedPersons() const;
    int getLivingPersons() const;

private:
    static int createdPersons;
    static int livingPersons;
};

int Person::createdPersons = 0;
int Person::livingPersons = 0;

Person::Person()
{
    createdPersons++;
    livingPersons++;
}

Person::~Person()
{
    livingPersons--;
}

int Person::getCreatedPersons() const { return createdPersons; }
int Person::getLivingPersons() const { return livingPersons; }

int main()
{
    Person a, b, c;

    int test1_created = b.getCreatedPersons();
    int test1_living = c.getLivingPersons();
    if(test1_created != 3 || test1_living != 3) {
        cerr << "Failed test1!\n";
    } else {
        cout << "Passed test1!\n";
    }

    for (int i = 0; i < 5; i++)
    {
        Person d;
    }
    int test2_created = a.getCreatedPersons();
    int test2_living = a.getLivingPersons();
    if(test2_created != 8 || test2_living != 3) {
        cerr << "Failed test2!\n";
    } else {
        cout << "Passed test2!\n";
    }
    

    cout << "Finished tests!\n";
    return 0;
}
