#include <iostream>
#include <string>

int player_position = 0;

int main(){
    
    bool is_running = true;

    while(is_running){

        std::string user_input = "";
        std::cout << "Enter 'e' to move right 'w' to move left or 'quit' to exit.\n";
        std::getline(std::cin, user_input);

        if(user_input == "quit"){
            is_running = false;
            std::cout << "Exiting.....";
            continue;
        } 

        if(user_input == "w"){
            player_position++;
        } else if (user_input == "e"){
            player_position--;
        } else {
            std::cout << "Invalid input!\n";
            continue;
        }

        std::cout << "Player at position: " << player_position << std::endl;
    }



    return 0;
}