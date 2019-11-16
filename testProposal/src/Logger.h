#ifndef _Logger_h_
#define _Logger_h_

#include <iostream>
#include <string>

namespace pio
{
namespace util
{
class Logger
{
private:
    Logger();
    ~Logger();

public:
    static void Log(std::string message);
};
} // namespace util
} // namespace pio

#endif