#include <iostream>
#include <vector>

typedef std::vector<std::pair<std::string, int>> pairlist_t;
typedef std::string string_t;
typedef int number_t;
using text_t = std::string;

int main(){
    using std::cout;

    // typedef  =   reserved keyword used to create an additional name
    //              (alias) for another data type.
    //              New identifier for an existing type
    //              Helps with readability and reduces typos
    //              Use when there is a clear benefit
    //              Replaced with 'using' (works better w/ templates)

    pairlist_t pairlist;
    
    string_t firstName = "Bro";
    cout << firstName << std::endl;

    number_t age = 38;
    cout << age << '\n';

    text_t lastName = "Code";
    cout << lastName << '\n';

    return 0;
}