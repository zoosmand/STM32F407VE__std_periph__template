/*
 * dot_15x21.c
 *
 * Created: 18.12.2019 0:21:34
 *  Author: zoosman
 */ 

#include "fonts.h"


//////////////////////////////////////////////////////////////////////////
const uint8_t font_15x21[(96 * 54)] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // [space]  #32 (0x20)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // !        #33 (0x21)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x38, 0xfe, 0xff, 0x38, 0xfe, 0xff, 0x38, 0xfe, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "        #34 (0x22)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xc0, 0xff, 0x00, 0xc0, 0xff, 0x00, 0xc0, 0xff,  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0xc0, 0xff, 0x00, 0xc0, 0xff, 0x00, 0xc0, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c, // #        #35 (0x23)
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x81, 0x03, 0xc0, 0x81, 0x03, 0xc0, 0x81, 0x03, // $        #36 (0x24)
  0xc0, 0x71, 0x1c, 0xc0, 0x71, 0x1c, 0xc0, 0x71, 0x1c,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0xc0, 0x71, 0x1c, 0xc0, 0x71, 0x1c, 0xc0, 0x71, 0x1c,
  0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0x81, 0xff, 0xf8, 0x81, 0xff, 0xf8, 0x81, 0xff, // %        #37 (0x25)
  0x00, 0x9e, 0xe3, 0x00, 0x9e, 0xe3, 0x00, 0x9e, 0xe3,
  0xf8, 0xf1, 0xff, 0xf8, 0xf1, 0xff, 0xf8, 0xf1, 0xff,
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0xf8, 0x0f, 0xfc, 0xf8, 0x0f, 0xfc, 0xf8, 0x0f, 0xfc, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, // &        #38 (0x26)
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x38, 0x70, 0x00, 0x38, 0x70, 0x00, 0x38, 0x70, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '        #39 (0x27)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xfc, 0x00, 0x00, 0xfc, 0x00, 0x00, 0xfc,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // (        #40 (0x28)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // )        #41 (0x29)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // *        #42 (0x2a)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x70, 0x1c, 0x00, 0x70, 0x1c, 0x00, 0x70, 0x1c,
  0x00, 0x80, 0xff, 0x00, 0x80, 0xff, 0x00, 0x80, 0xff, 
  0x00, 0x70, 0x1c, 0x00, 0x70, 0x1c, 0x00, 0x70, 0x1c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, // +        #43 (0x2b)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ,        #44 (0x2c)
  0xc7, 0x01, 0x00, 0xc7, 0x01, 0x00, 0xc7, 0x01, 0x00,
  0xf8, 0x01, 0x00, 0xf8, 0x01, 0x00, 0xf8, 0x01, 0x00,   
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -        #45 (0x2d)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // .        #46 (0x2e)
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0x01, 0x00, 0xf8, 0x01, 0x00, 0xf8, 0x01, 0x00, // /        #47 (0x2f)
  0x00, 0x0e, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x0e, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0x00, 0x00, 0xfc, 0x00, 0x00, 0xfc, 0x00, 0x00, 0xfc,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, // 0        #48 (0x30)
  0x38, 0x0e, 0xe0, 0x38, 0x0e, 0xe0, 0x38, 0x0e, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x80, 0xe3, 0x38, 0x80, 0xe3, 0x38, 0x80, 0xe3,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 1        #49 (0x31)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0x0f, 0x1c, 0xf8, 0x0f, 0x1c, 0xf8, 0x0f, 0x1c, // 2        #50 (0x32)
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x80, 0x1f, 0x38, 0x80, 0x1f, 0x38, 0x80, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c, // 3        #51 (0x33)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0xf0, 0xff, 0x00, 0xf0, 0xff, 0x00, 0xf0, 0xff, // 4        #52 (0x34)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x38, 0xf0, 0xff, 0x38, 0xf0, 0xff, 0x38, 0xf0, 0xff, // 5        #53 (0x35)
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0xc0, 0x0f, 0xe0, 0xc0, 0x0f, 0xe0, 0xc0, 0x0f, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, // 6        #54 (0x36)
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0xc0, 0x0f, 0xe0, 0xc0, 0x0f, 0xe0, 0xc0, 0x0f, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, // 7        #55 (0x37)
  0xf8, 0x0f, 0xe0, 0xf8, 0x0f, 0xe0, 0xf8, 0x0f, 0xe0,
  0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0,
  0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0,
  0x00, 0x80, 0xff, 0x00, 0x80, 0xff, 0x00, 0x80, 0xff, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, // 8        #56 (0x38)
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x81, 0x1f, 0xc0, 0x81, 0x1f, 0xc0, 0x81, 0x1f, // 9        #57 (0x39)
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // :        #58 (0x3a)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xc0, 0x81, 0x03, 0xc0, 0x81, 0x03, 0xc0, 0x81, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ;        #59 (0x3b)
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0xf8, 0x81, 0x03, 0xf8, 0x81, 0x03, 0xf8, 0x81, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // <        #60 (0x3c)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03,
  0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // =        #61 (0x3d)
  0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03,
  0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03,
  0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03,
  0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // >        #62 (0x3e)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c,
  0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c, // ?        #63 (0x3f)
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0,
  0x38, 0x7e, 0xe0, 0x38, 0x7e, 0xe0, 0x38, 0x7e, 0xe0,
  0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0,
  0x00, 0x80, 0x1f, 0x00, 0x80, 0x1f, 0x00, 0x80, 0x1f, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0x01, 0x1c, 0xf8, 0x01, 0x1c, 0xf8, 0x01, 0x1c, // @        #64 (0x40)
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x8e, 0xe3, 0x38, 0x8e, 0xe3, 0x38, 0x8e, 0xe3, 
  0x38, 0x8e, 0xe3, 0x38, 0x8e, 0xe3, 0x38, 0x8e, 0xe3,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0x1f, 0xf8, 0xff, 0x1f, 0xf8, 0xff, 0x1f, // A        #65 (0x41)
  0x00, 0x06, 0xe0, 0x00, 0x06, 0xe0, 0x00, 0x06, 0xe0,
  0x00, 0x06, 0xe0, 0x00, 0x06, 0xe0, 0x00, 0x06, 0xe0,
  0x00, 0x06, 0xe0, 0x00, 0x06, 0xe0, 0x00, 0x06, 0xe0,
  0xf8, 0xff, 0x1f, 0xf8, 0xff, 0x1f, 0xf8, 0xff, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // B        #66 (0x42)
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, // C        #67 (0x43)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // D        #68 (0x44)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // E        #69 (0x45)
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // F        #70 (0x46)
  0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0,
  0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0,
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0,
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xc0, 0xff, 0xff, // G        #71 (0x47)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0xc0, 0x7f, 0x1c, 0xc0, 0x7f, 0x1c, 0xc0, 0x7f, 0x1c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // H        #72 (0x48)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, // I        #73 (0x49)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x0f, 0xe0, 0xc0, 0x0f, 0xe0, 0xc0, 0x0f, 0xe0, // J        #74 (0x4a)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xc0, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xc0, 0xff, 0xff,
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // K        #75 (0x4b)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x1e, 0x03, 0x00, 0x1e, 0x03, 0x00, 0x1e, 0x03,
  0xf8, 0x01, 0xfc, 0xf8, 0x01, 0xfc, 0xf8, 0x01, 0xfc,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // L        #76 (0x4c)
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // M        #77 (0x4d)
  0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c,
  0x00, 0xf0, 0x03, 0x00, 0xf0, 0x03, 0x00, 0xf0, 0x03,
  0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // N        #78 (0x4e)
  0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, // O        #79 (0x4f)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // P        #80 (0x50)
  0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0,
  0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0,
  0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0,
  0x00, 0x80, 0x1f, 0x00, 0x80, 0x1f, 0x00, 0x80, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, // Q        #81 (0x51)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xf8, 0x01, 0xe0, 0xf8, 0x01, 0xe0, 0xf8, 0x01, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // R        #82 (0x52)
  0x00, 0x0e, 0xe0, 0x00, 0x0e, 0xe0, 0x00, 0x0e, 0xe0,
  0x00, 0x0e, 0xe0, 0x00, 0x0e, 0xe0, 0x00, 0x0e, 0xe0,
  0x00, 0x0e, 0xe0, 0x00, 0x0e, 0xe0, 0x00, 0x0e, 0xe0,
  0xf8, 0xf1, 0x1f, 0xf8, 0xf1, 0x1f, 0xf8, 0xf1, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x38, 0x80, 0x1f, 0x38, 0x80, 0x1f, 0x38, 0x80, 0x1f, // S        #83 (0x53)
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0xc0, 0x0f, 0xe0, 0xc0, 0x0f, 0xe0, 0xc0, 0x0f, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, // T        #84 (0x54)
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0,
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xc0, 0xff, 0xff, // U        #85 (0x55)
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0xc0, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xc0, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0xfe, 0xff, 0x00, 0xfe, 0xff, 0x00, 0xfe, 0xff, // V        #86 (0x56)
  0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00,
  0x00, 0xfe, 0xff, 0x00, 0xfe, 0xff, 0x00, 0xfe, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // W        #87 (0x57)
  0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00,
  0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00,
  0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0x01, 0xfc, 0xf8, 0x01, 0xfc, 0xf8, 0x01, 0xfc, // X        #88 (0x58)
  0x00, 0x1c, 0x03, 0x00, 0x1c, 0x03, 0x00, 0x1c, 0x03,
  0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00,
  0x00, 0x1c, 0x03, 0x00, 0x1c, 0x03, 0x00, 0x1c, 0x03,
  0xf8, 0x01, 0xfc, 0xf8, 0x01, 0xfc, 0xf8, 0x01, 0xfc,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x80, 0xff, 0x00, 0x80, 0xff, 0x00, 0x80, 0xff, // Y        #89 (0x59)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0xf8, 0x0f, 0x00, 0xf8, 0x0f, 0x00, 0xf8, 0x0f, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x80, 0xff, 0x00, 0x80, 0xff, 0x00, 0x80, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0x01, 0xe0, 0xf8, 0x01, 0xe0, 0xf8, 0x01, 0xe0, // Z        #90 (0x5a)
  0x38, 0x0e, 0xe0, 0x38, 0x0e, 0xe0, 0x38, 0x0e, 0xe0,
  0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0, 0x38, 0x70, 0xe0,
  0x38, 0x80, 0xe3, 0x38, 0x80, 0xe3, 0x38, 0x80, 0xe3,
  0x38, 0x00, 0xfc, 0x38, 0x00, 0xfc, 0x38, 0x00, 0xfc,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // [        #91 (0x5b)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0xfc, 0x00, 0x00, 0xfc, 0x00, 0x00, 0xfc, // \        #92 (0x5c)
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x0e, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x0e, 0x00,
  0xf8, 0x01, 0x00, 0xf8, 0x01, 0x00, 0xf8, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, // ]        #93 (0x5d)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, // ^        #94 (0x5e)
  0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c,
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 
  0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, // _        #95 (0x5f)
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // `        #96 (0x60)
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0,
  0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x1c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x81, 0x03, 0xc0, 0x81, 0x03, 0xc0, 0x81, 0x03, // a        #97 (0x61)
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0xf8, 0x7f, 0x00, 0xf8, 0x7f, 0x00, 0xf8, 0x7f, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // b        #98 (0x62)
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00, // c        #99 (0x63)
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x38, 0x70, 0x00, 0x38, 0x70, 0x00, 0x38, 0x70, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00, // d        #100 (0x64)
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00, // e        #101 (0x65)
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0x38, 0x7e, 0x00, 0x38, 0x7e, 0x00, 0x38, 0x7e, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, // f        #102 (0x66)
  0xf8, 0xff, 0x1f, 0xf8, 0xff, 0x1f, 0xf8, 0xff, 0x1f,
  0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0,
  0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0, 0x00, 0x70, 0xe0,
  0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, // g        #103 (0x67)
  0x38, 0xf0, 0xe3, 0x38, 0xf0, 0xe3, 0x38, 0xf0, 0xe3,
  0x38, 0x8e, 0xe3, 0x38, 0x8e, 0xe3, 0x38, 0x8e, 0xe3,
  0x38, 0x8e, 0xff, 0x38, 0x8e, 0xff, 0x38, 0x8e, 0xff,
  0xc0, 0x0f, 0xe0, 0xc0, 0x0f, 0xe0, 0xc0, 0x0f, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // h        #104 (0x68)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0xf8, 0x7f, 0x00, 0xf8, 0x7f, 0x00, 0xf8, 0x7f, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // i        #105 (0x69)
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0xf8, 0xff, 0xe3, 0xf8, 0xff, 0xe3, 0xf8, 0xff, 0xe3,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00, // j        #106 (0x6a)
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0xc0, 0xff, 0xe1, 0xc0, 0xff, 0xe1, 0xc0, 0xff, 0xe1,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, // k        #107 (0x6b)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03, 0x00, 0x8e, 0x03,
  0xf8, 0x01, 0x1c, 0xf8, 0x01, 0x1c, 0xf8, 0x01, 0x1c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // l        #108 (0x6c)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0x01, 0xf8, 0xff, 0x01, 0xf8, 0xff, 0x01, // m        #109 (0x6d)
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0xf8, 0x7f, 0x00, 0xf8, 0x7f, 0x00, 0xf8, 0x7f, 0x00,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0xf8, 0xff, 0x01, 0xf8, 0xff, 0x01, 0xf8, 0xff, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0x03, 0xf8, 0xff, 0x03, 0xf8, 0xff, 0x03, // n        #110 (0x6e)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0xf8, 0x7f, 0x00, 0xf8, 0x7f, 0x00, 0xf8, 0x7f, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00, // o        #111 (0x6f)
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00, 0xc0, 0x7f, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xf8, 0xff, 0x1f, 0xf8, 0xff, 0x1f, 0xf8, 0xff, 0x1f, // p        #112 (0x70)
  0x38, 0x0e, 0x1c, 0x38, 0x0e, 0x1c, 0x38, 0x0e, 0x1c,
  0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c,
  0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c,
  0x00, 0xf0, 0x03, 0x00, 0xf0, 0x03, 0x00, 0xf0, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0xf0, 0x03, 0x00, 0xf0, 0x03, 0x00, 0xf0, 0x03, // q        #113 (0x71)
  0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c,
  0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c, 0x00, 0x0e, 0x1c,
  0x38, 0x0e, 0x1c, 0x38, 0x0e, 0x1c, 0x38, 0x0e, 0x1c,
  0xf8, 0xff, 0x1f, 0xf8, 0xff, 0x1f, 0xf8, 0xff, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, // r        #114 (0x72)
  0xf8, 0xff, 0x03, 0xf8, 0xff, 0x03, 0xf8, 0xff, 0x03,
  0x38, 0x70, 0x00, 0x38, 0x70, 0x00, 0x38, 0x70, 0x00,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x38, 0x70, 0x00, 0x38, 0x70, 0x00, 0x38, 0x70, 0x00, // s        #115 (0x73)
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0xc0, 0x81, 0x03, 0xc0, 0x81, 0x03, 0xc0, 0x81, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // t        #116 (0x74)
  0xc0, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xc0, 0xff, 0xff,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0xff, 0x03, 0xc0, 0xff, 0x03, 0xc0, 0xff, 0x03, // u        #117 (0x75)
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00,
  0xf8, 0xff, 0x03, 0xf8, 0xff, 0x03, 0xf8, 0xff, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0xfe, 0x03, 0x00, 0xfe, 0x03, 0x00, 0xfe, 0x03, // v        #118 (0x76)
  0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00, 0xc0, 0x01, 0x00,
  0x00, 0xfe, 0x03, 0x00, 0xfe, 0x03, 0x00, 0xfe, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0xff, 0x03, 0xc0, 0xff, 0x03, 0xc0, 0xff, 0x03, // w        #119 (0x77)
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0xc0, 0x0f, 0x00, 0xc0, 0x0f, 0x00, 0xc0, 0x0f, 0x00,
  0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00,
  0xc0, 0xff, 0x03, 0xc0, 0xff, 0x03, 0xc0, 0xff, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03, // x        #120 (0x78)
  0xc0, 0x71, 0x00, 0xc0, 0x71, 0x00, 0xc0, 0x71, 0x00,
  0x00, 0x0e, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x0e, 0x00,
  0xc0, 0x71, 0x00, 0xc0, 0x71, 0x00, 0xc0, 0x71, 0x00,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x38, 0xfe, 0x1f, 0x38, 0xfe, 0x1f, 0x38, 0xfe, 0x1f, // y        #121 (0x79)
  0x38, 0x0e, 0x00, 0x38, 0x0e, 0x00, 0x38, 0x0e, 0x00,
  0x38, 0x0e, 0x00, 0x38, 0x0e, 0x00, 0x38, 0x0e, 0x00,
  0x38, 0x0e, 0x00, 0x38, 0x0e, 0x00, 0x38, 0x0e, 0x00,
  0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f, 0xc0, 0xff, 0x1f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03, // z        #122 (0x7a)
  0xf8, 0x81, 0x03, 0xf8, 0x81, 0x03, 0xf8, 0x81, 0x03,
  0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03, 0x38, 0x8e, 0x03,
  0x38, 0xf0, 0x03, 0x38, 0xf0, 0x03, 0x38, 0xf0, 0x03,
  0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, // {        #123 (0x7b)
  0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // |        #124 (0x7c)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c, 0xc0, 0x01, 0x1c, // }        #125 (0x7d)
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0, 0x38, 0x00, 0xe0,
  0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f, 0xc0, 0x8f, 0x1f,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ~        #126 (0x7e)
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00,
  0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // �        #176 (0xb0)
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x18, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x66,
  0x00, 0x00, 0x66, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
