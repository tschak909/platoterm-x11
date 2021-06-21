/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 * This file written by Steve Peltz. Copyright notice preserved.
 * and this code has been used with permission, and can be considered
 * public domain.
 *
 * protocol.h - Protocol decoder functions 
 */

/* Copyright (c) 1990 by Steve Peltz */

#ifndef PROTOCOL_H
#define PROTOCOL_H

#define ACCESS	0x3c

typedef	unsigned char	padByte;
typedef	enum {padF, padT} padBool;
typedef	unsigned char	padChar;
typedef	short	padWord;
typedef	padWord	charData[8];
typedef	struct {
	padByte	red,
		green,
		blue;
	} padRGB;

typedef struct {
	padWord	x,
		y;
	} padPt;

typedef enum {ModeWrite, ModeErase, ModeRewrite, ModeInverse} DispMode;
typedef enum {M0, M1, M2, M3} CharMem;

typedef enum {	mBlock, mPoint, mLine, mAlpha, mLoadCoord, mLoadChar, mSSF,
		mExternal, mLoadMem, mMode5, mMode6, mMode7, mLoadAddr,
		mLoadEcho, mFore, mBack, mPaint } Mode;
 
typedef enum {	tByte, tWord, tCoord, tColor, tPaint } DataType;

extern	padPt		PLATOSize;
extern	CharMem		CurMem;
extern	padBool		TTY,
			FlowControl,
			ModeBold,
			Rotate,
			Reverse;
extern	DispMode	CurMode;

#endif
