#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char castToLower(char capitalLetter) {
	return ( capitalLetter + ('a' - 'A') );
}


int main(int argc, char *argv[]) {
	
	// Construct trie
	pTrieNode root = newTrieNode();
	char input;
	
	// Read input, verify correctness, cast if necessary and insert to trie
	pTrieNode *locationInWord = root;
	while( (input = getc(stdin)) != EOF) {
		if( (input >= 'a') && (input <= 'z') ) {
			// Proper input
			locationInWord = insertKid(locationInWord, input);
		} else if( (input >= 'A') && (input <= 'Z') ) {
			// Casting is required
			locationInWord = insertKid(locationInWord, castToLower(input) );
		} else if() {
			// End of word
			locationInWord->count++;
			locationInWord = root;
		}
	}
	
	// Print words by lexicographic order
	char word[10000] = {0};
	
	if( (argc >= 2) && (argv[1] == 'r') ) {
		printIncLexicog(root, word, 0);
	} else {
		printDecLexicog(root, word, 0);
	}
	destroyTrie(root);
	return 0;
}