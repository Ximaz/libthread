/*
** EPITECH PROJECT, 2024
** Threads in C
** File description:
** thread_pool_destroy.c
*/

#include <stdlib.h>
#include "thread_pool.h"

thread_pool_error_t thread_pool_destroy(thread_pool_t *this)
{
    size_t i = 0;

    if (NULL == this)
        return THREAD_POOL_INVALID_PTR;
    for (; i < this->_pool_size; ++i)
        thread_destroy(&(this->_threads[i]));
    free(this->_threads);
    return THREAD_POOL_NO_ERROR;
}
