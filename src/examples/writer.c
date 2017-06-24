#include <stdio.h>
#include <syscall.h>

#include <random.h>


int
main(int argc, char * argv[])
{
    int z = atoi(argv[1]);
    int i = 0;
    while(i < 30)
    {
        semdown(0);
        printf("Writing. [%d] \n", z);
  
        printf("Finished writing[%d] \n", z);
        semup(0);
        i++;
    }

    return 0;
}