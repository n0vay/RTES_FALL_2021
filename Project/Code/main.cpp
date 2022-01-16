#include "mbed.h"
#include "LCD_DISCO_F429ZI.h"
#include "gyro.h" // contains values for Gyro
using namespace std::chrono;

SPI spi(PF_9, PF_8, PF_7); // mosi, miso, sclk
DigitalOut cs(PC_1);  // chip select pihn for Gyroscope

LCD_DISCO_F429ZI lcd;       //Create a LCD_DISCO_F429ZI object    

Ticker ticker;

Timer t;

volatile bool is_sampleFlag = true;

void setSampleFlag() {

is_sampleFlag = true;

}


void getvalues(int16_t *z){
  cs = 0;
  
  // Send the adress of the z register to read along with write 
  spi.write(GYRO_ZOUT_H | READFLAG);
  
  // Send a dummy byte to receive the contents of the register
  *z = spi.write(DUMMYBIT);

  spi.write(GYRO_ZOUT_L | READFLAG);

  *z |= (spi.write(DUMMYBIT) << 8 );
  
  // Deselect the device
  cs = 1;  

}



int main()
{

    
    cs = 1; // Chip must be deselected

    wait_us(1000);
    
    
    spi.format(8,3);  // Setup the spi for 8 bit data, high steady state clock,
    spi.frequency(1000000);  // second edge capture, with a 1MHz clock rate

    
    int16_t GyroBuffer_sum=0;
    char buf[20];           //temporary string variable
    
    lcd.SetFont(&Font16);

    cs = 0;
    spi.write(CONTROL_REG);
    spi.write(GYRO_CONFIG);
    cs = 1;
    wait_us(1000);

    

    int16_t z;	//Varables for the program
    int buffer=0;
    uint8_t foot_length = 3;
    int16_t velocity;
    float delta_distance = 0;
    float total_distance = 0;
    int round_distance;
    int16_t GyroBuffer[3]= {0,0,0};    //array to store the results for  Z from the gyro
    uint8_t steps = 0;
    bool stepset = false;
    float time_count;
    uint8_t average_speed = 0;
    

    t.start();
    //ticker.attach(&setSampleFlag, 1ms);

    while (1) 
    {  
        GyroBuffer_sum=0; //setting the average to 0

        for(int j = 0;j<10;j++)
        {
	 //if(is_sampleFlag == true)
        //{       
        //is_sampleFlag = false;
	
        getvalues(&z);
        z = z*0.00825;	//multiplying for 250 senstivity
        buffer +=z;
        wait_us(10000); //sampling at 100Hz
	 //}
        }
        buffer/=10; //getting an average of 10 values
        //printf("%d\n", buffer);

        GyroBuffer[2]=GyroBuffer[1]; //shifting values for buffer
        GyroBuffer[1]=GyroBuffer[0];
        GyroBuffer[0]=buffer;
        for(uint8_t k = 0; k<3;k++)
        GyroBuffer_sum +=GyroBuffer[k]; 
        GyroBuffer_sum/=3; //buffer average

        buffer = (0.8)*GyroBuffer[1] + 0.2*(buffer+GyroBuffer[1])/2; // low pass filter
        
        
        velocity = buffer * foot_length * 0.0174; //degree to radian conversion

        delta_distance = velocity * 0.1;  //distance for small time
                                                        
        if (delta_distance > 0 && GyroBuffer_sum >50) // filter for the idle values
        total_distance+=delta_distance;

        round_distance = (int)total_distance;

        if (buffer > 150 && stepset == false) //pedometer algo
        {
            steps+=1;
            stepset = true;
        }
        if(buffer < 150)
        stepset = false;

        time_count = duration_cast<milliseconds>(t.elapsed_time()).count() / 1000; //total time in seconds


        average_speed = round_distance/time_count; //calculating average speed since active

        GyroBuffer_sum=0;

    
        lcd.DisplayStringAtLine(1, (uint8_t *) "Gyroscope Values"); //code to display values via LED
        sprintf(buf, "Z = %6d", z);
        lcd.DisplayStringAtLine(2,(uint8_t *) buf);
        lcd.DisplayStringAtLine(3, (uint8_t *) "Bunched Values");
        sprintf(buf, "Z = %6d", buffer);
        lcd.DisplayStringAtLine(4,(uint8_t *) buf);
        lcd.DisplayStringAtLine(5, (uint8_t *) "Lin Velocity Approx");
        sprintf(buf, "V = %6d", velocity);
        lcd.DisplayStringAtLine(6,(uint8_t *) buf);
        lcd.DisplayStringAtLine(7, (uint8_t *) "Distance Approx");
        sprintf(buf, "D = %6d", round_distance);
        lcd.DisplayStringAtLine(8,(uint8_t *) buf);
        lcd.DisplayStringAtLine(9, (uint8_t *) "Steps Taken");
        sprintf(buf, "S = %6d", steps);
        lcd.DisplayStringAtLine(10,(uint8_t *) buf);
        wait_us(1000);
    }

}
