#include <iostream>
#include <unistd.h>
#include <SFML/Audio.hpp>

int main() {
    //This is the intager that stores the users input
    int input;

    //This is the audio file that plays when the timer is up
    sf::Music music;
    if (!music.openFromFile("../files/sound.wav"))
        //TODO this error triggers due to a permission error but it works anyway :/?  
        std::cout << "This error sometimes triggers due to a harmless permission error?!.. If it triggers for another reason well your fucked I guess :D";

    while(1) {
        //Clears screen
        std::cout << "\x1B[2J\x1B[H";

        //Asks the user what they would like to do
        std::cout << "\nHow long would you want to take a break for or work for?\n\n1. Work for 25 mins\n2. Take a break for 5 mins\n3. Take a break for 10 mins\n\n:";
        std::cin >> input;
        
        //Checks the Input starting with 3 since we all know you are lazy
        if(input == 3) {
            std::cout << "\nTaking a break for 10 mins\n";
            sleep(600);
            std::cout << "Time is up!\n";
            music.play();
            sleep(10);
            music.stop();

        } else if (input == 2) {
            std::cout << "\nTaking a break for 5 mins\n";
            sleep(300);
            std::cout << "Time is up!\n";
            music.play();
            sleep(10);
            music.stop();
        
        //Note invaild input will trigger this
        } else {
            std::cout << "\nWorking for 25 mins\n";
            sleep(1500);
            std::cout << "Time is up!\n";
            music.play();
            sleep(10);
            music.stop();
        }
    }
}
