
#include <stdio.h>
#include <syscall.h>


int 
main(int argc, char* argv[])
{
    printf("%s\n", argv[1]);
    int i = 0;
    while(i < 1000)
    {
       semdown(0);
       printf("Consuming 1 Item! [%s]\n", argv[1]);
       semup(1);
       i++;
    }
    return 0;
}