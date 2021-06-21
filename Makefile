X11_INCLUDE=/usr/openwin/include
X11_LIBS=/usr/openwin/lib

all: platoterm

touch.o: touch.c
	cc -g -I$(X11_INCLUDE) -o touch.o -c touch.c

io.o: io.c
	cc -g -o io.o -c io.c

keyboard.o: keyboard.c
	cc -g -I$(X11_INCLUDE) -o keyboard.o -c keyboard.c

screen.o: screen.c
	cc -g -I$(X11_INCLUDE) -o screen.o -c screen.c

terminal.o: terminal.c
	cc -g -o terminal.o -c terminal.c

protocol.o: protocol.c
	cc -g -o protocol.o -c protocol.c

main.o: main.c
	cc -g -o main.o -c main.c

platoterm: main.o touch.o io.o keyboard.o screen.o terminal.o protocol.o
	cc -g -L$(X11_LIBS) -o platoterm main.o touch.o io.o keyboard.o screen.o terminal.o protocol.o -lX11 

clean:
	rm -rf platoterm *.o
