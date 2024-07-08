#include <Wire.h>

int ENA = 9;
int IN1 = 7;
int IN2 = 6;
int DCspeedPin = A0;

int PWM;

const int speedThreshold = 200;  // speed indicating high speed
const int TempThreshold = 50;    // speed indicating high temprature


void receive(int byte);
void Pot_Speed();

void setup() {

  Serial.begin(9600);
  Wire.begin(10);

  Wire.onReceive(receive);

  pinMode(ENA, OUTPUT);
  pinMode(DCspeedPin, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {

  int dcspeed = analogRead(DCspeedPin);
  PWM = map(dcspeed, 0, 1024, 0, 255);
  Wire.beginTransmission(8);
  Wire.write(PWM);
  Wire.endTransmission();
  delay(200);
}

void Pot_Speed() {

  if (PWM <= speedThreshold) {
    Serial.print("Motor speed: ");
    Serial.println(PWM);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
    analogWrite(ENA, PWM);
  } else {

    while (PWM > speedThreshold) {
      analogWrite(ENA, 0);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);

      Serial.flush();
      Serial.println("Motor speed: 0");
      delay(500);
      break;
    }
  }
}

void receive(int byte) {

  int x = Wire.read();

  if (x <= TempThreshold) {
    Pot_Speed();
  }

  else {
    while (x > TempThreshold) {
      analogWrite(ENA, 0);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);

      Serial.flush();
      Serial.println("MOTOR STOPPED,TEMP TOO HIGH");

      delay(1000);
      break;
    }
  }
}
