// Child file for defining struct.
// Trie will help implementation of dictionary.c's
// check function.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dictionary.h"
//#include "dictionary.c"

typedef struct node
{
    struct node *children[27];//struct word[length + 1];??
    bool leaf;//struct node *next;??
}
node;

