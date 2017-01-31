exercice1: exercice1.o mat_lib.o
	gcc -o exercice1 exercice1.o mat_lib.o

mat_lib.o: mat_lib.c
	gcc -o mat_lib.o -c mat_lib.c -W -Wall -g

exercice1.o: exercice1.c mat_lib.h
	gcc -o exercice1.o -c exercice1.c -W -Wall -g

exercice2: exercice2.o
	gcc -o exercice2 exercice2.o mat_lib.o

exercice2.o: exercice2.c
	gcc -o exercice2.o -c exercice2.c -W -Wall -g


all: exercice1 exercice2

clean:
	rm -rf *.o *.gch

mrproper: clean
	rm -rf exercice1 exercice2
