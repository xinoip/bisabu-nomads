#include "TestDictionary.h"
#include "TestControllers/Test.h"

#include "../src/Logger.h"

Test LoggerTest()
{
    return Test([]() {
        bool success = false;

        pio::util::Logger::Log("ABC");
        success = true;

        return success;
    }, "LoggerTest");
}
