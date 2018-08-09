//Demo for valgrind command function

#include <stdlib.h>

void f(void)
{
    int *x = malloc(10 * sizeof(int));
    x[9] = 0;//change x[9] from x[10]
    //need to free!!
    free(x);
}

int main(void)
{
    f();
    return 0;
}