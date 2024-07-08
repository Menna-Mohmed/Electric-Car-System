#include "display_seg.h"
#include <math.h>

#define voltage_sensor     A0      //Analog pin for voltage reading
#define current_sensor     A5      //Analog pin for current reading
#define buttonPin          2       //Digital pin for the push button(toggling)
#define first_segments_pin 13      //first pin for the 7segments


const float over_volt = 60;
const float over_curr = 1;

bool displayVoltage = true;
float voltage_value, current_value;
unsigned int first_digit, second_digit;

void setup() {

  Serial.begin(9600);

  pinMode(voltage_sensor, INPUT);
  pinMode(current_sensor, INPUT);
  pinMode(buttonPin,INPUT_PULLUP);
  segment_setup(first_segments_pin);  //function to intialize segments pins as outputs
}

void loop() {
  voltage_value = (((float)analogRead(voltage_sensor)) * 95 / 1023);           //calculation to get the voltage
  current_value = (((float)analogRead(current_sensor) * 5 / 1023) - 2.5) * 5;  //calculation to get the current
  
  
  if ((voltage_value >= over_volt) && (current_value >= over_curr))   //sending the status of current and voltage to dashboard section to alarm in case of over volt or current 
  {
    Serial.write('Z');
    delay(100);
  }
  else if (voltage_value >= over_volt) 
  {
    Serial.write('W');
    delay(100);
  } 
  else if (current_value >= over_curr) 
  {
    Serial.write('S');
    delay(100);
  } 
  else if ((voltage_value < over_volt) && (current_value < over_curr)) 
  {
    Serial.write('D');
    delay(100);
  }

  if (digitalRead(buttonPin) == LOW)  // Toggle display mode when the button is pressed
  {
    
    displayVoltage = !displayVoltage;
    delay(100);  // Debounce delay
  }

  if (displayVoltage)  // Display either voltage or current based on the selected mode
  {
    if (voltage_value >= 10)  //display the voltage as integer when the voltage bigger than or equal to 10v
    {
      voltage_value = round(voltage_value);
      first_digit = ((int)voltage_value) / 10;
      second_digit = ((int)voltage_value) % 10;
      print_volt();                  //function to display volt
      first_segment(first_digit);    //function to display the value of first 7segment
      second_segment(second_digit);  //function to display the value of second 7segment
    } else                           //display the voltage as float when the voltage less than 10v
    {
      voltage_value = voltage_value * 10;
      first_digit = ((int)voltage_value) / 10;
      second_digit = ((int)voltage_value) % 10;
      print_volt_dot();              //function to display volt and the dot point
      first_segment(first_digit);    //function to display the value of first 7segment
      second_segment(second_digit);  //function to display the value of second 7segment
    }
  } else {
    current_value = current_value * 10;
    first_digit = ((int)current_value) / 10;
    second_digit = ((int)current_value) % 10;
    print_ampere_dot();              //function to display current and the dot point
    first_segment(first_digit);
    second_segment(second_digit);
  }

}
