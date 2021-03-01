#include <3ds.h>
#include <unistd.h>
#include <iostream>


void PRINT_WELCOME() {
    std::cout << "\x1B[2J\x1B[H";

    std::cout << "Select a option" << std::endl << std::endl;

    std::cout << "Work for 25 mins(A)"         << std::endl;
    std::cout << "Take a break for 5 mins(B)"  << std::endl;
    std::cout << "Take a break for 10 mins(X)" << std::endl;
    std::cout << "\nQuit(START)" << std::endl << std::endl;
}

void wait(int time_wait)
{
    int time_sec;
    while (time_wait >= 1)
    {
        //Clears the screen
        std::cout << "\x1B[2J\x1B[H";

        time_sec = time_wait % 60;
        
        //prints a extra 0 if seconds is equal to something like 9
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
    std::cout << "time is up!" << std::endl;
    sleep(2);
    PRINT_WELCOME();
}

int main(int argc, char **argv)
{
	gfxInitDefault();

	//Initialize console on top screen. Using NULL as the second argument tells the console library to use the internal console structure as current one
	consoleInit(GFX_TOP, NULL);
    PRINT_WELCOME();



	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs.
		hidScanInput();

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break; // break in order to return to hbmenu
		
		else if (kDown & KEY_A) 
        {
            std::cout << "Working for 25 mins" << std::endl;
            sleep(2);
            wait(1500);
        }
        
        else if (kDown & KEY_B) 
        {
            std::cout << "Taking a break for 5 mins" << std::endl;
            sleep(2);
            wait(300);
        }
        
        else if (kDown & KEY_X) 
        {
            std::cout << "Taking a break for 10 mins" << std::endl;
            sleep(2);
            wait(600);
        }
        
        
		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();

		//Wait for VBlank
		gspWaitForVBlank();
	}
	gfxExit();
	return 0;
}
