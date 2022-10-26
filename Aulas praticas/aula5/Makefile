CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=VE2

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o VE2.o
	gcc main.o VE2.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

VE2.o: VE2.c
	gcc $(CFLAGS) -c VE2.c


clean:
	rm -rf *.o $(EXECUTAVEL)


run: $(EXECUTAVEL)
	./$(EXECUTAVEL)