#include <iostream>
#include <unistd.h>
#include <SFML/Audio.hpp>

//This sleeps for time_wait then plays sound
void play_sound_after(int time_wait, sf::Music& sound)
{
	std::cout << "Started timer" << std::endl;
	sleep(time_wait);
	sound.play();
    std::cin.clear();
    std::cin.ignore ( 1024, '\n' );
    std::cout << "Time up!\n";
    sleep(3);
	sound.stop();
}

int main() {
    //This is the intager that stores the users input
    int input;

    //This is the audio file that plays when the timer is up
    sf::Music sound;
    if (!sound.openFromFile("./files/sound.wav")) 
    {
        std::cout << "Could not load audio file";
        return -1;
    }

    while(1) 
    {
        //Clears screen
        std::cout << "\x1B[2J\x1B[H";

        //Asks the user what they would like to do
		std::cout << "How long would you want to take a break for or work for?" << std::endl << std::endl;

		std::cout << "1. Work for 25 mins"         << std::endl;
		std::cout << "2. Take a break for 5 mins"  << std::endl;
		std::cout << "3. Take a break for 10 mins" << std::endl << std::endl;

        std::cout << ":";
        std::cin >> input;
        
        //Checks the Input starting with 3 since we all know you are lazy
        if(input == 3) 
        {
            std::cout << "\nTaking a break for 10 mins\n";
            play_sound_after(600, sound);

        } 
        
        else if (input == 2) 
        {
            std::cout << "\nTaking a break for 5 mins\n";
            //play_sound_after(1, sound); <-- this is for testing
            play_sound_after(300, sound);
            
        } 
        
        else if (input == 1) 
        {
            std::cout << "\nWorking for 25 mins\n";
            play_sound_after(1500, sound);
        }
        
        else 
        {
            std::cin.clear();
            std::cin.ignore ( 1024, '\n' );
            std::cout << "Invaild input!\n";
            sleep(1);
        }
    }
    return 0;
}
