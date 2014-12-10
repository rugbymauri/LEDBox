/**
*
* referenzen
* http://scuola.arduino.cc/lesson/qXB4KZb/How_to_show_text_in_a_led_matrix_with_your_browser
* http://arduino.cc/en/Tutorial/TimeCheck
*
**/
#include <HT1632.h>
#include "font_clock.h"
#include <Process.h>

int i = 0;
int wd;
byte disp [10];
Process date;  
String timeString;

void setup () {
  Bridge.begin();
   HT1632.setCLK(4);
   HT1632.begin(5, 6, 7);
  wd = HT1632.getTextWidth(disp, FONT_CLOCK_END, FONT_CLOCK_HEIGHT);
  
  // run an initial date process. Should return:
  // hh:mm:ss :
  if (!date.running())  {
    date.begin("date");
//    date.addParameter("+%H:%M");
    date.addParameter("+%T");
    date.run();
  }
}

void loop () {
  
  // restart the date process:
    if (!date.running())  {
      date.begin("date");
//      date.addParameter("+%H:%M");
      date.addParameter("+%T");
      date.run();
    }
  
  
  timeString = date.readString();
  timeString.toCharArray((char*)disp,10); 
  //HT1632.drawTarget(BUFFER_BOARD(1));
  HT1632.clear();
  HT1632.drawText(disp, 0, 0, FONT_CLOCK, FONT_CLOCK_END, FONT_CLOCK_HEIGHT);
  HT1632.render();
  
  //i = (i+1)%(wd + OUT_SIZE);
  
  delay(100);
}
