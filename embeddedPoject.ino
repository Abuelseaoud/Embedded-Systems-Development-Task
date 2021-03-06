//lib responsible for timer interrupt 
    #include <TimerOne.h>


//led's pin number
    #define ledPin 13

//interrupt's pin number assuming it's arduino mega or uno "pushButton"
    #define InterruptPin 2

// the time of repeat the call func  of the timer
    #define constTime 3000000

// Var hold pin's state
    volatile byte State = LOW;

//led flag var
    volatile int ledFlag=0;


            /* temp sensor vars */

//led's pin number
    #define tempPin A0

// var hold sensor reading 
    volatile float tempValue=0;

//temp flag var
    volatile int tempFlag=0;




          /* serial setup*/
// set baudRate value 
    #define baudRate 9600



void setup() {
  
              // initialize serial communication at 9600 bits per second:
                  Serial.begin(baudRate);
                  
              // make the pushbutton's pin an input:
                   pinMode(InterruptPin, INPUT_PULLUP);
                   
               // make the led 's pin an output:
                   pinMode(ledPin, OUTPUT);
                   
                        /* declare the Hardware interrupt */
                   attachInterrupt(digitalPinToInterrupt(InterruptPin), toggle, RISING);

                       /*  software interrupt timer */ 
                    // define the timer 
                          Timer1.initialize(constTime);
                      //attach the timer to the call function
                         Timer1.attachInterrupt(readTemp);
            }

void loop() {
      
      if (tempFlag)
          {
      
          //remove flag 
            tempFlag=0;
      
      
      
      
            /* section o proccess the reading in volt and convert in to temperature according to the sensor */
      
      
      
      
      
      
      
      
      
                                         /* end of proccessing section*/
      
          //send data to serial 
      
              /*   i need to stop interrupt here */
                   noInterrupts();
          
              Serial.print("the temp reading is :");
              Serial.println(tempValue);
          
              /*i need to restart the   interrupt here*/
                   interrupts();
      
          
      
      
          }
          

    if (ledFlag)
    
        {
                //remove flag 
                      ledFlag=0;
    
                //send data to serial
    
                /*   i need to stop interrupt here */ 
                    noInterrupts();
    
                 Serial.println("pressed");
                 Serial.print("led state is : ");
                 if (State)
                    {Serial.println("ON");}
                 else
                    {Serial.println("OFF");}
    
                /*i need to restart the   interrupt here*/
                     interrupts();
    
          
    
        }

    
}

//hardware ISR
  void toggle()
  {



      //change state
         State=!State;
         
         
      //toggle the led   
         digitalWrite(ledPin,State);


      // raise flag
          ledFlag=1;
    
    
    // canceling the bouncing effect
      while (digitalRead(!InterruptPin))
    {
    };
    
  }


// software ISR
void readTemp()
{

 //read value 
  tempValue = analogRead(tempPin);

  //raise flag

  tempFlag=1;
}
