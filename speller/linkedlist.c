/*================================================*
 *Program: linkedlist.c                           *
 *Book:    Sams Teach Yourself C in One Hour a Day*
 *Purpose: Implementing a linked list             *
 ==================================================*/
#include <stdio.h>
#include <stdlib.h> //g

#ifndef NULL
    #define NULL 0
#endif

/* List data structure */
struct list
{
    int ch; /* using an int to hold a char */
    struct list *next_rec;
};

/* Typedefs for the structure and pointer. */
typedef struct list LIST;
typedef LIST *LISTPTR;

/* Function prototypes */
LISTPTR add_to_list ( int, LISTPTR );
void show_list (LISTPTR);
void free_memory_list(LISTPTR);

int main(void)
{
    LISTPTR first = NULL; //head pointer
    int i = 0;
    int ch;
    char trash[256]; //to clear stdin buffer

    while( i++ < 5 ) //build a list based on 5 items given.
    {
        ch = 0;
        printf("\nEnter character %d, ", i);

        do
        {
            printf("\nMust be a to z: ");
            ch = getc(stdin); // get next char in buffer
            fgets(trash); //remove trash from buffer.
        } while( (ch < 'a' || ch > 'z') && (ch < 'A' || ch > 'Z') );

        first = add_to_list( ch, first );
    }

    show_list( first ); //dumps entire list
    free_memory_list( first ); //Release all memory
    return 0;
}

/*==============================================================
 *Function: add_to_list()
 *Purpose: Inserts new link in the list
 *Entry: int ch = character to store
 *       LISTPTR first = address of original head pointer
 *Returns: address of head pointer (first)
=================================================================*/

LISTPTR add_to_list( int ch, LISTPTR first )
{
    LISTPTR new_rec = NULL;  //Holds address of new rec
    LISTPTR tmp_rec = NULL;  //Holds tmp pointer
    LISTPTR prev_rec = NULL;

    /* Allocate memory. */
    new_rec = (LISTPTR)malloc(sizeof(LIST));
    if (!new_rec)  //unable to allocaate memory
    {
        printf("\nUnable to allocate memory!\n");
        exit(1);
    }

    /* set new link's data */
    new_rec->ch = ch;
    new_rec->next_rec = NULL;

    if (first == NULL) //adding first link to list
    {
        first = new_rec;
        new_rec->next_rec = NULL;  //redundant but safe
    }
    else //not first record
    {
        //see if it goes before the first link
        if ( new_rec->ch < first->ch)
        {
            new_rec->next_rec = first;
            first = new_rec;
        }
        else  //it is being added to the middle or end
        {
            tmp_rec = first->next_rec;
            prev_rec = first;

            //Check to see where link is added.

            if( tmp_rec == NULL )
            {
                //we are adding second record to end
                prev_rec->next_rec = new_rec;
            }
            else
            {
                //check to see if adding in middle
                while ((tmp_rec->next_rec != NULL))
                {
                    if ( new_rec->ch < tmp_rec->ch )
                    {
                        new_rec->next_rec = tmp_rec;
                        if( new_rec->next_rec != prev_rec->next_rec )
                        {
                            printf("ERROR!");
                            getc(stdin);
                            exit(0);
                        }
                        prev_rec->next_rec = new_rec;
                        break;  //link is added; exit while
                    }
                    else
                    {
                        tmp_rec = tmp_rec->next_rec;
                        prev_rec = prev_rec->next_rec;
                    }
                }

                //check to see if adding to the end
                if ( tmp_rec->next_rec == NULL )
                {
                    if ( new_rec->ch < tmp_rec->ch )  //1 b4 end
                    {
                        new_rec->next_rec = tmp_rec;
                        prev_rec->next_rec = new_rec;
                    }
                    else // at the end
                    {
                        tmp_rec->next_rec = new_rec;
                        new_rec->next_rec = NULL; // redundant
                    }
                }
            }
        }
    }
    return(first);
}

/*===================================================
 *Function: show_list
 *Purpose: Displays the information currnt in the list
 *==================================================*/

void show_list( LISTPTR first )
{
    LISTPTR cur_ptr;
    int counter = 1;

    printf("\n\nRec  addr  Position  Data  Next Rec addr\n");
    printf("========  ======  ====  ====  =============\n");

    cur_ptr = first;
    while (cur_ptr != NULL )
    {
        printf("   %p   ", cur_ptr );
        printf("      %2i       %c", counter++, cur_ptr->ch );
        printf("       %p    \n", cur_ptr->next_rec);
        cur_ptr = cur_ptr->next_rec;
    }
}

/*=================================================
 *Function: free_memory_list
 *Purpose: Frees up all the memory collected for list
 *================================================*/

 void free_memory_list(LISTPTR first)
 {
     LISTPTR cur_ptr, next_rec;
     cur_ptr = first;                   //start at the beginning

     while (cur_ptr != NULL )           //go while not end of list
     {
         next_rec = cur_ptr->next_rec;  //get address of next record
         free(cur_ptr);                 //free current record
         cur_ptr = next_rec;            //adjust current record
     }
 }