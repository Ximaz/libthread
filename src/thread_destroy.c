/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** thread_destroy.c
*/

#include <stddef.h>
#include "thread.h"

thread_error_t thread_destroy(thread_t *this)
{
    thread_error_t err = THREAD_NO_ERROR;

    if (NULL == this)
        return THREAD_INVALID_PTR;
    if (THREAD_DEAD != this->status) {
        pthread_detach(this->_thread);
        err = thread_cancel(this);
    }
    if (0 != pthread_mutex_destroy(&(this->_mutex)))
        err = THREAD_MUTEX_DESTROY_FAILED;
    if (0 != pthread_cond_destroy(&(this->_cond)))
        err = THREAD_COND_DESTROY_FAILED;
    return err;
}
