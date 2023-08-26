
#include "EmonLib.h"             // Include Emon Library
#include <Arduino.h>
#include <EEPROM.h>

EnergyMonitor emon1;             // Create an instance

volatile int i=60;
int eprom = 1;
int buttonState = 1;
int cont = 3;
int buttonPin = 2;  //pin buton 
int pin2 = 4;  //pin led rosu
int pin3 = 3;  //pin led galben
int pin6 = 6;  //pin led alb
const byte interruptPin = 2;

void setup(){ 
  TCCR0B = TCCR0B & B11111000 | B00000001; // PWM 65 kHz pins 5 and 6  
  pinMode(buttonPin, INPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin6, OUTPUT);
  Serial.begin(9600);
  eprom = 2;
  EEPROM.write(1, 3);  
  cont = EEPROM.read(1);    
  emon1.voltage(2, 197.26, 2);  // 1.7 Voltage: input pin, calibration, phase_shift
  emon1.current(1, 14.5);       // Current: input pin, calibration.
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), set_botton, RISING);
  emon1.realPower = 0;
}

void loop(){
  eprom = EEPROM.read(1);
  if (cont == 1) {
    traker();
  } 
  if (cont == 2) { 
    full();
  }
  if (cont == 3) { 
    stop();
  } 
}
