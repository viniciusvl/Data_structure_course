#ifndef QUEUE_H
#define QUEUE_H

struct queue_s{
    int MAX;
    int n; // number of element in the queue
    int begin;
    int *array;
};

struct queue_s *create_queue_s(int);

int emptyQueue(struct queue_s *);

int fullQueue(struct queue_s *);

void ins_queue_s(struct queue_s *, int);

int queueFull(struct queue_s *);

int remove_queue_s(struct queue_s *);

void showQueue(struct queue_s *);


#endif