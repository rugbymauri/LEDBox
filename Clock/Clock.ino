/**
*
* referenzen
* http://scuola.arduino.cc/lesson/qXB4KZb/How_to_show_text_in_a_led_matrix_with_your_browser
* http://arduino.cc/en/Tutorial/TimeCheck
*
**/
#include <HT1632.h>
#include <font_8x4.h>
#include <font_5x4.h>
#include <Process.h>

int i = 0;
int wd;
byte disp [10];
byte dispDate [10];
Process time;  
String timeString;
Process date;  
String dateString;
int left;

void setup () {
  Bridge.begin();
   HT1632.setCLK(4);
   HT1632.begin(5, 6, 7);
//  wd = HT1632.getTextWidth(disp, FONT_8X4_END, FONT_8X4_HEIGHT);
  
  // run an initial date process. Should return:
  // hh:mm:ss :
  if (!time.running())  {
    time.begin("date");
    time.addParameter("+%H:%M");
//    time.addParameter("+%T");
    time.run();
  }
  
  // run an initial date process. Should return:
  // hh:mm:ss :
  if (!date.running())  {
    date.begin("date");
//    date.addParameter("+%H:%M");
    date.addParameter("+%d.%m.%y");
    date.run();
  }
}

void loop () {
  
  // restart the date process:
    if (!time.running())  {
      time.begin("date");
      time.addParameter("+%H:%M");
//      time.addParameter("+%T");
      time.run();
    }
    
      timeString = time.readString();
  timeString.toCharArray((char*)disp,10); 

  
   // restart the date process:
    if (!date.running())  {
      date.begin("date");
//      date.addParameter("+%H:%M");
      date.addParameter("+%d.%m.%y");
      date.run();
    }
      dateString = date.readString();
  dateString.toCharArray((char*)dispDate,10); 

  
  
  //HT1632.drawTarget(BUFFER_BOARD(1));
  HT1632.clear();

  HT1632. selectChannel(1); 
  wd = HT1632.getTextWidth(disp, FONT_8X4_END, FONT_8X4_HEIGHT);
  left = (OUT_SIZE - wd) / 2;
  HT1632.drawText(disp, left+1, 1, FONT_8X4, FONT_8X4_END, FONT_8X4_HEIGHT);


  HT1632. selectChannel(0);
  wd = HT1632.getTextWidth(dispDate, FONT_8X4_END, FONT_8X4_HEIGHT);
  left = (OUT_SIZE - wd) / 2;
  HT1632.drawText(dispDate, left+1, 10, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);

  
  HT1632.render();
  
  //i = (i+1)%(wd + OUT_SIZE);
  

}
