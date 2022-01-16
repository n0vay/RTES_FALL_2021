#include "mbed.h"

//DATASHEET: https://www.nxp.com/docs/en/data-sheet/MPL3115A2.pdf

I2C i2c(PF_0, PF_1); // SDA, SCL

// 7 bit device address, shifted one bit left, lowest bit is read/write
const int addrRead = 0xC1;
const int addrWrite = 0xC0;


int main()
{
    // place to store received bytes
    char recv = 0x00;

    // address of status reg
    char statusAddr = 0x00;
    while (1) {
        
        // write 0xB8 to register 0x26 on the device
        char cmd[2] = {0x26, 0xB8};
        i2c.write(addrWrite, cmd, 2);

        wait_us(10000);

        // write 0x07 to register 0x13 on the device
        char cmd2[2] = {0x13, 0x07};
        i2c.write(addrWrite, cmd2, 2);

        wait_us(10000);

        // write 0xB9 to register 0x26 on the device
        char cmd3[2] = {0x26, 0xB9};
        i2c.write(addrWrite, cmd3, 2);

        wait_us(10000);
        // write status reg address
        i2c.write(addrWrite, &statusAddr, 1, true);

        // read a byte (status reg)
        i2c.read(addrRead, &recv, 1);

        wait_us(100000);

        // check the status reg until there is data available
        for (int i = 0; i < 10; i++) {
          // write status reg address
          i2c.write(addrWrite, &statusAddr, 1, true);

          // read a byte (status reg)
          i2c.read(addrRead, &recv, 1);
          wait_us(100000);
        }

        // addresses of the three data field we want to read
        char OUT_P_MSB = 0x01;
        char OUT_P_CSB = 0x02;
        char OUT_P_LSB = 0x03;

        // place to store data
        char p_data[3];
        
        for (int k = 0; k < 100; k++) {
          // write the lowest address
          i2c.write(addrWrite, &OUT_P_MSB, 1, true);

          // read 3 bytes! (auto increment address)
          i2c.read(addrRead, p_data, 3);

          printf("fractional part: %d\n\r", p_data[2]>>4);
          wait_us(1000000);
        }
        
        wait_us(1000000);
    }
}
