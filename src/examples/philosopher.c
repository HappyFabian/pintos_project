#include <stdio.h>
#include <syscall.h>
#include <random.h>

int
main(int argc, char * argv[])
{
    int currentPhilosopher = atoi(argv[1]);

    int value = 0;
    int thinkering = 10000;
    int gotAFork=0;
    int thinking = 0;
    
    int i = 0;
    while(i < 1000)
    {
        if(!thinking)
        {
            semdown(0);
            printf("Got a fork and eating. [%d] \n", currentPhilosopher);
            gotAFork = 1;

            value = random_int()/thinkering;
            while(value > 0)
            {   
                value--;
            }

            semup(0);
            printf("Released a fork, thus finished eating. [%d] \n", currentPhilosopher);
            gotAFork = 0;
            value = 0;
            thinking = 1;
        }
        else
        {
            
            printf("Thinking. [%d] \n",currentPhilosopher);  
            value = random_int()/thinkering;
            while(value > 0)
            {   
                value--;
            }
            printf("Got Hungry. [%d] \n",currentPhilosopher); 
            thinking = 0;
            value = 0;
        }
        i++;
    }
    
    return 0;
}

