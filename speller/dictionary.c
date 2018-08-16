// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"
#include "speller.c"

//include word count
int count = 0;



// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO if( word is present in dictionary)
    //{ return true;} else {false};
    return false;
}

// Loads dictionary into memory, returning true if successful
// else false
bool load(const char *dictionary)
{
    char *dictfile = "dictionary.h";

    //OPEN INPUT FILE
    FILE *inptr = fopen(dictfile, "r");

    if (dictfile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictfile);
        return false;
        fclose(dictfile);
    }

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
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
