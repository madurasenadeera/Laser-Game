// % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
// Title: Project I - Laser Game - Hardware Setup #4                     %
// Author: Jeremy Ng Jian Zhe & Madura Senadeera                         %                                        
// Last Update: 16/04/2019                                               %
// Description: Arduino code controlling the laser game by sensing the . %
// incoming RF24 signal from Hardware Setup #3. This code looks after    %
// Hardware Setup #4 activating the solenoid to open the door between .  %
// Room 1 and Room 2 once the singal is received.                        %
// % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Importing required libraries                                        %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Allocating Component Configuration                                  %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

const uint64_t pipe = 0xE8E8F0F0E1LL;

int msg[1];

int solenoid = 3;

RF24 radio(9, 10);

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Initialising Components                                             %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void setup(void) {
  
  Serial.begin(9600);

  radio.begin();
  
  radio.openReadingPipe(1, pipe);
  
  radio.startListening();
  
  pinMode(solenoid, OUTPUT);
  
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Looping Code for the detection of the RF24 signal                   %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void loop(void) {
  
  if (radio.available()) {
    
    bool done = false;
    
    while (!done) {
      
      done = radio.read(msg, 1);
      
      Serial.println(msg[0]);
      
      if (msg[0] == 111) {
        
        delay(10);
        
        digitalWrite(solenoid, HIGH);
      }
      else {
        
        digitalWrite(solenoid, LOW);
        
      }
      
      delay(10);
      
    }
  }
  else {
    
    Serial.println("No radio available");
    
  }
}
