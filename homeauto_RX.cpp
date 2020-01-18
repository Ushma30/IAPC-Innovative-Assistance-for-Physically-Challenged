#include "mbed.h"
DigitalOut F1(PTE3);
DigitalOut F2(PTE2);
DigitalOut L1(PTB11);
DigitalOut L2(PTB10);
Serial uart(PTC4,PTC3);
BusOut led(LED1,LED2,LED3);
Serial pc(USBTX, USBRX);

int main() 
{
    F1=0;
    F2=1;
    L1=0;
    L2=1;
    char c='\0';
    while(1)
    {
        if(uart.readable())
        {
            c=uart.getc();
            pc.putc(c);
            if(c=='G')
            {
                F1=1;
                F2=0;
                L1=0;
                L2=0;
                led=0x03; //blue 
                wait(0.5);
            }    
            else if(c=='H')
            {
                L1=1;
                L2=0;
                F1=0;
                F2=1;
                led=0x05; //green
                wait(0.5);
            }
            else if(c=='I')
            {
                F1=1;
                F2=0;
                L1=1;
                L2=0;
                led=0x06; //red
                wait(0.5);
            }
            else if(c=='J')
            {
                F1=0;
                F2=1;
                L1=0;
                L2=1;
                led=0x04; //yellow
                wait(0.5);            
                }
        }
    }
}
