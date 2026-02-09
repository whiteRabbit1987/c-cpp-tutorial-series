#include <iostream>
#include <fstream>
#include <string>

// ifstream object  =   links a file on disk (example.txt) to the program
//                      for input. It requires the <fstream> header

// is_open()        =   checks if the file was successfully found and opened.
//                      Reading should only proceed if this check is true.

// std::getline()   =   reads an entire line of text from the file stream (inputFile)
//                      into the string variable (line). The loop continues until the 
//                      End Of File (EOF) is reached.

// close()          =   releases the file resource when reading is complete.

int main(){

    std::ifstream inputFile("example.txt");
    std::string line;

    if(inputFile.is_open()){

        while(std::getline(inputFile, line)){
            std::cout << line << '\n';
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file 'example.txt'\n";
    }

    return 0;
}