main : main.o
	g++ main.o -o main
main.o : main.s
	g++ -c main.s -o main.o
main.s : main.i
	g++ -S main.i -o main.s
main.i : main.c
	g++ -E main.c -o main.i

clean:
	-rm *.i *.s *.o
