all: exercice1 exercice2 exercice3 exercice4


mat_lib.o: mat_lib.c
	gcc -o mat_lib.o -c mat_lib.c -W -Wall -g

treeDrawing.o: treeDrawing.c
	gcc -o treeDrawing.o -c treeDrawing.c -W -Wall -g

exercice1: exercice1.o mat_lib.o
	gcc -o exercice1 exercice1.o mat_lib.o

exercice1.o: exercice1.c mat_lib.h
	gcc -o exercice1.o -c exercice1.c -W -Wall -g

exercice2: exercice2.o
	gcc -o exercice2 exercice2.o

exercice2.o: exercice2.c
	gcc -o exercice2.o -c exercice2.c -W -Wall -g

exercice3: exercice3.o
	gcc -o exercice3 exercice3.o

exercice3.o: exercice3.c
	gcc -o exercice3.o -c exercice3.c -W -Wall -g

exercice4: exercice4.o treeDrawing.o
	gcc -o exercice4 exercice4.o treeDrawing.o

exercice4.o: exercice4.c treeDrawing.h
	gcc -o exercice4.o -c exercice4.c -W -Wall -g



clean:
	rm -rf *.o *.gch

mrproper: clean
	rm -rf exercice1 exercice2 exercice3 exercice4
