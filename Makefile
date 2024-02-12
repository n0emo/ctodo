ctodo: main.c
	gcc -o ctodo main.c -lncurses

run: ctodo
	./ctodo
