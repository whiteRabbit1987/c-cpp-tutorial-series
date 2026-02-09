#include <iostream>

// Namespace  = provides a solution for preventing name conflicts
//              in large projects. Each entity needs a unique name.
//              A namespace allows for identically named entities
//              as long as the namespaces are different.

// using namespace std;
// int main(void) {
//   cout << "It's working\n" << endl;
// }

namespace first{
  int x = 1;
}

namespace second{
  int x = 2;
}

int main(){
  using std::cout;
  int x = 0;
  
  cout << x << '\n';
  cout << first::x << '\n';
  cout << second::x << '\n';

  return 0;
}