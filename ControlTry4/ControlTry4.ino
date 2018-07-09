int ESCpin = 9;    // ESC signal wire connected to pin 11 on arduino
int val = 0;        //variable to store PWM value

void setup() 
{ 
 
} 


void loop() 
{ 
 for(val = 0; val <= 255; val += 5)
 {
   analogWrite(ESCpin, val);
   delay(100);
 }
}
