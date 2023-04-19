#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int shmId;
    pid_t pid; 
    char * shmAddr;
    shmId = shmget(IPC_PRIVATE,1024,0666 | IPC_CREAT);                        
    if(shmId<0)
    {
        perror("fork failed\n");
        exit(1);
    }
    pid = fork();
    if(pid<0)
    {
        perror("Shm get failed\n");
        exit(1);
    }
    if(pid==0)
    {
        shmAddr = shmat(shmId,NULL,0);
        if(shmAddr== (char*)-1)
        {
            perror("Shm mat failed");
            exit(1);
        }
        printf("Child process read data: %s\n",shmAddr);
        shmdt(shmAddr);
        exit(0);
    }
    else
    {
        shmAddr = shmat(shmId,NULL,0);
        if(shmAddr== (char*)-1)
        {
            perror("shm mat failed\n");
            exit(1);
        }
        sprintf(shmAddr,"hello, shared memory\n");
        wait(NULL);
        shmdt(shmAddr);
        shmctl(shmId,IPC_RMID,NULL);
        exit(0);
    }
    
}