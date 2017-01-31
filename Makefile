CC=gcc
CFLAGS=-W -Wall
EXEC=exercice1 exercice2 exercice3 exercice4

all: $(EXEC)

mat_lib.o: mat_lib.c
	$(CC) -o mat_lib.o -c mat_lib.c $(CFLAGS)

treeDrawing.o: treeDrawing.c
	$(CC) -o treeDrawing.o -c treeDrawing.c $(CFLAGS)

exercice1: exercice1.o mat_lib.o
	$(CC) -o exercice1 exercice1.o mat_lib.o

exercice1.o: exercice1.c mat_lib.h
	$(CC) -o exercice1.o -c exercice1.c $(CFLAGS)

exercice2: exercice2.o
	$(CC) -o exercice2 exercice2.o

exercice2.o: exercice2.c
	$(CC) -o exercice2.o -c exercice2.c $(CFLAGS)

exercice3: exercice3.o
	$(CC) -o exercice3 exercice3.o

exercice3.o: exercice3.c
	$(CC) -o exercice3.o -c exercice3.c $(CFLAGS)

exercice4: exercice4.o treeDrawing.o
	$(CC) -o exercice4 exercice4.o treeDrawing.o

exercice4.o: exercice4.c treeDrawing.h
	$(CC) -o exercice4.o -c exercice4.c $(CFLAGS)

clean:
	rm -rf *.o *.h.gch

mrproper: clean
	rm -rf $(EXEC)
