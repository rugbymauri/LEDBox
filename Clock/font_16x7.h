/*
 * 8-high FONT FOR RENDERING TO THE LED SCREEN.
 * 8 pixels-per-byte, variable width.
 *
 * By Gaurav Manek, 2014.
 * Based loosely on the font by Louis Roy, based on 7x5 by David Soyez, 2013
 */

#ifndef __FONTCLOCK_H
#define __FONTCLOCK_H

#define FONT_CLOCK_HEIGHT  16

const byte FONT_CLOCK [] PROGMEM = {
 	0b00000000, 0b00000000,  //
	0b00000000, 0b00001111, 0b00001111, 0b10110000, 0b10110000, 0b00000000,  // !
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11000000,  // "
	0b00000000, 0b00001100, 0b00001100, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000101,  // #
	0b00000000, 0b01010000, 0b01010000, 0b11111000, 0b11111000, 0b01010000, 0b01010000, 0b11111000,  // $
	0b00001111, 0b10000101, 0b10000101, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,  // %
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11001000,  // &
	0b00001100, 0b10001101,  // '
	0b01011000, 0b10011000, 0b10011000, 0b01010000, 0b01010000, 0b10101000,  // (
	0b10001001, 0b10000101, 0b10000101, 0b10000000, 0b10000000, 0b00001100,  // )
	0b11000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,  // *
	0b00000000, 0b00000111, 0b00000111, 0b00001000, 0b00001000, 0b10000000, 0b10000000, 0b00000000,  // +
	0b00000000, 0b00000000, 0b00000000, 0b00000000,  // ,
	0b10000111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001010,  // -
	0b00000000, 0b10100000, 0b10100000, 0b01000000,  // .
	0b00000000, 0b00000000, 0b00000000, 0b00000010, 0b00000010, 0b00000010, 0b00000010, 0b00001111,  // /
	0b00100000, 0b11111000, 0b11111000, 0b00100000, 0b00100000, 0b00100000, 0b00100000, 0b00001000,  // 0
	0b00000000, 0b10000001, 0b10000001, 0b00000000, 0b00000000, 0b00000000,  // 1
	0b00000000, 0b00000000, 0b00000000, 0b00100000, 0b00100000, 0b00100000, 0b00100000, 0b00100000,  // 2
	0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10000000,  // 3
	0b00001000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,  // 4
	0b00000000, 0b00000000, 0b00000000, 0b10000011, 0b10000011, 0b00000110, 0b00000110, 0b00001000,  // 5
	0b01100000, 0b10000000, 0b10000000, 0b00000000, 0b00000000, 0b01111110, 0b01111110, 0b10000001,  // 6
	0b11101000, 0b00010111, 0b00010111, 0b11100000, 0b11100000, 0b00000000, 0b00000000, 0b00000100,  // 7
	0b00000000, 0b01000001, 0b01000001, 0b11111111, 0b11111111, 0b00000001, 0b00000001, 0b00000000,  // 8
	0b00010000, 0b00000000, 0b00000000, 0b00000100, 0b00000100, 0b01111000, 0b01111000, 0b10010111,  // 9
	0b10001001, 0b01110001,  // :
	0b00001000, 0b10011000, 0b10011000, 0b10011111,  // ;
	0b00000000, 0b00000000, 0b00000000, 0b11110000, 0b11110000, 0b00010000, 0b00010000, 0b11111111,  // <
	0b00001111, 0b11110000, 0b11110000, 0b00000000, 0b00000000, 0b00001111, 0b00001111, 0b00011001,  // =
	0b11110001, 0b10010001, 0b10010001, 0b10011111, 0b10011111, 0b00000000, 0b00000000, 0b00000000,  // >
	0b00000000, 0b00001111, 0b00001111, 0b11111001, 0b11111001, 0b00011001, 0b00011001, 0b11110000,  // ?
	0b10011111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10001111, 0b10001111, 0b10010000,  // @
	0b11111001, 0b00001110, 0b00001110, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001111,  // A
	0b00000000, 0b11111111, 0b11111111, 0b10010001, 0b10010001, 0b11111111, 0b11111111, 0b00000000,  // B
	0b11110000, 0b00000000, 0b00000000, 0b00001111, 0b00001111, 0b00011001, 0b00011001, 0b00011111,  // C
	0b10010001, 0b11111111, 0b11111111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00100100,  // D
	0b00000010, 0b01000000, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,  // E
	0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00001000, 0b01010000, 0b01010000, 0b00000000,  // F
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000010, 0b00000010, 0b00000101,  // G
	0b00100000, 0b01010000, 0b01010000, 0b10001000, 0b10001000, 0b00000000, 0b00000000, 0b00000000,  // H
	0b00000000, 0b00000101, 0b00000101, 0b00000101, 0b00000101, 0b00000101,  // I
	0b01010000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10001000, 0b10001000, 0b01010000,  // J
	0b10000101, 0b00000010, 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000100,  // K
	0b00000000, 0b01000000, 0b01000000, 0b10000000, 0b10000000, 0b10011000, 0b10011000, 0b01100000,  // L
	0b10000110, 0b00000000, 0b00000000, 0b00000111, 0b00000111, 0b00001000, 0b00001000, 0b00001011,  // M
	0b10000000, 0b10110000, 0b10110000, 0b10101000, 0b10101000, 0b11110000, 0b11110000, 0b11111111,  // N
	0b00001111, 0b11111001, 0b11111001, 0b00001001, 0b00001001, 0b00001111, 0b00001111, 0b11110000,  // O
	0b11111111, 0b00000000, 0b00000000, 0b11111111, 0b11111111, 0b10010001, 0b10010001, 0b10010001,  // P
	0b00011001, 0b00011110, 0b00011110, 0b11110000, 0b11110000, 0b00001111, 0b00001111, 0b11111000,  // Q
	0b11111111, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b11000011, 0b11000011, 0b00000000,  // R
	0b00110000, 0b00001111, 0b00001111, 0b11111000, 0b11111000, 0b00011000, 0b00011000, 0b00010111,  // S
	0b10000001, 0b01111110, 0b01111110, 0b00000000, 0b00000000, 0b11111111, 0b11111111, 0b10010001,  // T
	0b11111001, 0b00011001, 0b00011001, 0b00011000, 0b00011000, 0b00010000, 0b00010000, 0b00001111,  // U
	0b00000000, 0b11111111, 0b11111111, 0b10010000, 0b10010000, 0b10010000, 0b10010000, 0b10000000,  // V
	0b00001000, 0b00000000, 0b00000000, 0b00001111, 0b00001111, 0b11111000, 0b11111000, 0b00011001,  // W
	0b10000001, 0b10010001, 0b10010001, 0b10011111, 0b10011111, 0b00000000, 0b00000000, 0b11111111,  // X
	0b00001111, 0b11110001, 0b11110001, 0b00000001, 0b00000001, 0b00001111, 0b00001111, 0b11110000,  // Y
	0b11111111, 0b00000000, 0b00000000, 0b10000001, 0b10000001, 0b11111111, 0b11111111, 0b10000001,  // Z
	0b11111000, 0b00010000, 0b00010000, 0b00000000, 0b00000000, 0b00001000,  // [
	0b10000011, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b11111111, 0b11111111, 0b00000000,  // \
	0b11110000, 0b00001111, 0b00001111, 0b11110001, 0b11110001, 0b00000010,  // ]
	0b00101000, 0b11000111, 0b11000111, 0b00000000, 0b00000000, 0b11111111, 0b11111111, 0b00000001,  // ^
	0b11110000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00010000, 0b00001111, 0b00001111, 0b11110110,  // _
};

  int FONT_CLOCK_END [] = {
       1,   4,   7,  11,  15,  19,  23,  24,
	  27,  30,  34,  38,  40,  44,  46,  50,
	  54,  57,  61,  65,  69,  73,  77,  81,
	  85,  89,  90,  92,  96, 100, 104, 108,
	 112, 116, 120, 124, 128, 132, 136, 140,
	 144, 147, 151, 155, 159, 163, 167, 171,
	 175, 179, 183, 187, 191, 195, 199, 203,
	 207, 211, 215, 218, 222, 225, 229, 234
};

#endif  // __FONT8X4_H