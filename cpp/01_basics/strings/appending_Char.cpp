#include <iostream>
#include <string>

int main() {

  std::string alphabet;
  for(char c = 'A'; c <= 'Z'; c++){
    alphabet.push_back(c);
  }

  std::cout << alphabet;

  return 0;
}