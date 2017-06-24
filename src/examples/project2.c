#include <stdio.h>
#include <syscall.h>



int
main(void)
{

  seminst(1);
  seminit(0,3);

  int pid[5];
  pid[0] = exec("philosopher 1");
  pid[1] = exec("philosopher 2");
  pid[2] = exec("philosopher 3");
  pid[3] = exec("philosopher 4");
  pid[4] = exec("philosopher 5");

  wait(pid[0]);
  wait(pid[1]);
  wait(pid[2]);
  wait(pid[3]);
  wait(pid[4]);

  return 0;
}

