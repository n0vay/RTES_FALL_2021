# Real Time Embedded Systems
### Programming Assignment 3 - ADC/Timers

<br />

In this assignment you will experiment with the ADC and various capabilities with the Timer integrated into the microprocessor.
The ADC (Analog-Digital Converter) is used to capture real-time voltage measures in the real world and is able to translate it into a digital signal that can be understood by code.
Timers are also used extensively for critical timing applications such as creating waveforms or setting up communication standards between systems.

The assignment will be graded according to the following criteria:

| Part        | Grade       |
| ------------| ----------- |
| 1           | 100%         |




### Instructions

Create a new project in platformIO as demonstrated in class. Copy the code from main.c in this repository to your project and modify to complete each part. Submit your main.c and either a .png or .jpg showing the analog voltages from the extension component all together in a zip file.


<br />

---

<br />


**FAQ**

**My code gets stuck at:**   `serial = new USBSerial()`

You have to plug in a second usb cable to use the USBSerial interface. See these [Instructions](tutorials/USBSerial.md).


<br />


**My code no longer appears to run when connected to an external power source?**

This is caused by a firmware bug in the st-link controller on the board. Follow these [Instructions on Updating the Firmware](tutorials/firmware.md) on your board.

<br />

**I'm not seeing any data from printf()?**

Make sure to follow all the instructions [here](tutorials/USBSerial.md).

<br />

**I have another question/issue?**

Contact a the professor or a TA, one place to start: mjt9978@nyu.edu
