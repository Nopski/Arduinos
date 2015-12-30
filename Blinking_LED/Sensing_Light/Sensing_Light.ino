// December 29, 2015 
// Project: Sensing Light 


  //sensor minimum, discovered through experiment 
  const int sensorMin = 0; 
  //sensor maximum, discovered through experiment 
  const int sensorMax = 800; 

  //the photocell voltage divider pin 
  int photocellPin = A0; 

void setup() {
  //set up serial at 9600 baud 
  Serial.begin(9600); 
}

void loop() {
  int analogValue; 
  int range; 

  //read our photocell 
  analogValue = analogRead(photocellPin);
  //map the sensor range to a range of four options 
  range = map(analogValue, sensorMin, sensorMax, 0, 3); 

  //do something different depending on the range value
  switch(range) 
  {
    //your hand is on the sensor 
    
    case 0: 
      Serial.println("dark");
      break; 
      
    //your hand close to the sensor 
    case 1: 
        Serial.println("dim"); 
        break;
        
    //your hand is a few inches from the sensor
    case 2: 
        Serial.println("medium");
        break; 
        
    //your hand is nowhere near the sensor
    case 3: 
       Serial.println("bright");
       break;  
  }

  //wait 0.25s before reading the photocell again 
  delay(250);
}
