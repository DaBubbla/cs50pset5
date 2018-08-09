
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int capacity;
    do
    {
        capacity = get_int("capacity: ");
    }
    while(capacity < 1);

    //memory for numbers
    int numbers[capacity];

    //Prompt for numbers
    int size = 0;
    while(size < capacity)
    {
        //prompt for number
        int number = get_int("number: ");

        //check whether number is already in list
        bool found = false;
        for (int i = 0; i < size; i++)
        {
             if(numbers[i] == number)
             {
                 found = true;
                 break;
             }
        }
        if(!found)
        {
            numbers[size] = number;
            size++;
        }
    }
    //print numbers
    for(int i = 0; i < size; i++)
    printf("%i\n", numbers[i]);
}