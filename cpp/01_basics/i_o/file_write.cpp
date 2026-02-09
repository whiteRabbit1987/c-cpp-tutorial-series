#include <iostream>
#include <fstream>
#include <string>

// ofsream object       =   links a file on disk (example.txt) to the program
//                          for output (writing). It requires the <fstream> header.
//                          Creates the file if it doesn't exist, and overwrites existing content.

// is_open()        =   checks if the file was successfully opened and is ready for writing.
//                      Writing should only proceed if this check is true.

// << operator      =   the insertion operator used to send data (strings, numbers, etc.)
//                      from the program into the file stream (outputFile).

// close()          =   releases the file resource when writing is complete, ensuring all
//                      buffered data is physically saved to the disk.

int main(){

    std::ofstream outputFile("example.txt");
    std::string textToWrite[] = {
                                    "C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do, it blows your whole leg off.", 
                                    "Premature optimization is the root of all evil.", 
                                    "The world doesn't need another game engine. It needs better games.", 
                                    "Focus on the simplest thing that could possibly work.", 
                                    "Software is like sex: it’s better when it’s free."};

    if(outputFile.is_open()){
        for(std::string text : textToWrite){
            outputFile << text << '\n';
        }
        outputFile.close();
        std::cout << "Data successfully written to example.txt\n";
    } else {
        std::cerr << "Error: Unable to open file 'output.txt' for writing.\n";
    }

    return 0;
}