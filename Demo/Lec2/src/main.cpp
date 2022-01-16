#include <mbed.h>

#define N 5

extern "C" uint32_t summation(uint8_t* arr, uint32_t n);

int main() {

  DigitalOut 
  uint8_t myInts[N] = {1, 2, 3, 4, 5};

  while(1) {
    uint32_t result = summation(myInts, N);
    printf("result: %d \n", result);
  }


}
















// #include <mbed.h>

// extern "C" uint32_t summation(uint32_t* ptr, uint32_t n);

// int main() {

//   uint32_t myInts[5] = {1, 2, 3, 4, 5};

//   while(1) {
//     // put your main code here, to run repeatedly:
//     uint32_t result = summation(myInts, 5);

//     printf("result: %d \n", result);
//   }
// }