/* 
 * 8-high FONT FOR RENDERING TO THE LED SCREEN.
 * 8 pixels-per-byte, variable width.
 *
 * By Gaurav Manek, 2014.
 * Based loosely on the font by Louis Roy, based on 7x5 by David Soyez, 2013
 */

#ifndef __FONTCLOCK_H
#define __FONTCLOCK_H

#define FONT_CLOCK_HEIGHT  8

const byte FONT_CLOCK [] PROGMEM = {
  0b00000000,                                                   // SPACE
  0b01110000, 0b11111101, 0b01110000,                           // !
  0b11000000, 0b00000000, 0b11000000,                           // "
  0b00100100, 0b11111111, 0b00100100, 0b11111111, 0b00100100,   // #
  0b00100100, 0b01010010, 0b11011011, 0b01001010, 0b00100100,   // $
  0b11000001, 0b11000110, 0b00011000, 0b01100011, 0b10000011,   // %
  0b01101110, 0b10010001, 0b10010010, 0b01100101,               // &
  0b11000000,                                                   // '
  0b00111100, 0b01000010, 0b10000001,                           // (
  0b10000001, 0b01000010, 0b00111100,                           // )
  0b10100000, 0b01000000, 0b10100000,                           // *
  0b00001000, 0b00001000, 0b00111110, 0b00001000, 0b00001000,   // +
  0b00000001, 0b00000010,                                       // ,
  0b00001000, 0b00001000, 0b00001000,                           // -
  0b00000001,                                                   // .
  0b00000011, 0b00001100, 0b00110000, 0b11000000,               // /
  0b01111110, 0b10110001, 0b10001101, 0b01111110,               // 0
  0b01000001, 0b11111111, 0b00000001,                           // 1
  0b01000011, 0b10000101, 0b10001001, 0b01110001,               // 2
  0b01000010, 0b10001001, 0b10001001, 0b01110110,               // 3
  0b00011100, 0b00100100, 0b01001111, 0b10000100,               // 4
  0b11110001, 0b10010001, 0b10010001, 0b10001110,               // 5
  0b01111110, 0b10001001, 0b10001001, 0b01000110,               // 6
  0b10000000, 0b10000111, 0b10011000, 0b11100000,               // 7
  0b01110110, 0b10001001, 0b10001001, 0b01110110,               // 8
  0b01110010, 0b10001001, 0b10001001, 0b01111110,               // 9
  0b00100010,                                                   // :
  0b00000001, 0b00100010,                                       // ;
  0b00011000, 0b00100100, 0b01000010, 0b10000001,               // <
  0b00010100, 0b00010100, 0b00010100, 0b00010100,               // =
  0b10000001, 0b01000010, 0b00100100, 0b00011000,               // >
  0b01000000, 0b10001101, 0b10001000, 0b01110000,               // ?
  0b01111110, 0b10000001, 0b10111001, 0b10000101, 0b01111100,   // @
  0b01111111, 0b10001000, 0b10001000, 0b01111111,               // A
  0b11111111, 0b10001001, 0b10001001, 0b01110110,               // B
  0b01111110, 0b10000001, 0b10000001, 0b01000010,               // C
  0b11111111, 0b10000001, 0b10000001, 0b01111110,               // D
  0b11111111, 0b10001001, 0b10001001, 0b10000001,               // E
  0b11111111, 0b10010000, 0b10010000, 0b10000000,               // F
  0b01111110, 0b10000001, 0b10001001, 0b01001110,               // G
  0b11111111, 0b00001000, 0b00001000, 0b11111111,               // H
  0b10000001, 0b11111111, 0b10000001,                           // I
  0b10000110, 0b10000001, 0b10000001, 0b11111110,               // J
  0b11111111, 0b00010000, 0b00101000, 0b11000111,               // K
  0b11111111, 0b00000001, 0b00000001, 0b00000001,               // L
  0b01111111, 0b11000000, 0b00110000, 0b11000000, 0b01111111,   // M
  0b11111111, 0b01100000, 0b00011000, 0b00000110, 0b11111111,   // N
  0b01111110, 0b10000001, 0b10000001, 0b01111110,               // O
  0b11111111, 0b10001000, 0b10001000, 0b01110000,               // P
  0b01111110, 0b10000001, 0b10000101, 0b10000010, 0b01111101,   // Q
  0b11111111, 0b10001000, 0b10001100, 0b01110011,               // R
  0b01100010, 0b10010001, 0b10001001, 0b01000110,               // S
  0b10000000, 0b11111111, 0b10000000,                           // T
  0b11111110, 0b00000001, 0b00000001, 0b11111110,               // U
  0b11111110, 0b00000001, 0b00000110, 0b11111000,               // V
  0b11111100, 0b00000011, 0b00011100, 0b00000011, 0b11111100,   // W
  0b10000001, 0b01100110, 0b00011000, 0b01100110, 0b10000001,   // X
  0b11000000, 0b00110000, 0b00001111, 0b00110000, 0b11000000,   // Y
  0b10000011, 0b10001101, 0b10110001, 0b11000001,               // Z
  0b11111111, 0b10000001,                                       // [
  0b11000000, 0b00110000, 0b00001100, 0b00000011,               // \
  0b10000001, 0b11111111,                                       // ]
  0b01000000, 0b10000000, 0b01000000,                           // ^
  0b00000001, 0b00000001, 0b00000001, 0b00000001,               // _
};

  int FONT_CLOCK_END [] = {
         1,   4,   7,  12,  17,  22,  26,  27,
      30,  33,  36,  41,  43,  46,  47,  51,
      55,  58,  62,  66,  70,  74,  78,  82,
      86,  90,  91,  93,  97, 101, 105, 109,
     114, 118, 122, 126, 130, 134, 138, 142,
     146, 149, 153, 157, 161, 166, 171, 175,
     179, 184, 188, 192, 195, 199, 203, 208,
     213, 218, 222, 224, 228, 230, 233, 237
};

#endif  // __FONT8X4_H
