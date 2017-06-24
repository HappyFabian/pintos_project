#include <stdio.h>
#include <syscall.h>

#include <random.h>


int
main(int argc, char * argv[])
{
    int z = atoi(argv[1]);
    int i = 0;
    while(i < 1000)
    {
        semdown(0);
        printf("Writing. [%d] \n", z);
        int j = 0;
        while(j < random_int())
        {
            j++;
        }
        printf("Finished writing[%d] \n", z);
        semup(1);
     
    }

    return 0;
}