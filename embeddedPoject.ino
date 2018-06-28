//lib responsible for timer interrupt #include "timeOneConfig/TimerOne.h"//led's pin number#define ledPin 13//interrupt's pin number assuming it's arduino mega or uno "pushButton"#define InterruptPin 2// the time of repeat the call func  of the timer#define constTime 3000000// Var hold pin's statevolatile byte State = LOW;            /* temp sensor vars *///led's pin number#define tempPin A0// var hold sensor reading volatile float tempValue=0;void setup() {                // initialize serial communication at 9600 bits per second:                  Serial.begin(9600);                                // make the pushbutton's pin an input:                   pinMode(InterruptPin, INPUT_PULLUP);                                  // make the led 's pin an output:                   pinMode(ledPin, OUTPUT);                                 // declare the Hardware interrupt                   attachInterrupt(digitalPinToInterrupt(InterruptPin), toggle, RISING);              // software interrupt timer              			// define the timer                     			Timer1.initialize(constTime);                    	//attach the timer to the call function   					 			Timer1.attachInterrupt(readTemp);            }void loop() {    }//hardware ISR  void toggle()  {      //change state         State=State^1;                        //toggle the led            digitalWrite(ledPin,State);      }// software ISRvoid readTemp(){	tempValue = analogRead(tempPin);}