/**
 * PLATOTerm64 - A PLATO Terminal for the Commodore 64
 * Based on Steve Peltz's PAD
 * 
 * Author: Thomas Cherryhomes <thom.cherryhomes at gmail dot com>
 *
 * io.h - Input/output functions (serial/ethernet)
 */

#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <errno.h>
#include <fcntl.h>
#include "io.h"
#include "protocol.h"

#define TRUE 1
#define FALSE 0

int rxlen;
padByte rxBuf[32768];
struct sockaddr_in sa;
int sockfd;
int fileflags;

io_inject(b,l)
padByte* b;
int l;
{
}

/**
 * io_init() - Set-up the I/O
 */
io_init(hostname,port)
char *hostname;
unsigned short port;
{
        sockfd = socket(AF_INET, SOCK_STREAM, 0);        
        sa.sin_family = AF_INET;       
        sa.sin_addr.s_addr = inet_addr(hostname);
	sa.sin_port = htons(port);
        connect(sockfd,(struct sockaddr *)&sa, sizeof(sa)); 	

	fileflags = fcntl(sockfd,F_GETFL,0);
	fcntl(sockfd,F_SETFL,fileflags|FNDELAY);
}

/**
 * io_send_byte(b) - Send specified byte out
 */
io_send_byte(b)
unsigned char b;
{
	write(sockfd, &b, 1);
}

/**
 * io_main() - The IO main loop
 */
io_main()
{
	rxlen = read(sockfd, &rxBuf[0], sizeof(rxBuf));
	if (rxlen < 0 )
		return;

	ShowPLATO(&rxBuf[0], rxlen);	
}

/**
 * io_done() - Called to close I/O
 */
io_done()
{
}
