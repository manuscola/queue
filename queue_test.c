#include "queue.h"
#include <stdio.h>

int test_queue()
{
	struct Queue queue;
	int ret = queue_init(&queue);
	if(ret < 0)
	{
		fprintf(stderr,"queue init failed\n");
		return -1;
	}
	int data_array[6] = {10,19,23,45,32,8};
	int i = 0;
    while(i<6)
    {
    	ret = queue_put(&queue,&data_array[i]);
    	if(ret < 0)
    	{
    		fprintf(stderr,"put failed\n");
    		return -2;
    	}
    	i++;
    }

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