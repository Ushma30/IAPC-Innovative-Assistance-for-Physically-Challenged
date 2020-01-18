const int fan = 2;
const int light = 3;

int buttonState3 = 0;         // variable for reading the pushbutton status
int buttonState4 = 0;         // variable for reading the pushbutton status

 void setup()
 {
   pinMode(fan,INPUT);
   pinMode(light,INPUT);

   Serial.begin(9600);
   Serial.flush();
 }
 void loop()
 {
   buttonState3=digitalRead(fan);
   buttonState4=digitalRead(light);
   if(buttonState3==HIGH && buttonState4==LOW)
        {
            Serial.write('H');
            Serial.write('\r');
            delay(500);
         }
        else if(buttonState3==LOW && buttonState4==HIGH)
        {
            Serial.write('G');
            Serial.write('\r');
            delay(500);   
        }
        else if(buttonState3==HIGH && buttonState4==HIGH)
        {
            Serial.write('I');
            Serial.write('\r');
            delay(500);
        }
        else 
        {
            Serial.write('J');
            Serial.write('\r');
            delay(500);
        }
 }
