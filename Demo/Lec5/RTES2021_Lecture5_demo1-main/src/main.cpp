
#include "mbed.h"
 
SPI spi(PF_9, PF_8, PF_7); // mosi, miso, sclk
DigitalOut cs(PC_1);

// Documents
// Manual for dev board: https://www.st.com/resource/en/user_manual/um1670-discovery-kit-with-stm32f429zi-mcu-stmicroelectronics.pdf
// gyroscope datasheet: https://www.mouser.com/datasheet/2/389/dm00168691-1798633.pdf

// Read a register on the gyroscope
int main() {
    // Chip must be deselected
    cs = 1;
 
    // Setup the spi for 8 bit data, high steady state clock,
    // second edge capture, with a 1MHz clock rate
    spi.format(8,3);
    spi.frequency(1000000);
 
    while (1) {
    
      // Select the device by seting chip select low
      cs = 0;
  
      // Send 0x8f, the command to read the WHOAMI register
      spi.write(0x8F);
  
      // Send a dummy byte to receive the contents of the WHOAMI register
      int whoami = spi.write(0x00);
      printf("WHOAMI register = 0x%X\n", whoami);
  
      // Deselect the device
      cs = 1;

      wait_us(1000000);

    }
}
