#include "Test.h"

class TestController {
public:
    Test arr[5];
    void pushTest(const Test &test);
    unsigned lastIndex = 0;
    void startTests();
};