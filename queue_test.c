#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int test_queue()
{
    struct Queue queue;
    int ret = queue_init(&queue);
    if(ret < 0)
    {
        fprintf(stderr,"queue init failed\n");
        return -1;
    }
    int data_array[10] = {0};
    int i = 0;
    srand(time(NULL));
    while(i<10)
    {
        data_array[i] = rand()%100;
        fprintf(stdout,"%d\t",data_array[i]);
        ret = queue_put(&queue,&data_array[i]);
        if(ret < 0)
        {
            fprintf(stderr,"put failed\n");
            return -2;
        }
        i++;
    }
    fprintf(stdout,"\n");

    int *p;
    while(queue_empty(&queue)==0)
    {
        p =(int*) queue_get(&queue);
        fprintf(stdout,"%d\t" ,*p);
    }
    fprintf(stdout,"\n");
    return 0;
}

int main()
{
    test_queue();
    return 0;
}
