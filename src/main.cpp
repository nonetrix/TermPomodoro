#include <iostream>
#include <unistd.h>
#include <SFML/Audio.hpp>

//This sleeps for time_wait then plays sound it also now converts time_wait to minutes and seconds 
void play_sound_after(int time_wait, sf::Music& sound)
{
    while (time_wait >= 1)
    {
        std::cout << "\x1B[2J\x1B[H";
        //TODO if the seconds go below 10 it prints something like 10:9 when it should really print 10:09 but it works I guess..
        std::cout << "Time remaining: " << time_wait / 60 << ":" << time_wait % 60 << std::endl;
        sleep(1);
        time_wait--;
    }
    sound.play();
    std::cin.clear();
    std::cin.ignore ( 1024, '\n' );
    std::cout << "Time up!" << std::endl;
    sleep(3);
    sound.stop();
}

int main() {
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
            default:
                std::cin.clear();
                std::cin.ignore ( 1024, '\n' );
                std::cout << "Invaild input!" << std::endl;
                sleep(1);
                break;
        }
    }
    return 0;
}

