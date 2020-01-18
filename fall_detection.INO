#include <SoftwareSerial.h>
// Constants
#define txPin 8      //tx pin in GPS connection
#define rxPin 9      //rx pin in GPS connection

// Set up the GPS serial port
SoftwareSerial gps = SoftwareSerial(rxPin, txPin);
static int i=1;
const int ledPin =  13;  
int j=1;
char s[75]={'$','\0'};
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
    
void setup()
{
pinMode(ledPin, OUTPUT);     
Serial.begin(9600);
Serial.flush(); 
//setup for GPS Serial Port  
pinMode(rxPin, INPUT);
pinMode(txPin, OUTPUT);
gps.begin(9600);
gps.flush();
//setup satellites signal

}
void loop()
{
  sensorValue= analogRead(sensorPin);
   while (s[j-1]!='E' && j<45)
  {char c=gps.read();
  s[j]=c;
  j++;
  delay(1000);
  };
  Serial.println(s);
  Serial.println(i);  
  if((i==1) && (sensorValue>700))
  {  
   i++;
  digitalWrite(ledPin, HIGH); 
  delay(1000);
  digitalWrite(ledPin, LOW); 
  delay(1000);
  Serial.print("\r");
  delay(1000);                  
  Serial.print("AT+CMGF=1\r");    
  delay(1000); 
  Serial.print("AT+CMGS=\"+919820703275\"\r");    //Number to which you want to send the sms
  delay(1000);
  Serial.println("ABC fell off at loaction:");
  delay(1000);
  Serial.print("Latitude: ");
  for (int k=20;k<29;k++)
  { 
    int a=int(s[k]); 
    if(k==22)
    {
    Serial.print(" ");
    Serial.print(a-48);
    }
    else if(k==24)
    Serial.print(char(46));
     
    else if (k==28) 
    {
     Serial.print(a-48); 
    Serial.print("' North");}
    else
    { Serial.print(a-48);}
  }
  Serial.println();
  delay(1000);
  
  Serial.print("Longitude: ");
  for (int k=33;k<42;k++)
  { 
    int a=int(s[k]); 
        if(k==35)
    {
    Serial.print(" ");
    Serial.print(a-48);
    }
    else if(k==37)
    Serial.print(char(46));
     
    else if (k==41) 
    {Serial.print(a-48); 
    Serial.print("' East");}
    else
    { Serial.print(a-48);}
  }
  //Serial.println();
  //delay(1000);
  Serial.write(0X1A);
  delay(1000);
//  Serial.write("26");
  //delay(1000);
  
  }
else 
  {
    digitalWrite(ledPin, LOW); 
    delay(1000);
  }
}
