/*
** EPITECH PROJECT, 2024
** Threads in C
** File description:
** thread_pool_run.c
*/

#include <stdio.h>
#include "thread_pool.h"

thread_pool_error_t thread_pool_run(thread_pool_t *this)
{
    size_t j = 0;
    size_t i = 0;

    if (NULL == this)
        return THREAD_POOL_INVALID_PTR;
    while (0 == tasks_queue_is_empty(this->_tasks)) {
        for (i = 0; i < this->_pool_size && 0 == tasks_queue_is_empty(this->_tasks);
            ++i)
            thread_start(&(this->_threads[i]), tasks_queue_pop(this->_tasks),
                NULL);
        for (j = 0; j < i; ++j)
            thread_join(&(this->_threads[j]), NULL);
    }
    return THREAD_POOL_NO_ERROR;
}
