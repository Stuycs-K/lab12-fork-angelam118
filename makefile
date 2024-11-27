.PHONY: clean run compile

run: main
	@./main
clean: 
	@rm -f *.o main
compile: main
main: main.o
	@gcc -o main main.o
main.o: main.c 
	@gcc -c main.c 
