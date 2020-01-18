#include <SoftwareSerial.h>
//KEYPAD
int fan = 2;
int light = 3;
int enable1 = 4;
int enable2 = 7;

//MOTORS
int m1 = 5;
int m2 = 6;
int m3 = 9; 
int m4 = 10;

//SENORS N BUZZER
int ain1 = A0;
int ain2 = A1;
int buzz = A2;

//RF PINS FOR HOME AUTOMATION
#define txPin 11     
#define rxPin 12
SoftwareSerial ha = SoftwareSerial(rxPin, txPin);

void setup()
{
  pinMode(fan,INPUT);
  pinMode(light,INPUT);
  pinMode(enable1,INPUT);
  pinMode(enable2,INPUT);
  pinMode(ain1,INPUT);
  pinMode(ain2,INPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  Serial.begin(9600);
  ha.begin(9600);
}
void home_auto()
{
        if(digitalRead(fan)==0 && digitalRead(light)==1)
        {
            ha.println('H');
            ha.print('\r');
            delay(500);
         }
        else if(digitalRead(fan)==1 && digitalRead(light)==0)
        {
            ha.println('G');
            ha.print('\r');
            delay(500);   
        }
        else if(digitalRead(fan)==0 && digitalRead(light)==0)
        {
            ha.println('I');
            ha.print('\r');
            delay(500);
        }
        else 
        {
            ha.println('J');
            ha.print('\r');
            delay(500);
        }
}
void stop1()
{
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
    delay(500);                    
}
void front()
{
    digitalWrite(m2,HIGH);
    digitalWrite(m4,HIGH);    
    delay(500);
}
void back()
{   
    digitalWrite(m2,LOW);
    digitalWrite(m4,LOW);
    delay(500);
}
void left()
{  
    digitalWrite(m2,LOW);
    digitalWrite(m4,HIGH);
    delay(500);
}
void right()
{
    digitalWrite(m2,HIGH);
    digitalWrite(m4,LOW);
    delay(500);
}

void loop() 
{
    analogWrite(buzz,LOW);
    int k;
    char c='\0';while(1)
    {
               
               digitalWrite(m1,HIGH);
               digitalWrite(m3,HIGH);
               if (digitalRead(enable1) == 0 && digitalRead(enable2) == 1 && analogRead(ain2) > 700)
               {  
                     char a[]= {'F','F','F','F','F','F','F','F','F','F','F','F','F','L','L','L','L','L','L','L','F','F','F','F','F','F','F','F','F','F','F','F','L','L','L','L','L','L','L','L','F','F','F','F','F','F'};
                     for (k=0;k<sizeof a;k++)
                        {
                            c=a[k];
                            if(c=='F' && analogRead(ain2) > 700)
                                {
                                    analogWrite(buzz,LOW);
                                    front();                
                                    home_auto();             
                                }
            
                           else if(c=='L' && analogRead(ain2) > 700)
                               {
                                    analogWrite(buzz,LOW);
                                    left();
                                    home_auto();             
                                }
            
                            else if(c=='R' && analogRead(ain2) > 700)
                                {
                                    analogWrite(buzz,LOW);
                                    right();
                                    home_auto();             
                                }
                            else if(analogRead(ain2) < 700)
                                {
                                    analogWrite(buzz,HIGH);
                                    stop1();
                                    home_auto();             
                                }
                        }
                 }
                 else if (digitalRead(enable2) == 0 && digitalRead(enable1) == 1 && analogRead(ain2) > 700)
                 {  
                      char b[]={'F','F','F','F','F','F','F','F','F','F','F','F','F','R','R','R','R','R','R','R','F','F','F','F','F','F','F','F','F','F','F','F','F','R','R','R','R','R','R','R','R','F','F','F','F','F','F'};
                      for (k=0;k<sizeof b;k++)
                        {
                            c=b[k];
                            if(c=='F' && analogRead(ain2) > 700)
                                {
                                    analogWrite(buzz,LOW);
                                    front();
                                    home_auto();              
                                }
            
                            else if(c=='L' && analogRead(ain2) > 700)
                                {
                                    analogWrite(buzz,LOW);
                                    left();
                                    home_auto(); 
                                }
            
                            else if(c=='R' && analogRead(ain2) > 700)
                                {
                                    analogWrite(buzz,LOW);
                                    right();
                                    home_auto(); 
                                }
                            else if(analogRead(ain2) < 700)
                                {
                                    analogWrite(buzz,HIGH);
                                    stop1();
                                    home_auto(); 
                                }
                        }
                 }
                 else if(digitalRead(enable1) == 1 && digitalRead(enable2) ==1) 
                 {
                      analogWrite(buzz,LOW);
                      char c='\0';
                      if(Serial.available())
                      {
                            c=Serial.read(); 
                            Serial.print(c);
                            if(analogRead(ain1) < 700 && c=='B')
                            {               
                                analogWrite(buzz,HIGH);
                                stop1();   
                                home_auto();
                            }
                            else 
                            {
                                analogWrite(buzz,LOW);
                                if(c=='F')
                                {
                                    front();
                                    home_auto();
                                }
                                else if(c=='B')
                                {
                                    back();
                                    home_auto();
                                }
                                else if(c=='L')
                                {
                                    left();
                                    home_auto();
                                }
                                else if(c=='R')
                                {
                                    right();
                                    home_auto();
                                }               
                                else if(c=='S')
                                {
                                    stop1();
                                    home_auto();
                                }
                            }
                      }
            }       
            else if(analogRead(ain2) < 700)
             {
                analogWrite(buzz,HIGH);;
                stop1();                 
             }               
    }
}
