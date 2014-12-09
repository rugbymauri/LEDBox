#include <HT1632.h>
#include <font_5x4.h>
#include <images.h>

int i = 0;
int j = 0;



const byte IMG_TREE [] PROGMEM = {
0b00000000, 0b11001110, 0b00001001, 0b10011100, 0b00011011, 0b10111000, 0b00111111, 0b11111111, 0b11111111, 0b11111111, 0b00111111, 0b11111111, 0b00011011, 0b10111000, 0b00001001, 0b10011100, 0b00000000, 0b11001110
};
#define IMG_TREE_WIDTH 	 9
#define IMG_TREE_HEIGHT  16

void setup () {
  // Working with Bicolor displays.
  // Make sure that a bicolor display is set in HT1632.h  
  HT1632.setCLK(4);
  HT1632.begin(5, 6, 7);
}

void loop () {
  // Zero all data in all channels:
  HT1632.clear();
  
  if (~i & 0b01) { // On frames 1 and 3:
    HT1632.selectChannel(0); // Select the first channel
    // Draw a heart:
    HT1632.drawImage(IMG_TREE, IMG_TREE_WIDTH,  IMG_TREE_HEIGHT, j - IMG_TREE_WIDTH, 0);
  }
  
  if (~i & 0b10) { // On frames 2 and 3:
    HT1632.selectChannel(1); // Select the second channel
    // Draw a heart:
    HT1632.drawImage(IMG_TREE, IMG_TREE_WIDTH,  IMG_TREE_HEIGHT, j - IMG_TREE_WIDTH, 0);
  }
  
  HT1632.render(); // This sends the data in both channels to the screen.

  // Get the next number in the sequence, wrapping from 3 back to 0:
  i = (i + 1) % 3;
  j = (j + 1) % (OUT_SIZE + IMG_TREE_WIDTH * 2);
  
  delay(300);  
}
