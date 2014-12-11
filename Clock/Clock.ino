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

#define HT1632_CLK 4
#define HT1632_CS 5
#define HT1632_DATA 7
#define HT1632_WR 6

#define BUTTON_RED 8
#define BUTTON_YELLOW 10
#define BUTTON_WHITE 11
#define BUTTON_GREEN 12
#define BUTTON_BLUE 3 
#define BUTTON_BLACK 2 

#define SPEAKER 9


byte update [] = "update";
byte ntp [] = "ntp";
byte done [] = "done";
byte disp [7];
byte dispDate [10];
byte dispSecond [4];

String dateString;
String timeString;
String secondString;

int left, wd;

Process date;


void setup () {
  Bridge.begin();
  HT1632.setCLK(HT1632_CLK);
  HT1632.begin(HT1632_CS, HT1632_WR, HT1632_DATA);

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
    date.addParameter("+%T%d.%b");
    date.run();
  }

  dateString = date.readString();

  timeString = dateString.substring(0,8);
  secondString = timeString.substring(6);
  timeString = timeString.substring(0,5);
  dateString = dateString.substring(8);

  dateString.toCharArray((char*)dispDate,10);
  timeString.toCharArray((char*)disp,7);
  secondString.toCharArray((char*)dispSecond,4);

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
}
