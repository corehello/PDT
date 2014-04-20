/* ARRAY.H */

#include <stdlib.h>
#include <time.h>

/* Arrange the N elements of ARRAY in random order. */
void array_shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        // Seed that will get different result
        srand( time(NULL) );
        
        size_t i;
        for (i = n-1; i > 0; i--) 
        {
          size_t j = rand() % (i+1);
          // swap
          array[i] = array[i] ^ array[j];
          array[j] = array[i] ^ array[j];
          array[i] = array[i] ^ array[j];
        }
    }
}
