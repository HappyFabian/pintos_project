#include <stdio.h>
#include <syscall.h>

#include <random.h>

int
main(int argc, char * argv[])
{   
    int j = atoi(argv[1]);
    int i = 0;
    int readCount = 0;
    while(i < 30)
    {
        semdown(1);
        readCount++;
        if(readCount == 1)
        {
            semdown(0);
        }
        semup(1);
        printf("Reading. [%d]", j);
        
        int random = 0;
        while(random < 10000)
        {
            random++;
        }
        
        semdown(1);
        readCount--;
        if(readCount == 0)
        {
            semup(0);
        }
        semup(1);
        i++;
    }


    return 0;
}