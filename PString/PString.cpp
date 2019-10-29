#include "PString.h"

PString::PString()
{
    size = 0;
    data = new char[size];
}

PString::PString(char c)
{
    size = 1;
    data = new char(c);
}

PString::PString(const char *c)
{
    if (c)
    {
        unsigned n = 0;
        while (c[n] != '\0')
            n++;
        size = n;
        data = new char[n];
        for (unsigned i = 0; i < size; i++)
            data[i] = c[i];
    }
    else
    {
        size = 0;
        data = new char[size];
    }
}

PString::PString(const PString &s)
{
    size = s.length();
    data = new char[size];
    for (unsigned i = 0; i < size; i++)
        data[i] = s(i);
}

PString::~PString()
{
    delete[] data;
}

size_t PString::length() const
{
    return size;
}

int PString::indexOf(char c) const
{
    for (unsigned i = 0; i < size; i++)
    {
        if (data[i] == c)
            return (int)i;
    }
    return -1;
}

PString PString::subString(unsigned first)
{
    
}

PString PString::subString(unsigned first, unsigned last)
{
    if ((first >= last) || last > size)
        throw 1;
    
    PString rtr;
    
    rtr.size = last - first - 1;
    char *newData = new char[rtr.size];

    for (unsigned i = first, j = 0; i < last; i++, j++)
    {
        newData[j] = data[i];
    }
    rtr.data = newData;
    return rtr;
}

void PString::toUpperCase() {}
void PString::toUpperCase(unsigned first) {}
void PString::toUpperCase(unsigned first, unsigned last)
{
    if ((first >= last) || last > size)
        throw 1;

    for (unsigned i = first; i < last; i++)
    {
        if ('a' <= data[i] && data[i] <= 'z')
            data[i] -= ('a' - 'A');
    }
}
void PString::toLowerCase() {}
void PString::toLowerCase(unsigned first) {}
void PString::toLowerCase(unsigned first, unsigned last)
{
    if ((first >= last) || last > size)
        throw 1;

    for (unsigned i = first; i < last; i++)
    {
        if ('A' <= data[i] && data[i] <= 'Z')
            data[i] += ('a' - 'A');
    }
}
void PString::toggleCase() {}
void PString::toggleCase(unsigned first) {}
void PString::toggleCase(unsigned first, unsigned last)
{
    if ((first >= last) || last > size)
        throw 1;

    for (unsigned i = first; i < last; i++)
    {
        if ('A' <= data[i] && data[i] <= 'Z')
            data[i] += ('a' - 'A');
        else if ('a' <= data[i] && data[i] <= 'z')
            data[i] -= ('a' - 'A');
    }
}

std::ostream &operator<<(std::ostream &so, const PString &s)
{
    if (s.length() > 0)
    {
        for (unsigned i = 0; i < s.length(); i++)
            so << s(i);
    }
    else
        so << "";

    return so;
}

std::istream &operator>>(std::istream &so, PString &s)
{
    char *c = new char[1000];
    so >> c;
    s = PString(c);
    delete[] c;

    return so;
}

// interesting...
char PString::operator()(unsigned i) const
{
    if (i >= size)
        throw 1;
    return data[i];
}

// verrry interesting...
char &PString::operator()(unsigned i)
{
    if (i >= size)
        throw 1;
    return data[i];
}

PString &PString::operator=(const PString &s)
{
    if (this == &s)
        return *this;

    delete data;
    size = s.length();
    data = new char[size];
    for (unsigned i = 0; i < size; i++)
        data[i] = s(i);
    return *this;
}

PString &PString::operator+=(const PString &s)
{
    unsigned len = size + s.length();
    char *str = new char[len];

    for (unsigned i = 0; i < size; i++)
        str[i] = data[i];

    for (unsigned i = 0; i < s.length(); i++)
        str[size + i] = s(i);

    delete data;
    size = len;
    data = str;
    return *this;
}

PString operator+(const PString &lhs, const PString &rhs)
{
    return PString(lhs) += rhs;
}

PString operator+(const PString &lhs, char rhs)
{
    return PString(lhs) += PString(rhs);
}

PString operator+(const PString &lhs, const char *rhs)
{
    return PString(lhs) += PString(rhs);
}

PString operator+(char lhs, const PString &rhs)
{
    return PString(lhs) += rhs;
}

PString operator+(const char *lhs, const PString &rhs)
{
    return PString(lhs) += rhs;
}

bool operator==(const PString &lhs, const PString &rhs)
{
    if (lhs.length() != rhs.length())
        return false;

    unsigned cap = lhs.length();
    unsigned n = 0;
    while (n < cap && lhs(n) == rhs(n))
    {
        n++;
    }
    return n == cap;
}

bool operator==(const PString &lhs, char rhs)
{
    return lhs == PString(rhs);
}

bool operator==(const PString &lhs, const char *rhs)
{
    return lhs == PString(rhs);
}

bool operator==(char lhs, const PString &rhs)
{
    return PString(lhs) == rhs;
}

bool operator==(const char *lhs, const PString &rhs)
{
    return PString(lhs) == rhs;
}

bool operator>(const PString &lhs, const PString &rhs)
{
    unsigned cap = lhs.length() < rhs.length() ? lhs.length() : rhs.length();
    unsigned n = 0;
    while (n < cap && lhs(n) == rhs(n))
    {
        n++;
    }
    if (n == cap)
        return lhs.length() > rhs.length();

    return lhs(n) > rhs(n);
}

bool operator>(const PString &lhs, char rhs)
{
    return lhs > PString(rhs);
}

bool operator>(const PString &lhs, const char *rhs)
{
    return lhs > PString(rhs);
}

bool operator>(char lhs, const PString &rhs)
{
    return PString(lhs) > rhs;
}

bool operator>(const char *lhs, const PString &rhs)
{
    return PString(lhs) > rhs;
}

bool operator!=(const PString &lhs, const PString &rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const PString &lhs, char rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const PString &lhs, const char *rhs)
{
    return !(lhs == rhs);
}

bool operator!=(char lhs, const PString &rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const char *lhs, const PString &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const PString &lhs, const PString &rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator<(const PString &lhs, char rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator<(const PString &lhs, const char *rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator<(char lhs, const PString &rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator<(const char *lhs, const PString &rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator<=(const PString &lhs, const PString &rhs)
{
    return !(lhs > rhs);
}

bool operator<=(const PString &lhs, char rhs)
{
    return !(lhs > rhs);
}

bool operator<=(const PString &lhs, const char *rhs)
{
    return !(lhs > rhs);
}

bool operator<=(char lhs, const PString &rhs)
{
    return !(lhs > rhs);
}

bool operator<=(const char *lhs, const PString &rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const PString &lhs, const PString &rhs)
{
    return !(lhs < rhs);
}

bool operator>=(const PString &lhs, char rhs)
{
    return !(lhs < rhs);
}

bool operator>=(const PString &lhs, const char *rhs)
{
    return !(lhs < rhs);
}

bool operator>=(char lhs, const PString &rhs)
{
    return !(lhs < rhs);
}

bool operator>=(const char *lhs, const PString &rhs)
{
    return !(lhs < rhs);
}