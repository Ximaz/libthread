/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** tasks_queue_pop.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "tasks_queue.h"

thread_task_t tasks_queue_pop(tasks_queue_t *this)
{
    thread_task_t task = NULL;
    internal_tasks_queue_t *node = NULL;

    if (NULL == this || 0 != pthread_mutex_lock(&(this->_mutex)))
        return NULL;
    if (NULL == this->_front) {
        pthread_mutex_unlock(&(this->_mutex));
        return NULL;
    }
    node = this->_front;
    this->_front = this->_front->_next;
    task = node->_task;
    free(node);
    if (NULL == this->_front)
        this->_rear = NULL;
    pthread_mutex_unlock(&(this->_mutex));
    return task;
}
