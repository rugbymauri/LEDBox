/*
  Melody
 
 Plays a melody
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */
 #include "pitches.h"

// notes in the melody:
int melody1[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
  4, 8, 8, 4,4,4,4,4 };

int melodyPace = 1000;

  
  // notes in the Jeopardy melody:
int jeopardy[] = {
NOTE_C5, NOTE_F5, NOTE_C5, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_F5, NOTE_C5,
NOTE_C5, NOTE_F5, NOTE_C5, NOTE_F5,
NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_CS5,
NOTE_C5, NOTE_F5, NOTE_C5, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_F5, NOTE_C5,
NOTE_F5, NOTE_D5, NOTE_C5, NOTE_AS4,
NOTE_A4, NOTE_G4, NOTE_F4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int jeopardyDurations[] = {
4, 4, 4, 8, 8, 4, 4, 2,
4, 4, 4, 4,
3, 8, 8, 8, 8, 8,
4, 4, 4, 8, 8, 4, 4, 2,
3, 8, 4, 4,
4, 4, 2
};

int jeopardyPace = 1000;


// notes in the Jeopardy melody:
int melody3[] = {
NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4,
NOTE_B4, NOTE_B4, NOTE_B4,
NOTE_A4, NOTE_A4, NOTE_A4,
NOTE_B4, NOTE_D5, NOTE_D5,
NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4,
NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4,
NOTE_G4

};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int melody3Durations[] = {
4, 4, 4, 4,
4, 4, 2,
4, 4, 2,
4, 4, 2,
4, 4, 4, 4,
4, 4, 4, 4,
4, 4, 4, 4,
1
};


int melody3Pace = 1000;


int jingleBells[] = {
NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_G6, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_G6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_G6, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_G6, NOTE_G6, NOTE_E6, NOTE_D6, NOTE_C6};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int jingleBellsDurations[] = {
4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1};

int jingleBellsPace = 1000;



//Mario main theme melody
int mario[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0, 

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int marioDurations[] = {
  8, 8, 8, 8, 
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8, 

  8, 8, 8, 8,
  8, 8, 8, 8, 
  8, 8, 8, 8, 
  8, 8, 8, 8, 

  4, 4, 4,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  4, 4, 4,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
};
//Mario main them tempo
int marioDurations_old[] = {
  12, 12, 12, 12, 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 

  12, 12, 12, 12,
  12, 12, 12, 12, 
  12, 12, 12, 12, 
  12, 12, 12, 12, 

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


int marioPace = 1000;


//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4, 
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4,NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18,18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

int underworldPace = 1000;



int jamesBond[] = {
  /*NOTE_G4,NOTE_G4,NO_SOUND,NOTE_G4,NOTE_G4,NO_SOUND,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,
   NOTE_B3,NOTE_G3,NOTE_C4,NOTE_G3,NOTE_CS4,NOTE_G3,NOTE_C4,NOTE_G3,NOTE_B3,NOTE_G3,NOTE_C4,NOTE_G3,NOTE_CS4,NOTE_G3,NOTE_C4,NOTE_G3,
   NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,
   NOTE_E4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_E4,*/
   //Introduction
  NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_DS5,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_B4,
  NOTE_E4,NOTE_G4,NOTE_DS5,NOTE_D5,NOTE_G4,NOTE_B4,
  NOTE_B4,NOTE_FS5,NOTE_F5,NOTE_B4,NOTE_D5,NOTE_AS5,
  NOTE_A5,NOTE_F5,NOTE_A5,NOTE_DS6,NOTE_D6,0
};


int jamesBondDurations[] = {
  /*8,8,2,8,8,2,16,8,16,8,8,
   2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,
   8,16,16,8,4,8,8,8,
   8,16,16,8,4,8,8,8,*/
  8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8,
  8,2,8,8,1,
  8,4,8,4,8,8,
  8,8,4,8,4,8,
  4,8,4,8,3
};

int jamesBandPace = 1450;

  
const int buttonPin = 9;     // the number of the pushbutton pin
const int buttonPin2 = 10;     // the number of the pushbutton pin
const int buttonPin3 = 11;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);    
  pinMode(buttonPin2, INPUT);    
  pinMode(buttonPin3, INPUT);    
}

void loop() {
   // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {    
    playMelody(mario, marioDurations, (sizeof(marioDurations)/2), 1000);
  }
  
    // read the state of the pushbutton value:
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState2 == HIGH) {    
    playMelody(jingleBells, jingleBellsDurations, (sizeof(jingleBellsDurations)/2), jingleBellsPace);
  }


    // read the state of the pushbutton value:
  buttonState3 = digitalRead(buttonPin3);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState3 == HIGH) {    
    playMelody(jamesBond, jamesBondDurations, (sizeof(jamesBondDurations)/2), jamesBandPace);
  }
 
}


void playMelody(int pMelody[], int pNoteDurations [], int sizeArray, int pace) {
  // iterate over the notes of the melody:
  
  
  for (int thisNote = 0; thisNote < sizeArray; thisNote++) {
//  for (int thisNote = 0; thisNote < ((sizeof *pNoteDurations/sizeof **pNoteDurations)/2); thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = pace/pNoteDurations[thisNote];
    tone(8, pMelody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}



