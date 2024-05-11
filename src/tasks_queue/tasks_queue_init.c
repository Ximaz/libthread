/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** tasks_queue_init.c
*/

#include <stddef.h>
#include "tasks_queue.h"

tasks_queue_error_t tasks_queue_init(tasks_queue_t *this)
{
    if (NULL == this)
        return TASKS_QUEUE_INVALID_PTR;
    if (0 != pthread_mutex_init(&(this->_mutex), NULL))
        return TASKS_QUEUE_MUTEX_INIT_FAILED;
    this->_front = NULL;
    this->_rear = NULL;
    return TASKS_QUEUE_NO_ERROR;
}
