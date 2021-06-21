#include <X11/Xlib.h>
#include <X11/keysym.h>
#include "keyboard.h"
#include "protocol.h"
#include "key.h"

#define TRUE 1
#define FALSE 0

unsigned char ch;

keyboard_out(platoKey)
unsigned char platoKey;
{
  if (platoKey==0xff)
    return;
  
  if (platoKey>0x7F)
    {
      Key(ACCESS);
      Key(ACCESS_KEYS[platoKey-0x80]);
      return;
    }
  Key(platoKey);
  return;
}

keyboard_main(ks,control_pressed,shift_pressed)
KeySym ks;
unsigned char control_pressed, shift_pressed;
{
	int k=-1;

	switch(ks)
	{
		case XK_BackSpace:
			k=(shift_pressed == TRUE ? PKEY_ERASE1 : PKEY_ERASE);
			break;
		case XK_Tab:
			k=PKEY_TAB;
			break;
		case XK_Return:
			k=(shift_pressed == TRUE ? PKEY_NEXT1 : PKEY_NEXT);
			break;
		case XK_Escape:
			k=PKEY_ASSIGN;
			break;
		case XK_space:
			k=(shift_pressed == TRUE ? PKEY_BACKSPACE : PKEY_SPACE);
			break;
		case XK_exclam:
			k=PKEY_EXCLAMATION;
			break;
		case XK_quotedbl:
			k=PKEY_QUOTE;
			break;
		case XK_numbersign:
			k=PKEY_POUND;
			break;
		case XK_dollar:
			k=PKEY_DOLLAR;
			break;
		case XK_percent:
			k=PKEY_PERCENT;
			break;
		case XK_ampersand:
			k=PKEY_AMPERSAND;
			break;
		case XK_apostrophe:
			k=PKEY_APOSTROPHE;
			break;
		case XK_parenleft:
			k=PKEY_PARENTHESIS_LEFT;
			break;
		case XK_parenright:
			k=PKEY_PARENTHESIS_RIGHT;
			break;
		case XK_asterisk:
			k=PKEY_ASTERISK;
			break;
		case XK_plus:
			if (control_pressed)
				k=PKEY_SIGMA;
			else
				k=PKEY_PLUS;
			break;
		case XK_comma:
			k=PKEY_COMMA;
			break;
		case XK_minus:
			if (control_pressed)
				k=PKEY_DELTA;
			else
				k=PKEY_MINUS;
			break;
		case XK_period:
			k=PKEY_PERIOD;
			break;
		case XK_slash:
			k=PKEY_SLASH;
			break;
		case XK_0:
		case XK_KP_0:
			k=PKEY_0;
			break;
		case XK_1:
		case XK_KP_1:
			k=PKEY_1;
			break;
		case XK_2:
		case XK_KP_2:
			k=PKEY_2;
			break;
		case XK_KP_3:
		case XK_3:
			k=PKEY_3;
			break;
		case XK_KP_4:
		case XK_4:
			k=PKEY_4;
			break;
		case XK_KP_5:
		case XK_5:
			k=PKEY_5;
			break;
		case XK_KP_6:
		case XK_6:
			k=PKEY_6;
			break;
		case XK_KP_7:
		case XK_7:
			k=PKEY_7;
			break;
		case XK_KP_8:
		case XK_8:
			k=PKEY_8;
			break;
		case XK_KP_9:
		case XK_9:
			k=PKEY_9;
			break;
		case XK_colon:
			k=PKEY_COLON;
			break;
		case XK_semicolon:
			k=PKEY_SEMICOLON;
			break;
		case XK_less:
			k=PKEY_LESS_THAN;
			break;
		case XK_equal:
			k=PKEY_EQUALS;
			break;
		case XK_greater:
			k=PKEY_GREATER_THAN;
			break;
		case XK_question:
			k=PKEY_QUESTION_MARK;
			break;
		case XK_at:
			k=PKEY_AT;
			break;
		case XK_A:
			if (control_pressed)
				k=PKEY_TERM;
			else
				k=PKEY_A;
			break;
		case XK_B:
			if (control_pressed)
				k=PKEY_BACK1;
			else
				k=PKEY_B;
			break;
		case XK_C:
			if (control_pressed)
				k=PKEY_COPY1;
			else
				k=PKEY_C;
			break;
		case XK_D:
			if (control_pressed)
				k=PKEY_DATA1;
			else
				k=PKEY_D;
			break;
		case XK_E:
			if (control_pressed)
				k=PKEY_EDIT1;
			else
				k=PKEY_E;
			break;
		case XK_F:
			if (control_pressed)
				k=PKEY_FONT;
			else	
				k=PKEY_F;
			break;
		case XK_G:
			if (control_pressed)
				k=PKEY_DIVIDE;
			else
				k=PKEY_G;
			break;
		case XK_H:
			if (control_pressed)
				k=PKEY_HELP1;
			else
				k=PKEY_H;
			break;
		case XK_I:
			k=PKEY_I;
			break;
		case XK_J:
			k=PKEY_J;
			break;
		case XK_K:
			k=PKEY_K;
			break;
		case XK_L:
			if (control_pressed)
				k=PKEY_LAB1;
			else
				k=PKEY_L;
			break;
		case XK_M:
			if (control_pressed)
				k=PKEY_MICRO;
			else
				k=PKEY_M;
			break;
		case XK_N:
			if (control_pressed)
				k=PKEY_NEXT1;
			else
				k=PKEY_N;
			break;
		case XK_O:
			k=PKEY_O;
			break;
		case XK_P:
			if (control_pressed)
				k=PKEY_SUPER1;
			else
				k=PKEY_P;
			break;
		case XK_Q:
			if (control_pressed)
				k=PKEY_SQUARE;
			else
				k=PKEY_Q;
			break;
		case XK_R:
			if (control_pressed)
				k=PKEY_ERASE1;
			else	
				k=PKEY_R;
			break;
		case XK_S:
			if (control_pressed)
				k=PKEY_STOP1;
			else	
				k=PKEY_S;
			break;
		case XK_T:
			if (control_pressed)
				k=PKEY_TERM;
			else
				k=PKEY_T;
			break;
		case XK_U:
			k=PKEY_U;
			break;
		case XK_V:
			k=PKEY_V;
			break;
		case XK_W:
			k=PKEY_W;
			break;
		case XK_X:
			if (control_pressed)
				k=PKEY_MULTIPLY;
			else
				k=PKEY_X;
			break;
		case XK_Y:
			if (control_pressed)
				k=PKEY_SUB1;
			else
				k=PKEY_Y;
			break;	
		case XK_Z:
			k=PKEY_Z;
			break;
		case XK_bracketleft:
			k=PKEY_BRACKET_LEFT;
			break;
		case XK_backslash:
			k=PKEY_BACKSLASH;
			break;
		case XK_bracketright:
			k=PKEY_BRACKET_RIGHT;
			break;
		case XK_asciicircum:
			k=PKEY_CIRCUMFLEX;
			break;
		case XK_underscore:
			k=PKEY_UNDERSCORE;
			break;
		case XK_grave:
			k=PKEY_GRAVE;
			break;
		case XK_a:
			if (control_pressed)
				k=PKEY_ANS;
			else
				k=PKEY_a;
			break;
		case XK_b:
			if (control_pressed)
				k=PKEY_BACK;
			else
				k=PKEY_b;
			break;
		case XK_c:
			if (control_pressed)
				k=PKEY_COPY;
			else	
				k=PKEY_c;
			break;
		case XK_d:
			if (control_pressed)
				k=PKEY_DATA;
			else	
				k=PKEY_d;
			break;
		case XK_e:
			if (control_pressed)
				k=PKEY_EDIT;
			else
				k=PKEY_e;
			break;
		case XK_f:
			if (control_pressed)
				k=PKEY_FONT;
			else	
				k=PKEY_f;
			break;
		case XK_g:
			if (control_pressed)
				k=PKEY_DIVIDE;
			else		
				k=PKEY_g;
			break;
		case XK_h:
			if (control_pressed)
				k=PKEY_HELP;
			else
				k=PKEY_h;
			break;
		case XK_i:
			k=PKEY_i;
			break;
		case XK_j:
			k=PKEY_j;
			break;
		case XK_k:
			k=PKEY_k;
			break;
		case XK_l:
			if (control_pressed)
				k=PKEY_LAB;
			else
				k=PKEY_l;
			break;
		case XK_m:
			if (control_pressed)
				k=PKEY_MICRO;
			else
				k=PKEY_m;
			break;
		case XK_n:
			if (control_pressed)
				k=PKEY_NEXT;
			else	
				k=PKEY_n;
			break;
		case XK_o:
			k=PKEY_o;
			break;
		case XK_p:
			if (control_pressed)
				k=PKEY_SUPER;
			else
				k=PKEY_p;
			break;
		case XK_q:
			if (control_pressed)
				k=PKEY_SQUARE;
			else
				k=PKEY_q;
			break;
		case XK_r:
			if (control_pressed)
				k=PKEY_ERASE;
			else
				k=PKEY_r;
			break;
		case XK_s:
			if (control_pressed)
				k=PKEY_STOP;
			else
				k=PKEY_s;
			break;
		case XK_t:
			if (control_pressed)
				k=PKEY_TERM;
			else
				k=PKEY_t;
			break;
		case XK_u:
			k=PKEY_u;
			break;
		case XK_v:
			k=PKEY_v;
			break;
		case XK_w:
			k=PKEY_w;
			break;
		case XK_x:
			if (control_pressed)
				k=PKEY_MULTIPLY;
			else
				k=PKEY_x;
			break;
		case XK_y:
			if (control_pressed)
				k=PKEY_SUB;
			else	
				k=PKEY_y;
			break;
		case XK_z:
			k=PKEY_z;
			break;
		case XK_braceleft:
			k=PKEY_LEFT_CURLY_BRACE;
			break;
		case XK_bar:
			k=PKEY_BAR;
			break;
		case XK_braceright:
			k=PKEY_RIGHT_CURLY_BRACE;
			break;
		case XK_asciitilde:
			k=PKEY_TILDE;
			break;	
		case XK_Greek_sigma:
			k=PKEY_SIGMA;
			break;
		case XK_Greek_delta:
			k=PKEY_DELTA;
			break;
		case XK_division:
			k=PKEY_DIVIDE;
			break;
		case XK_multiply:
			k=PKEY_MULTIPLY;
			break;
		case XK_Greek_alpha:
			k=PKEY_ALPHA;
			break;
		case XK_Greek_beta:
			k=PKEY_BETA;
			break;
		case XK_cedilla:
			k=PKEY_CEDILLA;
			break;
		case XK_acute:
			k=PKEY_ACUTE_ACCENT;
			break;
		case XK_ae:
			k=PKEY_LOWERCASE_AE;
			break;
		case XK_aring:
			k=PKEY_LOWERCASE_A_WITH_RING;
			break;
		case XK_Greek_lambda:
			k=PKEY_LAMBDA;
			break;
		case XK_Greek_mu:
			k=PKEY_MU;
			break;
		case XK_degree:
			k=PKEY_DEGREE;
			break;
		case XK_Greek_pi:
			k=PKEY_PI;
			break;
		case XK_Greek_rho:
			k=PKEY_RHO;
			break;
		case XK_Greek_finalsmallsigma:
			k=PKEY_LOWERCASE_SIGMA;
			break;
		case XK_Greek_theta:
			k=PKEY_THETA;
			break;
		case XK_diaeresis:
			k=PKEY_DIARESIS;
			break;
		case XK_Greek_PI:
			k=PKEY_CAPITAL_PI;
			break;
		case XK_odiaeresis:
			k=PKEY_LOWERCASE_O_WITH_DIARESIS;
			break;
		case XK_copyright:
			k=PKEY_COPYRIGHT;
			break;
		case XK_AE:
			k=PKEY_UPPERCASE_AE;
			break;
		case XK_Aring:
			k=PKEY_UPPERCASE_A_WITH_RING;
			break;
		case XK_Adiaeresis:
			k=PKEY_UPPERCASE_A_WITH_DIAERESIS;
			break;
	}

	if (k>-1)
		keyboard_out(k);
}

keyboard_out_tty(ch)
char ch;
{
}
