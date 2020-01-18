#include "mbed.h"
#include "MMA8451Q.h"
#define MMA8451_I2C_ADDRESS (0x1d<<1)
Serial uart(PTC4, PTC3); // tx, rx
DigitalOut myled(LED2);
DigitalOut myled1(LED3);
int main()
{
    uart.baud(9600);
    float i,j;
    MMA8451Q acc(PTE25, PTE24, MMA8451_I2C_ADDRESS);
    while (1)
    {
        myled=1;
    i = acc.getAccX();
    j = acc.getAccY();
    if ((i>0.5 && i<1.0))
    {
        myled=0;
        uart.printf("F");
        uart.putc(13);
        wait(0.1);
    }
   else if ((i<-0.5 && i>-1.0))
    {
        myled=0;
        uart.printf("B");
        uart.putc(13);
        wait(0.1);
    }
    else if ((j>0.5 && j<1.0))
    {
        myled=0;
        uart.printf("R");
        uart.putc(13);
        wait(0.1);
    }
    else if ((j<-0.5 && j>-1.0))
    {
        myled=0;
        uart.printf("L");
        uart.putc(13);
        wait(0.1);
    }
    else if ((j<0.2 && j>-0.2) && (i<0.2 && i>-0.2))
    {
        myled1=0;
        uart.printf("S");
        uart.putc(13);
        wait(0.1);
    }
    }
}
