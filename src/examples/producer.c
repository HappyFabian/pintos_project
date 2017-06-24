
#include <stdio.h>
#include <syscall.h>



int 
main(int argc, char* argv[])
{
    printf("%s\n", argv[1]);

    int i = 0;
    while(i < 1000)
    {
       semdown(1);
       printf("Producing 1 Item! [%s]\n", argv[1]);
       semup(0);
       i++;
    }

    return 0;
}