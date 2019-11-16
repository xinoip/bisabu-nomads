#include "TestDictionary.h"
#include "TestControllers/Test.h"

#include "../src/Adder.h"

Test AdderTest()
{
    return Test([]() {
        bool success = false;
        int dummy1 = 5;
        int dummy2 = 4;

        int res = pio::util::Adder::Add(dummy1, dummy2);
        success = (res == 9);

        return success;
    }, "AdderTest");
}
