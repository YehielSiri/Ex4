CC = gcc
RM = rm
FLAGS = -Wall -g


.PHONY: all clean


all: frequency

frequency: main.o trie.o
	$(CC) $(FLAGS) -o frequency main.o trie.o
trie.o: trie.c trie.h
	$(CC) $(FLAGS) -fPIC -c trie.c
main.o: main.c trie.h
	$(CC) $(FLAGS) -fPIC -c main.c

clean:
	$(RM) -f *.o frequency