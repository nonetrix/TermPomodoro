#include <iostream>
#include <unistd.h>
#include <SFML/Audio.hpp>

sf::Music sound;
static bool initialized;
int input;


//This takes time_wait then sleeps for that amout of time then plays sound
void wait_for(int time_wait) {
    //This is to avoid running the code more than once wasting cpu
    if (!initialized) {
    initialized = true;
    //this is the sound played when time_wait is over
    if (!sound.openFromFile("./files/sound.wav")) {
        std::cout << "Couldn't load sound";
    }
}

    std::cout << "Started timer\n";
    sleep(time_wait);
    std::cout << "Press enter\n";
    sound.play();
    //This only works if you run std::cin.ignore(); twice.. Sigh
    std::cin.ignore();
    std::cin.ignore();
    sound.stop();
}

int main() {
    while(1) {
        //Clears screen
        std::cout << "\x1B[2J\x1B[H";

        //Asks the user what to do
        std::cout << "\nHow long would you want to take a break for or work for?\n\n1. Work for 25 mins\n2. Take a break for 5 mins\n3. Take a break for 10 mins\n\n:";
        std::cin >> input;
        
        //Checks the Input starting with 3 since we all know you are lazy and will pick 3
        if(input == 3) {
            wait_for(600);
        }

        else if (input == 2) {
            //wait_for(300);
            wait_for(1);
        }
        else if (input == 1) {
            wait_for(1500);
        }
        else {
            std::cout << "Invalid input press enter";
        }
    }
}
