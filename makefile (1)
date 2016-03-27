main :  test_Barbre.o barbre.o 
	gcc -Wall -g -I. test_Barbre.o barbre.o -o main 
main.o : main.c barbre.h
	gcc -Wall -g -c -I. -L. test_Barbre.c -o  test_Barbre.o
barbre.o : barbre.c barbre.h
	gcc -Wall -g -c -I. -L. barbre.c -o barbre.o 	

