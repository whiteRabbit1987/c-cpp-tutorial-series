#include <iostream>
#include <string>

using namespace std;

// string size & memory control = functions that manage string length and allocated memory
// common methods              = .size()  .length()  .capacity()  .resize()  .reserve()  .clear()  .empty()
// size()/length()             = number of characters currently in the string
// capacity()                  = allocated storage (may be larger than size)
// resize(n)                   = changes the string length
// resize(n, ch)               = expands string and fills new characters with ch
// reserve(n)                  = pre-allocates memory WITHOUT changing string size
// clear()                     = removes all characters (size becomes 0)
// empty()                     = returns true if size == 0

void print_info(string & s) {
  cout << "content =\"" << s << "\" ";
  cout << "capacity = " << s.capacity() << endl;
  cout << "is empty? " << (s.empty() ? "yes" : "no") << endl;
  cout << "---------" << endl;
}

int main(void) {
  string the_string = "content";

  // initial string state
  print_info(the_string);

  // reserve memory ahead of time (no change to content or size)
  the_string.reserve(100);
  print_info(the_string);

  // expand string size and fill new characters
  the_string.resize(50, '?');
  print_info(the_string);

  // shrink string to first 4 characters
  the_string.resize(4);
  print_info(the_string);

  // remove all characters (capacity usually remains unchanged)
  the_string.clear();
  print_info(the_string);

  return 0;
}
