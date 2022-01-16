#include <mbed.h>

// processing
// link: https://colab.research.google.com/drive/1dDtqLqppkbNgQRQmHAe999KlV16cMo0n?usp=sharing

int main() {

  AnalogIn ain(PA_6);

  float buf[100];
  while (1) {

    // sample data
    for (int i = 0; i < 100; i++) {
      buf[i] = ain.read();
      wait_us(1000);
    }

    // output data
    printf("data = [");
    for (int i = 0; i < 100; i++) {
      printf("%d,", (int)(1000*buf[i]));
    }
    printf("]\n\r\n\r");

  }

}