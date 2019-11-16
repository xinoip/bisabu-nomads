#ifndef _Adder_h_
#define _Adder_h_

#include <iostream>
#include <string>

namespace pio
{
namespace util
{
class Adder
{
private:
    Adder();
    ~Adder();

public:
    static int Add(int a, int b);
};
} // namespace util
} // namespace pio

#endif