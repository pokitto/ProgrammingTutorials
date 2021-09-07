#include "Pokitto.h"

// the pokitto core library
Pokitto::Core pokitto;

// create a 'DigitalOut' object to represent
// the digital output pin used to communicated with the LED
// the object is set to use the EXT0 pin for output
DigitalOut led0 = DigitalOut(EXT0);

int main ()
{
    // initialise the Pokitto
    pokitto.begin();

    // the main loop
    while (pokitto.isRunning())
    {
        // update the Pokitto's state
        if (pokitto.update())
        {
            pokitto.display.color=led0+1;
            pokitto.display.setCursor(0,0);
            pokitto.display.print("Press A/B\n");
            if (led0==0) pokitto.display.print("Led ON");
            else pokitto.display.print("Led OFF");

            // if the A button is pressed
            if(pokitto.buttons.aBtn())
            {
                // send a high signal to turn the LED on
                led0.write(1);
            }

            // if the B button is pressed
            if(pokitto.buttons.bBtn())
            {
                // send a low signal to turn the LED off
                led0.write(0);
            }
        }
    }

    return 1;
}