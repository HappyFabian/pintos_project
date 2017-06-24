#include <stdio.h>
#include <syscall.h>



int
main(void)
{
    /*
    int into = lockinst(1);
    printf("Into: %d\n", into);
    lockinit(0,0);
    */

    seminst(2);
    seminit(0,1);
    seminit(1,0);

    int pid[3];
    pid[0] = exec("reader 1");
    pid[1] = exec("reader 2");
    pid[2] = exec("writer 3");
    

    wait(pid[0]);
    wait(pid[1]);
    wait(pid[2]);

    return 0;
}