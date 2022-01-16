#include <mbed.h>

// mbed 6 does not give us wait_ms
void wait_ms(uint32_t ms) {
  wait_us(1000*ms);
}

// function to set the LED using pointers
void setLEDviaptr(DigitalOut* led_ptr, uint8_t* ledState_ptr) {
  led_ptr->write(*ledState_ptr);
}


int main() {

  // pattern
  uint8_t myPattern[24] = {0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0};
  
  // this points to the same place!
  uint8_t* tmp_ptr = myPattern;

  // setup output
  DigitalOut led(LED3);

  while(1) {
    // set the LED
    // setLEDviaptr(&led, &ledState);


    // loop over pattern
    for (uint8_t i = 0; i < 24; i++) {
      // set the LED
      led.write(*tmp_ptr);
      
      // increment the pointer
      tmp_ptr++;
      
      // delay 500ms
      wait_ms(500);
    }
    
    // reset the pointer
    tmp_ptr = myPattern;
    
  }
}