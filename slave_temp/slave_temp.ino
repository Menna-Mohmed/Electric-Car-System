#include <Wire.h>

#define temperaturePin A0 // Analog pin for temperature sensor  

const int TempThreshold = 50; // speed indicating high temprature
const int speedThreshold = 200; // speed indicating high speed

void receive(int byte);
int temp;

void setup() {

  Serial.begin(9600);
  Wire.begin(8);

  Wire.onReceive(receive);
  pinMode(temperaturePin, INPUT);
  
}

void loop() {
  temp = readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("°C");

  delay(500);

  Wire.beginTransmission(10);
  Wire.write(temp);
  Wire.endTransmission();

  delay(200);

  Serial.flush();
 
}

int readTemperature() {

  int Value = analogRead(temperaturePin);
  float voltage = Value * (5.0 / 1023.0); // Convert the analog value to voltage
  float temperature = voltage * 100.0; // LM35 temperature formula
  return static_cast<int>(temperature); //Tconverts the temperature value from float to int
}
void receive(int byte){
   int x= Wire.read();
   if(x<=speedThreshold){

    readTemperature();
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println("°C");

    delay(500);
    
    Serial.flush();

   }
   else{
    while(x> speedThreshold){

      Serial.println("Speed of motor too high  ");
      temp=TempThreshold;
      delay(200);

      Serial.print("Temperature: ");
      Serial.print(temp);
      Serial.println("°C");

      delay(500);
      break;

    }
   }
  
}
