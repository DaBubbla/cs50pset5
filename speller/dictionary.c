// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"


/*DEFINE THE TRIE*/
typedef struct node
{
    bool isword;
    struct node *children[27];
}
node;

node *root = NULL;

void freeNode(node* branch);
/*GLOBAL DECLARATIONS*/

int count = 0;// INCLUDE A WORD COUNT FOR SIZE

int max = 46;// MAX WORD SIZE +1 FOR '\0'

/*END OF DECLARATIONS*/


// Returns true if word is in dictionary else false
bool check(const char *word)
{/*REVIEW SPELLER / CHECK @ 2:14*/
    // POINT TO ROOT
    node *branch = root;
    int i = 0;
    // ITERATE THROUGH WORD (+1 FOR '\0') - DECLARATIONS HELP
    int wordLength = strlen(word);

    for (int j = 0; j < wordLength + 1; j++)
    {
        if(word[j] == '\0')
        {
        if (branch->isword == true)
            return true;
        else
            return false;
        }

        // UPPERCASE IS ACCEPTABLE
        if(isupper(word[j]))
        {
            i = word[j] - 65;
        }
        //LOWERCASE IS ACCEPTABLE
        else if (islower(word[j]))
        {
            i = word[j] - 97;
        }
        // MAKE ROOM FOR POSSESSION '
        else if (word[j] == '\'')
        {
            i = 26;
        }
        // IF CURRENT BRANCH OF CHILDREN[X] == NULL
        if(branch->children[i] == NULL)
        {
            return false;
        }
        //ELSE BRANCH = BRANCH OF CHILDREN[X]
        else
        {
            branch = branch->children[i];
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful
// else false

bool load(const char *dictionary)
{
    /*CREATE DA ROOT*/
    root = calloc(1, sizeof(node));
    root->isword = false;
    int i = 0;
    char dict_word[max];

    //OPEN INPUT FILE
    FILE *fp = fopen(dictionary, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Could not open %p.\n", fp);
        return false;
    }

/*############################################################
*Purpose: While scanning for strings(%s) in the dictionary file (fp)
          until the End Of File. Start a root and iterate
          each char in the dictionary file. Values will be stored
          in the buffer (dict_word). Once a trie is established
          fclose - dictionary created.
##############################################################*/
    while( fscanf(fp, "%s", dict_word) != EOF )
    {
        node *branch = root;

        for(int j = 0; j < strlen(dict_word) +1; j++)
        {
            if(dict_word[j] == '\0')/*IF ENDING VALUE...*/
            {
                branch->isword = true;/*YOU FOUND A WORD!!*/
                count++;
                break;
            }
            else if (islower(dict_word[j]))/*IF LOWERCASE*/
            {
                i = dict_word[j] - 97; /*LOWER ASCII VALUES GOOD*/
            }
            else if (dict_word[j] == '\'')/*IF THERE IS AN ' */
            {
                i = 26; /*ASCII ' SHALL PASS! */
            }

            if (branch->children[i] == NULL)
            {/*IF WE HIT ANOTHER/NEXT WORD IN
            THE DICTIONARY, CREATE A NEW NODE FOR IT*/
                node *new_node = calloc(1, sizeof(node));
                new_node->isword = false;

                branch->children[i] = new_node;
                branch = new_node;


            }
            else
            {
                branch = branch->children[i];
            }
        }
    }
    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if
//not yet loaded
unsigned int size(void)
{
    if(count != 0)
    {
        return count;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node* branch = root;
    if(branch)
    {
        if(root != NULL)
        {
            freeNode(root);
        }
        return true;
    }
    return false;
}

void freeNode(node* branch)
{
    for (int i = 0; i < 27; i++)
    {
        if(branch->children[i])
        {
            freeNode(branch->children[i]);
        }
    }
    free(branch);
    return;
}