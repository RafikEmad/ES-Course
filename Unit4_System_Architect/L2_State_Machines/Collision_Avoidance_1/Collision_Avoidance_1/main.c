#include "CA.h"

void setup()
{
    //init all the drivers
    //init IRQ...
    //init HAL US_Driver DC_Driver
    //init BLOCK
    //set state pointers for each block
    CA_state = STATE(CA_waiting);
}
void main()
{
    setup();
    while (1)
    {
        //call state for each block
        CA_state();
    }
}