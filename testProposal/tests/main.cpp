#include "TestDictionary.h"
#include "TestControllers/Test.h"

int main()
{
    Test testsArr[TEST_COUNT] = {
        LoggerTest(),
        AdderTest(),
    };

    unsigned passedTests = 0;

    for (unsigned i = 0; i < TEST_COUNT; i++)
    {
        bool success = testsArr[i].run();
        if (success)
        {
            passedTests++;
        }
    }

    std::cout << "\n\nTest results: " << passedTests << "/" << TEST_COUNT << "\n";

    if (passedTests == TEST_COUNT)
    {
        std::cout << "Passed all of the " << TEST_COUNT << " tests." << std::endl;
    }
    else
    {
        std::cout << "Failed " << TEST_COUNT - passedTests << " tests." << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
