// % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
// Title: Project I - Laser Game                                         %
// Author: Madura Senadeera                                              %                                        
// Last Update: 15/04/2019                                               %
// Description: Arduino code controlling the laser game by initialising  %
// laser activation time. This code looks after Hardware Setup 2         %
// % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Allocating Component Configuration                                  %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

const int ledPin = 13;

const int ldrPin = A0;

const int laserPin = 4;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Initialising Components                                             %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void setup () {

Serial.begin(9600);

pinMode(ledPin, OUTPUT);

pinMode(ldrPin, INPUT);

pinMode( laserPin , OUTPUT);

digitalWrite( laserPin , HIGH);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Looping Code for the detection of the laser                         %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void loop() {

int ldrStatus = analogRead(ldrPin);

if (ldrStatus < 300) {

digitalWrite(ledPin, HIGH);

digitalWrite( laserPin , HIGH);

}
else {

digitalWrite(ledPin, LOW);

digitalWrite( laserPin , LOW);

}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Serial output of whether laser is detected                          %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Serial.println( ldrStatus );
//delay(10);
}
