// % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
// Title: Project I - Laser Game - Hardware Setup #3                     %
// Author: Jeremy Ng Jian Zhe & Madura Senadeera                         %                                        
// Last Update: 16/04/2019                                               %
// Description: Arduino code controlling the laser game by sensing the   %
// incoming laser from Hardware Setup #2. This code looks after Hardware %
// Setup #3 sending the RF24 signal for the door release once laser 2    %
// has been detected.                                                    %
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

const int ldr2Pin = A1;

const uint64_t pipe = 0xE8E8F0F0E1LL;

int msg[1];

int SW1 = 7;

RF24 radio(9,10);

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Initialising Components                                             %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void setup(void){
pinMode(ldr2Pin, INPUT);
Serial.begin(9600);
radio.begin();
radio.openWritingPipe(pipe);}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Looping Code for the detection of the laser and sending RF signal   %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void loop(void){

int ldr2Status = analogRead(ldr2Pin);

if (ldr2Status < 300) { //Laser is on

msg[0] = 111;

radio.write(msg, 1);

}

}
