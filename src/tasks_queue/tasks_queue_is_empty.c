/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** tasks_queue_is_empty.c
*/

#include "tasks_queue.h"

int tasks_queue_is_empty(tasks_queue_t *this)
{
    int is_empty = 0;

    if (0 != pthread_mutex_lock(&(this->_mutex)))
        return -1;
    is_empty = this->_front == NULL;
    pthread_mutex_unlock(&(this->_mutex));
    return is_empty;
}
