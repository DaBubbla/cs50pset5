// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"
#include "speller.c"
//#include "testsite.h"

//include word count
int count = 0;


/*define the trie*/
typedef struct node
{
    bool isword;
    struct node *children[27];
}
node;

node *root = NULL;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    return false;
}

// Loads dictionary into memory, returning true if successful
// else false
bool load(const char *dictionary)
{

    //OPEN INPUT FILE
    FILE *dict_ptr = fopen("cat.txt", "r");

    if (dict_ptr == NULL)
    {
        fprintf(stderr, "Could not open %p.\n", dict_ptr);
        return false;
        fclose(dict_ptr);
    }

    for (char letter = fgetc(dict_ptr); letter != EOF; letter++)
    {
        node *current;
        current = malloc(sizeof(node));
        current = root;

        node *nextnode = malloc(sizeof(node));
        current->children[letter - 'a'] = nextnode;

        if( letter == '\n')
        {
            nextnode->isword = true;
            current = root;
            count++;
        }
    }
/*========================================================*/
return false;

}

// Returns number of words in dictionary if loaded else 0 if
//not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
