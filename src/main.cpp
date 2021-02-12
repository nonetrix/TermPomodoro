#include <iostream>
#include <unistd.h>
#include <SFML/Audio.hpp>

//This sleeps for a given amount of seconds and prints the remaining time untill sleep is over 
void play_sound_after(int time_wait, sf::Music& sound)
{
    int time_sec;
    while (time_wait >= 1)
    {
        //Clears the screen
        std::cout << "\x1B[2J\x1B[H";

        time_sec = time_wait % 60;
        if (time_sec <= 9) 
        {
            std::cout << "Time remaining: " << time_wait / 60 << ":" << "0" << time_sec << std::endl;
        }
        else 
        {
            std::cout << "Time remaining: " << time_wait / 60 << ":" << time_sec << std::endl;
        }
        sleep(1);
        time_wait--;
    }
    sound.play();

    //This is to stop a never ending loop
    std::cin.clear();
    std::cin.ignore ( 1024, '\n' );

    std::cout << "Time up!" << std::endl;
    sleep(3);
    sound.stop();
}

int main() {
    int input;
    //This loads a audio file
    sf::Music sound;
    if (!sound.openFromFile("./files/sound.wav")) 
    {
        std::cout << "Could not load audio file";
        return(-1);
    }

    while(1) 
    {
        //Clears the screen
        std::cout << "\x1B[2J\x1B[H";

        std::cout << "How long would you want to take a break for or work for?" << std::endl << std::endl;

        std::cout << "1. Work for 25 mins"         << std::endl;
        std::cout << "2. Take a break for 5 mins"  << std::endl;
        std::cout << "3. Take a break for 10 mins" << std::endl;
        std::cout << "4. quit" << std::endl << std::endl;

        std::cout << ":";
        std::cin >> input;
        
        switch(input) {
            case 3:
                std::cout << "Taking a break for 10 mins" << std::endl;
                play_sound_after(600, sound);
                break;
            case 2:
                std::cout << "Taking a break for 5 mins" << std::endl;
                play_sound_after(300, sound);
                break;
            case 1:
                std::cout << "Working for 25 mins" << std::endl;
                play_sound_after(1500, sound);
                break;
            case 4:
                return(0);
                break;
            default:
                //This is to stop a never ending loop
                std::cin.clear();
                std::cin.ignore ( 1024, '\n' );
                std::cout << "Invaild input!" << std::endl;
                sleep(1);
                break;
        }
    }
    return(0);
}
