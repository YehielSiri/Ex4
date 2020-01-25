#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Defalt constructor: create a new trie node (initialized to NULLs) 
pTrieNode newTrieNode(void) {
	pTrieNode newTrieNode = NULL;

	newTrieNode = (pTrieNode *)malloc(sizeof(TrieNode));

	if(newTrieNode) {
		newTrieNode->count = FALSE;

		int i;
		for(i = 0; i < ALPHABET; i++) {
			newTrieNode->children[i] = NULL;
		}
	}
	return newTrieNode;
} 


// Constructor with letter: create a new trie node (initialized to NULLs & put into the letter) 
pTrieNode newTrieNode(char letter) {
	pTrieNode newTrieNode = NULL;

	newTrieNode = (pTrieNode *)malloc(sizeof(TrieNode));

	if(newTrieNode) {
		newTrieNode->letter = letter;
		newTrieNode->count = FALSE;

		int i;
		for(i = 0; i < ALPHABET; i++) {
			newTrieNode->children[i] = NULL;
		}
	}
	return newTrieNode;
}


// Inserts a letter into word trie or just push the pointer if the letter is already kid of this trie node. (low letters)
pTrieNode insertKid(pTrieNode locationInWord, const char letter) {
	
	// Verify input
	if( (locationInWord == NULL) || (letter < 'a') || (letter > 'z') ) {
		printf("Error in func 'insertKid'! A wrong pTrieNode / letter have sent to the function.")
		return locationInWord;
	}
	
	int i = CHAR_TO_INDEX(letter);
	
	// If there is a 'letter' kid (just push the pointer)
	if( (locationInWord->children[i]) != NULL ) {
		return (locationInWord->children[i]);
	}
	
	// Insert a 'letter' kid
	if(locationInWord->children[i] = newTrieNode(letter)) {	// Make sure mallocation have succeed
		return locationInWord->children[i];
	} else { // Mallocation have falled
		printf("Malloc error!");
		return locationInWord;
	}
}


// TRUE if the node has no kids
boolean hasNoKids(pTrieNode node) {
	int i;
	for(i = 0; i < ALPHABET; i++) {
		if((node->children[i])) {
			return FALSE;
		}
	}
	return TRUE;
}


//// Return how many words are ended in this node (more than 0 = is leaf)
//int isLeaf(pTrieNode node) {
//	return node->count;
//}


// Print trie in incrising lexicography order
int printIncLexicog(pTrieNode node, char *str, int level) {
	if(node->count) {
		str[level] = '\0';
		printf("%s\t%d\n", str, node->count);
		return;
	}

	int i;
	for(i = 0; i < ALPHABET; i++) {
		if(node->children[i]) {
			str[level] = node->children[i]->letter;
			printIncLexicog(node->children[i], str, level++);
		}
	}
	return 0;
}


// Print in incrising lexicography order
int printDecLexicog(pTrieNode root, char *str, int level) {
	if(node->count) {
		str[level] = '\0';
		printf("%s\t%d\n", str, node->count);
		return;
	}

	int i;
	for(i = ALPHABET; i > 0; i--) {
		if(node->children[i]) {
			str[level] = node->children[i]->letter;
			printIncLexicog(node->children[i], str, level++);
		}
	}
	return 0;
}


// Free all Trie's nodes from ground up
int destroyTrie(pTrieNode root) {
	
	// First stop condition
	if(root == NULL) {
		return 0;
	}

	// Second stop condition
	if(hasNoKids(root)) {
		free(root);
		return 0;
	}
	
	// Root has kids
	int i;
	for(i = 0; i < ALPHABET; i++) {
		destroyTrie(root->children[i]);
	}
	
	free(root);
	return 0;
}