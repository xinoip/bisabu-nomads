#ifndef PString_h
#define PString_h

#include <iostream>

class PString
{
public:
    PString();
    PString(char c);
    PString(const char *c);
    PString(const PString &s);
    ~PString();

    size_t length() const;
    int indexOf(char c) const;

    void toUpperCase();
    void toUpperCase(unsigned first);
    void toUpperCase(unsigned first, unsigned last);
    void toLowerCase();
    void toLowerCase(unsigned first);
    void toLowerCase(unsigned first, unsigned last);
    void toggleCase();
    void toggleCase(unsigned first);
    void toggleCase(unsigned first, unsigned last);

    friend std::ostream &operator<<(std::ostream &so, const PString &s);
    friend std::istream &operator>>(std::istream &so, PString &s);

    // interesting...
    char operator()(unsigned i) const;
    char &operator()(unsigned i);

    PString &operator=(const PString &s);
    PString &operator+=(const PString &s);

    friend PString operator+(const PString &lhs, const PString &rhs);
    friend PString operator+(const PString &lhs, char rhs);
    friend PString operator+(const PString &lhs, const char *rhs);
    friend PString operator+(char lhs, const PString &rhs);
    friend PString operator+(const char *lhs, const PString &rhs);

    friend bool operator==(const PString &lhs, const PString &rhs);
    friend bool operator==(const PString &lhs, char rhs);
    friend bool operator==(const PString &lhs, const char *rhs);
    friend bool operator==(char lhs, const PString &rhs);
    friend bool operator==(const char *lhs, const PString &rhs);

    friend bool operator>(const PString &lhs, const PString &rhs);
    friend bool operator>(const PString &lhs, char rhs);
    friend bool operator>(const PString &lhs, const char *rhs);
    friend bool operator>(char lhs, const PString &rhs);
    friend bool operator>(const char *lhs, const PString &rhs);

    friend bool operator!=(const PString &lhs, const PString &rhs);
    friend bool operator!=(const PString &lhs, char rhs);
    friend bool operator!=(const PString &lhs, const char *rhs);
    friend bool operator!=(char lhs, const PString &rhs);
    friend bool operator!=(const char *lhs, const PString &rhs);

    friend bool operator<(const PString &lhs, const PString &rhs);
    friend bool operator<(const PString &lhs, char rhs);
    friend bool operator<(const PString &lhs, const char *rhs);
    friend bool operator<(char lhs, const PString &rhs);
    friend bool operator<(const char *lhs, const PString &rhs);

    friend bool operator<=(const PString &lhs, const PString &rhs);
    friend bool operator<=(const PString &lhs, char rhs);
    friend bool operator<=(const PString &lhs, const char *rhs);
    friend bool operator<=(char lhs, const PString &rhs);
    friend bool operator<=(const char *lhs, const PString &rhs);

    friend bool operator>=(const PString &lhs, const PString &rhs);
    friend bool operator>=(const PString &lhs, char rhs);
    friend bool operator>=(const PString &lhs, const char *rhs);
    friend bool operator>=(char lhs, const PString &rhs);
    friend bool operator>=(const char *lhs, const PString &rhs);

private:
    char *data;
    size_t size;
};

#endif