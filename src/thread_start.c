/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** thread_start.c
*/

#include <stddef.h>
#include "thread.h"

NO_DISCARD thread_error_t thread_start(thread_t *this, thread_function_t func,
    void *arg)
{
    thread_error_t err = THREAD_NO_ERROR;

    if (NULL == this)
        return THREAD_INVALID_PTR;
    this->_arg.arg = arg;
    if (0 != pthread_create(&(this->_thread), NULL,
        (void *(*)(void *)) func, (void *) &(this->_arg)))
        err = THREAD_START_FAILED;
    this->_status = THREAD_RUNNING;
    return err;
}
