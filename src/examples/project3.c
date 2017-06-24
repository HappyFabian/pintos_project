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
    //RW
    seminit(0,1);
    //MUTEX
    seminit(1,1);

    int pid[3];
    pid[0] = exec("writer 1");
    pid[1] = exec("reader 2");
    pid[2] = exec("reader 3");
    
    

    wait(pid[0]);
    wait(pid[1]);
    wait(pid[2]);

    return 0;
}