  #include <HT1632.h>
#include <font_5x4.h>
#include <images.h>
#include "pitches.h"

// https://learn.adafruit.com/multi-tasking-the-arduino-part-1/overview
//



class Tone {

    // notes in the melody:
    int melody[8] =   {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_G3, NOTE_B3, NOTE_C4};

    // note durations: 4 = quarter note, 8 = eighth note, etc.:
    int noteDurations[8] =  {4, 8, 8, 4, 4, 4, 4, 4 };

    int updateInterval = 0;      // interval between updates unsigned long
    int lastUpdate = 0; // last update of position

    int thisNote = 0;

  public:
    Tone(int i)
    {
    }


    void Update() {
      if ((millis() - lastUpdate) > updateInterval) // time to update
      {
        lastUpdate = millis();

        if (thisNote < 7) {

          noTone(9);
          // to calculate the note duration, take one second
          // divided by the note type.
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(9, melody[thisNote], noteDuration);

          // to distinguish the notes, set a minimum time between them.
          // the note's duration + 30% seems to work well:
          int pauseBetweenNotes = noteDuration * 1.30;
          thisNote++;
          updateInterval = 300;
          // stop the tone playing:
          //noTone(8);


        } else {
          thisNote = 0;
        }
      }

    }

};


class ImageRunner
{

  int clk;
  int cs;
  int wr;
  int data;

  int i = 0;


  int wd;



  const byte disp [20] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'h', 'o', 'w', ' ', 'a', 'r', 'e', ' ', 'y', 'o', 'u', '?'};

  int mIMG_TREE_WIDTH = 9;
  int mIMG_TREE_HEIGHT = 16;

  int  updateInterval = 150;      // interval between updates
  unsigned long lastUpdate = 0; // last update of position

  public:
  ImageRunner(int i) {
//    clk = pClk;
clk = i;
  //  cs = pCs;
    //wr = pWr;
//    data = pData;




  }

  void Attach() {

    HT1632.setCLK(4);
    HT1632.begin(5, 6, 7);
    wd = HT1632.getTextWidth(disp, FONT_5X4_END, FONT_5X4_HEIGHT);


  }

  void Update() {
  if((millis() - lastUpdate) > updateInterval)  // time to update
    {
      lastUpdate = millis();
//      HT1632.drawTarget(BUFFER_BOARD(1));
      HT1632.clear();
      HT1632.drawText(disp, OUT_SIZE - i, 2, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);
      HT1632.render();

      i = (i+1)%(wd + OUT_SIZE);

      updateInterval = 300;

    }

  }

};




Tone playMusic(0);
ImageRunner imageRunner(1);

void setup () {

  // Working with Bicolor displays.
  // Make sure that a bicolor display is set in HT1632.h
  //  HT1632.setCLK(4);
  // HT1632.begin(5, 6, 7);

  imageRunner.Attach();

}

void loop() {

    imageRunner.Update();
  playMusic.Update();
}
