#ifndef _Test_h_
#define _Test_h_

#include <iostream>
#include <string>

class Test
{
public:
    Test(bool (*testPtr)(), std::string name = "unnamed");

    bool run();

private:
    std::string name;
    bool (*testPtr)();
    bool result;
};

#endif