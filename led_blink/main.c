#include "F28x_Project.h"  // Includes device header and delay macro

void main(void)
{
    // Step 1: Initialize system
    InitSysCtrl();  // Sets up system clock and disables watchdog

    // Step 2: Disable interrupts
    DINT;
    IER = 0x0000;
    IFR = 0x0000;

    // Step 3: Initialize GPIO
    InitGpio();  // Initializes all pins as GPIO

    EALLOW; // Allow protected register access
    GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;   // Set GPIO31 as output
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0;  // Set GPIO31 as GPIO
    EDIS;   // Disable protected register access

    // Step 4: Infinite loop to blink LED
    while(1)
    {
        GpioDataRegs.GPATOGGLE.bit.GPIO14 = 1;  // Toggle LED
        DELAY_US(500000);  // Delay 500 ms (0.5 second)
    }
}
