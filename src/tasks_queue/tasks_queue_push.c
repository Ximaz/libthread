/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** tasks_queue_push.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "tasks_queue.h"

static void tasks_queue_safe_push(tasks_queue_t *this, thread_task_t task,
    internal_tasks_queue_t *node)
{
    node->_next = NULL;
    node->_task = task;
    if (NULL == this->_front) {
        this->_front = node;
        this->_rear = this->_front;
    } else {
        this->_rear->_next = node;
        this->_rear = this->_rear->_next;
    }
}

tasks_queue_error_t tasks_queue_push(tasks_queue_t *this, thread_task_t task)
{
    internal_tasks_queue_t *node = NULL;

    if (NULL == this || NULL == task)
        return TASKS_QUEUE_INVALID_PTR;
    if (0 != pthread_mutex_lock(&(this->_mutex)))
        return TASKS_QUEUE_MUTEX_LOCK_FAILED;
    node = malloc(sizeof(internal_tasks_queue_t));
    if (NULL == node) {
        pthread_mutex_unlock(&(this->_mutex));
        return TASKS_QUEUE_PUSH_MEMORY_ALLOCATION_FAILED;
    }
    tasks_queue_safe_push(this, task, node);
    pthread_mutex_unlock(&(this->_mutex));
    return TASKS_QUEUE_NO_ERROR;
}
