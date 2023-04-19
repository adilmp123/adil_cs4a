#include <stdio.h>
int empty, full=0,mutex=1, buffer[];

int wait(int S)
{
    while(S<=0);
    return --S;
}

int signal(int S)
{
    return ++S;
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
                                                                                                                                                                                                                                    
}