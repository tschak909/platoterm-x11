X11_INCLUDE=/usr/openwin/include
X11_LIBS=/usr/X11/lib
X11_LIBS=/usr/openwin/lib
OBJ=main.o touch.o io.o keyboard.o screen.o terminal.o protocol.o
CFLAGS=-g -Wno-error=implicit-function-declaration -Wno-error=return-type

all: platoterm

touch.o: touch.c
	cc $(CFLAGS) -I$(X11_INCLUDE) -o $@ -c touch.c

io.o: io.c
	cc $(CFLAGS) -o $@ -c io.c

keyboard.o: keyboard.c
	cc $(CFLAGS) -I$(X11_INCLUDE) -o $@ -c keyboard.c

screen.o: screen.c
	cc $(CFLAGS) -I$(X11_INCLUDE) -o $@ -c screen.c

terminal.o: terminal.c
	cc $(CFLAGS) -o $@ -c terminal.c

protocol.o: protocol.c
	cc $(CFLAGS) -o $@ -c protocol.c

main.o: main.c
	cc $(CFLAGS) -o $@ -c main.c

platoterm: $(OBJ)
	cc -g -L$(X11_LIBS) -o $@ $(OBJ) -lX11 

clean:
	rm -rf platoterm $(OBJ)

check:
	./platoterm IRATA.ONLINE 8005
