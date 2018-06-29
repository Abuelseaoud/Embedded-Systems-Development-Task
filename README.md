# Embedded-Systems-Development-Task

## Description
Arduino project  control reading from sensors continuously  and change led state and sending the data reading&led state without any conflict 


## Specifications
#### the project contains:
* intput hardware interrupt pin .
* output digital pin controlled by ISR.
* input analog pin connected to temperature pin and being read by software interrupt.

##  instructions for setting the app
#### software instruction 
  1.[ download arduino IDE ][https://www.arduino.cc/en/Main/Software]
  
  2- intall arduino driver form  'drivers' folder according to your computer
  
  3. Add TimerOne library to  '/libraries' folder   -TimerOne library files is in this repo-
  
  4. run the IDE , connect the arduino board to your computer with cable ,
  [select the port and type of arduino assuming it is mega2650][https://www.arduino.cc/en/Guide/ArduinoMega2560#toc5]

  5. after hardware setup,  open attached code file ->verify the code and upload it 
  
  6. open serial monitor to see the sent data
  
  
#### hardware instruction 
 ###### You can change the port numbers according to your choice by changing the constant definiton in the begining of code
 
 1. connect interrupt pin -pin '2' in digital pins - to pushbutton and connect the pushbutton to arduino ground.
 
 2. connect  +ve terminal in led to led pin -pin '13' in digital pins -,the other pin  is connected to res 220ohm and the res is connected to arduino ground . 
 
 3. connect the temperature sensor according to it's configuration  but connect data terminal to tempPin -pin 'A0' in analog input pins-.
 
 
 
 ## assumptions
 
 - Arduino board :Arduino mega 2650
 
 - digital Pins:
   - ledPin 13
   -InterruptPin 2
   
 - Analog pins:
   -tempPin A0
   
 - baudRate 9600
 
 
 
   
 