# Details about program:
1. InitSysCtrl()
   - Initializes system functions like setting system clock frequency using PLL, enable clock to CPU, GPIO and disable watchdog by default
2. DINT - disables global interrupts
   - IER: Interrupt Enable Register cleared to clear all sources of interrupts
   - IFR: Interrupt Flag Register cleared to clear all pending flag interrupts
   All this ensures clean interrupt state
3. InitGPIO()
   - Resets all GPIOs to default state before configuring specific GPIO
4. EALLOW (Enable Access to protected register)
   - registers further used are protected and hence this step is required for writing to them
   - required before modifying MUX and DIR
5. GpioCtrlRegs.GPADIR.bit.GPIO14 = 1 sets GPIO14 as output pin
   - GPADIR controls direction that is input or output for particular GPIO
   - 0 = input, 1 = output
6. GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0 sets GPIO14 as GPIO pin
   - GPIO pins have other functionalities like SPI, PWM etc
   - GPAMUX1 is responsible for controlling GPIO0-15 and setting it to 0 marks its function as GPIO
7. EDIS (Disable Access to protected register)
   - disabling access to protected registers is necessary after configuration to prevent unintended changes
8. GpioDataRegs.GPATOGGLE.bit.GPIO14 = 1
   - toggles GPIO14, that is turns LED on->off->on
