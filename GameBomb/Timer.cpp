#include "GameBomb.h"
int hours1 = 0;
int minutes1 = 0;
int seconds1 = 0;

// function to display the timer
void displayClock()
{
    // system call to clear the screen
    

    cout << setfill(' ') << setw(55) << "         TIMER         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << "| " << setfill('0') << setw(2) << hours1 << " hrs | ";
    cout << setfill('0') << setw(2) << minutes1 << " min | ";
    cout << setfill('0') << setw(2) << seconds1 << " sec |" << endl;
    cout << setfill(' ') << setw(55) << " --------------------------\n";
}

void timer()
{
    // infinite loop because timer will keep
    // counting. To kill the process press
    // Ctrl+D. If it does not work ask
    // ubuntu for other ways.
    while (true) {

        // display the timer
        displayClock();

        // sleep system call to sleep
        // for 1 second
        Sleep(1000);

        // increment seconds
        seconds1++;

        // if seconds reaches 60
        if (seconds1 == 60) {

            // increment minutes
            minutes1++;

            // if minutes reaches 60
            if (minutes1 == 60) {

                // increment hours
                hours1++;
                minutes1 = 0;
            }
            seconds1 = 0;
        }
    }
}