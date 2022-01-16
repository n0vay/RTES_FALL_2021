#include <mbed.h>

DigitalOut led(LED3);

void flasher() {
  led = !led;
}


int main() {

  Ticker t;
  t.attach(&flasher, 0.5);

  while(1) {
    wait_us(1000000000);
  }
}