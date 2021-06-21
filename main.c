/* PLATOTERM for UNIX */

#include "protocol.h"
#include "screen.h"
#include "io.h"
#include "terminal.h"
#include "keyboard.h"
#include "touch.h"

#define TRUE 1
#define FALSE 0

unsigned char already_started=FALSE;
int done = FALSE;
char hostname[64];
unsigned short port;

main(argc, argv)
int argc;
char *argv[];
{
	if (argc<3)
	{
		printf("%s <host> <port>\n",argv[0]);
		exit(1);
	}
	else
	{
		strcpy(hostname,argv[1]);
		port=atoi(argv[2]);
	}


	screen_init(hostname,port);
	touch_init();
	terminal_initial_position();
	io_init(hostname,port);

        while (done == FALSE)	
	{
		screen_main();
		io_main();
	}

	touch_done();
	io_done();
	screen_done();	
}
