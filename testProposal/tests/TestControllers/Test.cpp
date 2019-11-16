#include "Test.h"

Test::Test(bool (*testPtr)(), std::string name)
{
    this->testPtr = testPtr;
    this->name = name;
}

bool Test::run()
{
    std::cout << "\nDoing>> " << name << "\n";
    std::cout << "-----------------------" << std::endl;

    result = testPtr();

    std::cout << "\n - Result: ";    
    if(result) {
        std::cout << "PASSED";
    } else {
        std::cout << "FAILED";
    }
    std::cout << " -" << std::endl;

    return result;
}