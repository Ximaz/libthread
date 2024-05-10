/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** thread_destroy.c
*/

#include <stdio.h>
#include <stddef.h>
#include "thread.h"

thread_error_t thread_destroy(thread_t *this)
{
    thread_error_t err = THREAD_NO_ERROR;

    if (NULL == this)
        return THREAD_INVALID_PTR;
    if (THREAD_DEAD != this->_status) {
        pthread_detach(this->_thread);
        err = thread_cancel(this);
    }
    return err;
}
