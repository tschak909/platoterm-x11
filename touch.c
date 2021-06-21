/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * touch.c - Touchscreen functions
 */
#include <X11/Xlib.h>
#include "touch.h"
#include "protocol.h"

/**
 * touch_init() - Set up touch screen
 */
touch_init()
{
}

/**
 * touch_main() - Main loop for touch screen
 */
touch_main(x,y)
int x,y;
{  
	padPt pt;

	pt.x = x;
	pt.y = y^0x1FF;

	Touch(&pt);
}

/**
 * touch_allow - Set whether touchpanel is active or not.
 */
touch_allow(allow)
padBool allow;
{
}

/**
 * handle_mouse - Process mouse events and turn into scaled touch events
 */
handle_mouse()
{
}

/**
 * touch_hide() - hide the mouse cursor
 */
touch_hide()
{
}

/**
 * touch_done() - Stop the mouse driver
 */
touch_done()
{
}

