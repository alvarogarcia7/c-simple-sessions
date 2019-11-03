#include "maximum.h"

int main()
{
    int array1[] = {3, 1, 2, 45, 4, 5};
    int m = sizeof(array1)/sizeof(int);

    int max = find_max(array1, m);
    
    printf("The maximum value is %d \n", max);

    return 0;
}
