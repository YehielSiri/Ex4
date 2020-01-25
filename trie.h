#ifndef TRIE_H
#define TRIE_H

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 
#define ALPHABET ((int)26)						/*number of letters in Alphabet*/
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')	/*Converts key current character into index use (only 'a' through 'z' and lower case)*/
#define INDEX_TO_CHAR(i) ((int)i + (int)'a')	/*Converts back the index into key character (only 'a' through 'z' and lower case)*/


typedef enum {
	FALSE = 0,
	TRUE = 1
} boolean;

// trie node structure
typedef struct TrieNode { 
    char letter;
    long unsigned int count;					/*counting occurrences in the text of the word ending in this node*/
	struct TrieNode *children[ALPHABET]; 
} TrieNode, *pTrieNode;


pTrieNode newTrieNode(void);
pTrieNode newTrieNode(char letter);
pTrieNode insertKid(pTrieNode locationInWord, const char letter);
boolean hasNoKids(pTrieNode node);
int printIncLexicog(pTrieNode node, char *str, int level);
int printDecLexicog(pTrieNode root, char *str, int level);
int destroyTrie(pTrieNode root);

#endif