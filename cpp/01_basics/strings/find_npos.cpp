#include <iostream>
#include <string>

// string searching = functions built into std::string for locating text inside other text
// common methods   = .find()  .rfind()  .npos
// .find()          = returns the index where the substring starts
//                    returns std::string::npos if the substring is NOT found
// npos             = special value meaning "no position" (not found)

int main() {

  std::string full_string = "Never trust a fart!";
  std::string partial_string = "fart";

  if(full_string.find(partial_string) != std::string::npos){
    std::cout << "Found the string!\n" << full_string.find(partial_string) << std::endl;
  } else {
    std::cout << "Could NOT find the string!";
  }

  return 0;
}