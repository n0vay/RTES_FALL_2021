/*
 * Copyright (c) 2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

//references:
// Thread https://os.mbed.com/docs/mbed-os/v6.15/apis/thread.html
// Semaphore https://os.mbed.com/docs/mbed-os/v6.15/apis/semaphore.html


Semaphore shh(1);
Mutex m;
Thread t(osPriorityLow);

void myFunc() {
  while (1) {
    shh.acquire();
    printf("BAHHHHHHHHHHHHH\n\r");
    shh.release();
    ThisThread::sleep_for(10);

  }
}

int main () {
  t.start(callback(myFunc));

  while(1) {
    shh.acquire()
    printf("knock knock.... who's there.... the interrupting sheep...... the interrupting sheep who?....\n\r");
    shh.release();
    ThisThread::sleep_for(1000);
  }

}




















// Thread thread;
// Semaphore shh(1);

// void shouty_thread()
// {
//     while (1) {
//         shh.acquire();
//         printf("I'm a thread!!!!!!!!!\n\r");
//         shh.release();
//         ThisThread::sleep_for(1);
        
//     }
// }


// int main(){

//   thread.start(callback(shouty_thread));
//   int i = 0;
//   while (1) {
//     shh.acquire();
//     printf("I'm a main loop, and it sure would be a problem if a thread interrupted this super important message\r\n", i++);
//     shh.release();
//     ThisThread::sleep_for(1000);
//   }
// }