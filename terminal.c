/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * terminal.c - Terminal state functions
 */

/* Some functions are intentionally stubbed. */

#include <string.h>
#include "terminal.h"

#define TRUE 1
#define FALSE 0

/**
 * ASCII Features to return in Features
 */
#define ASC_ZFGT        0x01
#define ASC_ZPCKEYS     0x02
#define ASC_ZKERMIT     0x04
#define ASC_ZWINDOW     0x08

/**
 * protocol.c externals
 */
extern CharMem CurMem;
extern padBool TTY;
extern padBool ModeBold;
extern padBool Rotate;
extern padBool Reverse;
extern DispMode CurMode;
extern padBool FlowControl;

/**
 * screen.c externals
 */
extern unsigned char CharWide;
extern unsigned char CharHigh;
extern padPt TTYLoc;

extern unsigned char already_started;
extern unsigned char fontm23[2048];

static unsigned char BTAB[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
static unsigned char u;
static unsigned char curr_word;

#define FONTPTR(a) (a<<4)

/**
 * terminal_init()
 * Initialize terminal state
 */
terminal_init()
{
  terminal_set_tty();
}

/**
 * terminal_initial_position()
 * Set terminal initial position after splash screen.
 */
terminal_initial_position()
{
  TTYLoc.x=0;
  TTYLoc.y=495; 
}

/**
 * terminal_set_tty() - Switch to TTY mode
 */
terminal_set_tty()
{
  if (already_started)
    screen_clear();
  TTY=TRUE;
  ModeBold=padF;
  Rotate=padF;
  Reverse=padF;
  CurMem=M0;
  CurMode=ModeRewrite; 
  CharWide=8;
  CharHigh=16;
  TTYLoc.x = 0;        
  TTYLoc.y = 495;      
}

/**
 * terminal_set_plato() - Switch to PLATO mode
 */
terminal_set_plato()
{
  TTY=FALSE;
  screen_clear();
}

/**
 * terminal_get_features() - Inquire about terminal ASCII features
 */
unsigned char terminal_get_features()
{
  return ASC_ZFGT; /* This terminal can do Fine Grained Touch (FGT) */
}

/**
 * terminal_get_type() - Return the appropriate terminal type
 */
unsigned char terminal_get_type()
{
  return 12; /* ASCII terminal type */
}

/**
 * terminal_get_subtype() - Return the appropriate terminal subtype
 */
unsigned char terminal_get_subtype()
{
  return 1; /* ASCII terminal subtype IST-III */
}

/**
 * terminal_get_load_file() - Return the appropriate terminal loadfile (should just be 0)
 */
unsigned char terminal_get_load_file()
{
  return 0; /* This terminal does not load its resident from the PLATO system. */
}

/**
 * terminal_get_configuration() - Return the terminal configuration
 */
unsigned char terminal_get_configuration()
{
  return 0x40; /* Touch panel is present. */
}

/**
 * terminal_get_char_address() - Return the base address of the character set.
 */
unsigned short terminal_get_char_address()
{
  return 0x3000; /* What the? Shouldn't this be 0x3800? */
}

/**
 * terminal_mem_read - Read a byte of program memory.
 * not needed for our terminal, but must
 * be decoded.
 */
padByte terminal_mem_read(addr)
padWord addr;
{
  return (0xFF);
}

/**
 * terminal_mem_load - Write a byte to non-character memory.
 * not needed for our terminal, but must be decoded.
 */
terminal_mem_load(addr, value)
padWord addr, value;
{
  /* Not Implemented */
}

/**
 * Mode5, 6, and 7 are basically stubbed.
 */
terminal_mode_5(value)
padWord value;
{ 
}

terminal_mode_6(value)
padWord value;
{ 
}

terminal_mode_7(value)
padWord value;
{ 
}

/**
 * terminal_ext_allow - External Input allowed. Not implemented.
 */
terminal_ext_allow(allow)
padBool allow;
{
  /* Not Implemented */
}

/**
 * terminal_set_ext_in - Set which device to get input from.
 * Not implemented
 */
terminal_set_ext_in(device)
padWord device;
{
}

/**
 * terminal_set_ext_out - Set which device to send external data to.
 * Not implemented
 */
terminal_set_ext_out(device)
padWord device;
{
}

/**
 * terminal_ext_in - get an external input from selected device.
 * Not implemented.
 */
padByte terminal_ext_in()
{
  return 0;
}

/**
 * terminal_ext_out - Send an external output to selected device
 * Not implemented.
 */
terminal_ext_out(value)
padByte value;
{
}

/**
 * terminal_char_load - Store a character into the user definable
 * character set.
 */
terminal_char_load(charnum, theChar)
padWord charnum;
charData theChar;
{
  memset(&fontm23[(charnum*16)],0,16);
  for (curr_word=0;curr_word<8;curr_word++)
    {
      for (u=16; u-->0; )
  	{
  	  if (theChar[curr_word] & 1<<u)
  	    {
	      fontm23[(charnum*16+u)^0x0f]|=BTAB[curr_word];
  	    }
  	}
    }
}
