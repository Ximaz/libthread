/*
** EPITECH PROJECT, 2024
** Threads in C
** File description:
** thread_pool_init.c
*/

#include <stdlib.h>
#include "thread_pool.h"

thread_pool_error_t thread_pool_init(thread_pool_t *this, size_t pool_size,
    tasks_queue_t *tasks)
{
    size_t i = 0;

    if (NULL == this || NULL == tasks)
        return THREAD_POOL_INVALID_PTR;
    if (0 == pool_size)
        return THREAD_POOL_INVALID_SIZE;
    this->_threads = malloc(sizeof(thread_t) * pool_size);
    if (NULL == this->_threads)
        return THREAD_POOL_INIT_FAILED;
    this->_pool_size = pool_size;
    for (; i < pool_size; ++i)
        thread_init(&this->_threads[i]);
    this->_tasks = tasks;
    return THREAD_POOL_NO_ERROR;
}
