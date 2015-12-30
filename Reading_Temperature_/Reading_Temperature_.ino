/*
 * Dec. 28, 2015 
 * Project: Reading Temperature  
 * Me and Chris also ended up going the extra mile and converting the temperature from Celsius to Fahrenheit
 * We also realized that while posting our mini achievement through our Snapchat story that their temperature reader
 * was actually wrong. 
*/

int lm35pin = A0; 

void setup() {
  //set up serial at 9600 baud 
  Serial.begin(9600); 

}

void loop() {
  int analogValue; 
  float temperature;

  //read our temperature sensor
  analogValue = analogRead(lm35pin);

  //convert the 10bit analog value to celcius 
  temperature = float(analogValue) / 1023;
  temperature = temperature * 500;
  temperature = temperature * 9/5 + 32;

  //print the temperature over serial 
  Serial.print("Temp: "); 
  Serial.print(temperature);
  Serial.println("F"); 

  //wait 1s before before reading the temperature again 
  delay(1000);
}
