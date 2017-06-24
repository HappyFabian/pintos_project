#include <stdio.h>
#include <syscall.h>

#include <random.h>

int
main(int argc, char * argv[])
{   
    int j = atoi(argv[1]);
    int i = 0;
    while(i < 1000)
    {
        semdown(1);
        printf("Reading. %d \n", j);
        semup(0);
    }


    return 0;
}