#include "PString.h"

int main()
{
  PString a;
  a = "Foo";
  std::cout << a << std::endl;

  PString b('T');
  std::cout << b << std::endl;

  PString c("abcde");
  std::cout << c << std::endl;

  PString copyOfC(c);
  std::cout << copyOfC << std::endl;

  PString myString("Bugra eren yilmaz");
  std::cout << myString << std::endl;

  myString.toUpperCase(0, myString.length());
  std::cout << "Uppercase: " << myString << std::endl;

  myString.toLowerCase(3, 6);
  std::cout << "Lowercased 3 to 6: " << myString << std::endl;

  myString.toggleCase(0, myString.length());
  std::cout << "Toggledcase: " << myString << std::endl;

  std::cout << "Char at 4: " << myString(4) << std::endl;

  myString = "Abdullah Kusgulu";
  std::cout << myString << std::endl;

  myString += " king";
  std::cout << myString << std::endl;

  PString inputMe;
  std::cin >> inputMe;
  std::cout << inputMe << std::endl;

  return 0;
}
