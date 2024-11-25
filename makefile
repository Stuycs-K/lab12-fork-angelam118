.PHONY: clean run compile

run: main.o
	@./main.o
clean: 
	@rm -f *.o 
compile: main.o
main.o: main.c 
	@gcc -c main.c 
