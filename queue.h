#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct Queue_node
{
	void *data;
	struct Queue_node* next;
}Queue_node;

typedef struct Queue
{
    struct Queue_node * head;
    struct Queue_node *tail;
}Queue;


int queue_init(struct Queue* self);
int queue_empty(struct Queue* self);
int queue_put(struct Queue* self, void* data);
void* queue_get(struct Queue* self);

#endif
