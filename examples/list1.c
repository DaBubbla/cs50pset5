
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //memory for numbers
    int *numbers = NULL;
    int capacity = 0;

    //prompt for numbers until eof
    int size = 0;
    while(true)
    {
        //prompt for number
        int number = get_int("number: ");

        //check for eof
        if(number == INT_MAX)
        {
            break;
        }

        //check if num is already in list
        bool found = false;
        for(int i = 0; i < size; i++)
        {
            if(numbers[i] == number)
            {
                found = true;
                break;
            }

        }

        //if not in list, add to list
        if(!found)
        {
            //check whether enuff space for number
            if(size == capacity)
            {
                //allocate space for number
                numbers = realloc(numbers, sizeof(int) * (size + 1));
                if(!numbers)
                {
                    return 1;
                }
                capacity++;
            }


            //add num to list
            numbers[size] = number;
            size++;
        }
    }

    //print numbers
    for(int i = 0; i < size; i++)
    printf("%i\n", numbers[i]);
}
