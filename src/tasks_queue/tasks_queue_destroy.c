/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** tasks_queue_destroy.c
*/

#include <stdlib.h>
#include "tasks_queue.h"

tasks_queue_error_t tasks_queue_destroy(tasks_queue_t *this)
{
    internal_tasks_queue_t *node = NULL;

    if (NULL == this)
        return TASKS_QUEUE_INVALID_PTR;
    pthread_mutex_lock(&(this->_mutex));
    node = this->_front;
    while (NULL != node) {
        this->_front = node->_next;
        free(node);
        node = this->_front;
    }
    pthread_mutex_unlock(&(this->_mutex));
    if (0 != pthread_mutex_destroy(&(this->_mutex)))
        return TASKS_QUEUE_MUTEX_DESTROY_FAILED;
    return TASKS_QUEUE_NO_ERROR;
}
