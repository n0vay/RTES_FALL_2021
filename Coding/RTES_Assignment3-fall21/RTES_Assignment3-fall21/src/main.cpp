/*
* Project:    Assignment3
* File:       main.cpp
* Author(s):  Michael Thoreau, Chris Piekarski
*/

#include <mbed.h>

//References
// PwmOut https://os.mbed.com/docs/mbed-os/v6.9/apis/pwmout.html
// AnalogIn https://os.mbed.com/docs/mbed-os/v6.15/apis/i-o-apis.html


/*	Signal Graphing
*	In this exercise you must utilize a timer/ticker to monitor the Analog ADC pins and sample their values.
*	Set up PB_0 for PwmOut and set up PB_1 for AnalogIn. Initiate a PWM signal of 1Hz with a 20% duty cycle on PB_0.
*	When sampling, you must short the pins PB_0 and PB_1. One method is to utilize jumper JP2 that comes with your board!
*	For this task, you will sample the ADC for 5 seconds at 500 samples/second. Store your samples in a buffer and then output the buffer to the terminal.
*	From the terminal, record and graph your collected data in either Matlab or Python (Using matplotlib libraries)
*	and submit the resulting graph as a jpg/png as part of this assignment. Remember to label the x & y axis correctly.
* you must be able to show that the frequency of the square wave is as expected
*/

// recommended steps:
// create a PWMOut on PB_0
// create a ticker to read from the an AnalogIn on PB_1
// set up a way to write to a buffer in the ticker callback
// output values in the main loop

int main() {

	while (1) {

	}

}







