X11_INCLUDE=/usr/openwin/include
X11_LIBS=/usr/X11/lib
X11_LIBS=/usr/openwin/lib
OBJ=main.o touch.o io.o keyboard.o screen.o terminal.o protocol.o

all: platoterm

touch.o: touch.c
	cc -g -I$(X11_INCLUDE) -o $@ -c touch.c

io.o: io.c
	cc -g -o $@ -c io.c

keyboard.o: keyboard.c
	cc -g -I$(X11_INCLUDE) -o $@ -c keyboard.c

screen.o: screen.c
	cc -g -I$(X11_INCLUDE) -o $@ -c screen.c

terminal.o: terminal.c
	cc -g -o $@ -c terminal.c

protocol.o: protocol.c
	cc -g -o $@ -c protocol.c

main.o: main.c
	cc -g -o $@ -c main.c

platoterm: $(OBJ)
	cc -g -L$(X11_LIBS) -o $@ $(OBJ) -lX11 

clean:
	rm -rf platoterm $(OBJ)

run:
	./platoterm IRATA.ONLINE 8005
