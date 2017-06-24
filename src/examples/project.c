/*
pintos-mkdisk myfile.dsk --filesys-size=5
pintos --qemu --disk=myfile.dsk -- -f -q
pintos --qemu --disk=myfile.dsk -p ../../examples/project -a project -- -q
pintos --qemu --disk=myfile.dsk -p ../../examples/child_sort -a child_sort -- -q
pintos --qemu --disk=myfile.dsk -p ../../examples/matmult -a matmult -- -q
pintos -r --qemu --disk=myfile.dsk -- -q run project
*/

#include <stdio.h>
#include <syscall.h>


int
main(void)
{

  int pid[4];

  seminst(2);
  seminit(0,5);
  seminit(1,0);

  pid[0] = exec("consumer 1");
  pid[1] = exec("consumer 2");
  pid[2] = exec("producer 3");
  pid[3] = exec("producer 4");

  wait(pid[0]);
  wait(pid[1]);
  wait(pid[2]);
  wait(pid[3]);

  return 0;
}

