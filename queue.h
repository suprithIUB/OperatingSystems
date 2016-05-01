/*
 * This is the header file for an implemenation of a simple FIFO queue.
 */

#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
typedef struct queue_node_s {
	struct queue_node_s* next;
	void* payload;
} queue_node;

typedef struct queue_s {
	queue_node* first;
	queue_node* last;
	int size;
} queue;

void queue_init(queue* q);
int queue_is_empty(queue* q);
void queue_push(queue* q, void* payload);
void* queue_pop(queue* q);

#endif
