#include <iostream>
#include <stack>
#include <string>

std::string reverseString(const std::string &input){
    // initalize stack and assing input message contents
    std::stack<char> charStack;
    for(char c : input){
        charStack.push(c);
    }

    //initalize return string and assign stack contents in reverse
    std::string toReturn;
    while(!charStack.empty()){
        toReturn.push_back(charStack.top());
        // or toReturn += charStack.top()
        charStack.pop();
    }

    return toReturn;
};

int main(){

    std::string message;
    std::cout << "Please enter text to be reversed: " << std::flush;
    std::getline(std::cin, message);

    std::string reversedText = reverseString(message);

    std::cout << "The original text is: " << message << std::endl;
    std::cout << "The reversed text is: " << reversedText << std::endl;

    return 0;
}