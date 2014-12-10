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
byte update [] = "update";
byte ntp [] = "ntp";
byte done [] = "done";
byte disp [10];
byte dispDate [10];
byte dispSecond [4];
byte dispSecondDigit1 [2];
String timeString;
Process date;
String dateString;
String secondString;
String secondStringDigit1;
int left;

void setup () {
  Bridge.begin();
  HT1632.setCLK(4);
  HT1632.begin(5, 6, 7);
//  wd = HT1632.getTextWidth(disp, FONT_8X4_END, FONT_8X4_HEIGHT);



  HT1632.clear();
  HT1632.drawText(update, 4, 2, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);
  HT1632.drawText(ntp, 10, 9, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);
  HT1632.render();
  
  Process p;
  p.runShellCommand("ntpd -qn -p 0.pool.ntp.org");

  HT1632.clear();
  HT1632. selectChannel(1);
  HT1632.drawText(done, 7, 5, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);
  HT1632. selectChannel(0);
  HT1632.drawText(done, 7, 5, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);
  HT1632.render();

}

void loop () {

  HT1632.clear();


   // restart the date process:
    if (!date.running())  {
      date.begin("date");
//      date.addParameter("+%H:%M");
      date.addParameter("+%T%d.%m.%y");
      date.run();
    }
      dateString = date.readString();

      Serial.println(dateString);

      timeString = dateString.substring(0,8);
      secondString = timeString.substring(6);
      //secondStringDigit1 = secondString.substring(1);
      //secondString = secondString.substring(0, 1);

      timeString = timeString.substring(0,5);
      dateString = dateString.substring(8);



  dateString.toCharArray((char*)dispDate,10);
  timeString.toCharArray((char*)disp,10);
  secondString.toCharArray((char*)dispSecond,4);
  secondStringDigit1.toCharArray((char*)dispSecondDigit1,4);





  HT1632. selectChannel(1);
  wd = HT1632.getTextWidth(disp, FONT_8X4_END, FONT_8X4_HEIGHT);
  left = (OUT_SIZE - wd) / 2;
  HT1632.drawText(disp, 1, 1, FONT_8X4, FONT_8X4_END, FONT_8X4_HEIGHT);

  HT1632.drawText(dispSecond, 23, 3, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);
  HT1632. selectChannel(0);
  HT1632.drawText(dispSecond, 23, 3, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);



  HT1632. selectChannel(0);
  wd = HT1632.getTextWidth(dispDate, FONT_8X4_END, FONT_8X4_HEIGHT);
  left = (OUT_SIZE - wd) / 2;
  HT1632.drawText(dispDate, left+1, 10, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);


  HT1632.render();

  //i = (i+1)%(wd + OUT_SIZE);


}
