void setup()
{
  pinMode(A0,INPUT);
  pinMode(A5,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  Serial.begin(9600);
}
void loop()
 {
       if(analogRead(A3) < 700 ) 
        {
            Serial.write('F');
            Serial.write('\r');
            delay(500); 
        }
        else if(analogRead(A2) < 700 ) 
        {
            Serial.write('B');
            Serial.write('\r');
            delay(500); 
        }
        else if(analogRead(A0) < 700 ) 
        {
            Serial.write('L');
            Serial.write('\r');
            delay(500); 
        }
        else if(analogRead(A5) < 700 ) 
        {
            Serial.write('R');
            Serial.write('\r');
            delay(500); 
        }
        else if((analogRead(A0) > 700 ) && (analogRead(A5) > 700 ) && (analogRead(A2) > 700 ) && (analogRead(A3) > 700 )) 
        {
            Serial.write('S');
            Serial.write('\r');
            delay(500); 
        }
}
