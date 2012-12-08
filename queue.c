#include "queue.h"
#include <stdlib.h>
#include <assert.h>
int queue_init(struct Queue* self)
{
    if(self == NULL)
        return -1;
    else
    {
        self->head = NULL;
        self->tail = NULL;
    }
    return 0;
}

int queue_empty(struct Queue* self)
{
    return self->head == NULL;
}

int queue_put(struct Queue* self, void* data)
{
    assert(self != NULL && data != NULL);
    struct Queue_node *newnode = (struct Queue_node*)malloc(sizeof(Queue_node));
    if(newnode == NULL)
        return -1;
    else
    {
        newnode->data = data;
        newnode->next = NULL;
        if(self->head == NULL)
        {
            self->head = newnode;
            self->tail = newnode;
        }
        else
        {
            self->tail->next = newnode;
            self->tail = newnode;
        }
        return 0;
    }

}

void* queue_get(struct Queue* self)
{
    void* data = NULL;
    if(queue_empty(self) == 1)
        return NULL;
    else
    {
        data = self->head->data;
        struct Queue_node* next = self->head->next;
        free(self->head);
        self->head=next;
        return data;
    }
}

