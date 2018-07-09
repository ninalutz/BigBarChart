int armingTime;
int pin = 9;
int counter = 0;
int pulseTime = 1100;
boolean highSpeed = true;

void setup() {
  Serial.begin(9600);

  pinMode(pin, OUTPUT);

  lowThrottleSim();

  Serial.println("Enter 0-9 to adjust motor speed.");
  Serial.println("Enter h or 1 to change the speed range.");
  
}

void loop() {
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulseTime);
  digitalWrite(pin, LOW);
  delay(10-(pulseTime/1000));


  while(Serial.available() > 0){
        readSerialVal();
    }

  if(Serial.available() == 0){
        Serial.print("Throttle: ");
        Serial.print((pulseTime-1100)/8);
        Serial.println("%");
    }
}

void readSerialVal(){
  switch(Serial.read()){
      case '0':
        setTimingParams(1100);
        break;
      case '1':
        setTimingParams(1150);
        break;
      case '2':
        setTimingParams(1200);
        break;
      case '3':
        setTimingParams(1300);
        break;
      case '4':
        setTimingParams(1400);
        break;
      case '5':
        setTimingParams(1500);
        break;
      case '6':
        setTimingParams(1600);
        break;
      case '7':
        setTimingParams(1700);
        break;
      case '8': 
        setTimingParams(1800);
        break;
      case '9':
        setTimingParams(1900);
        break;
      case 'h':
        highSpeed = true;
        setTimingParams(pulseTime);   
        break;
    }
  }

void setTimingParams(int newPulseTimeVal){
  if(highSpeed){
      pulseTime = newPulseTimeVal;
   } else{
      pulseTime = 1025 + (newPulseTimeVal/10);
   }
}

void lowThrottleSim(){
    for(armingTime = 0; armingTime<500; armingTime++){
        digitalWrite(pin, HIGH);
        delayMicroseconds(pulseTime);
        digitalWrite(pin, LOW);
        delay(10-(pulseTime/1000));
      }
}
