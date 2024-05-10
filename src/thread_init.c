/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** thread_init.c
*/

#include <stddef.h>
#include "thread.h"

NO_DISCARD thread_error_t thread_init(thread_t *this)
{
    if (NULL == this)
        return THREAD_INVALID_PTR;
    if (0 != pthread_mutex_init(&(this->_mutex), NULL))
        return THREAD_MUTEX_INIT_FAILED;
    if (0 != pthread_cond_init(&(this->_cond), NULL)) {
        pthread_mutex_destroy(&(this->_mutex));
        return THREAD_COND_INIT_FAILED;
    }
    this->arg.this = this;
    this->arg.arg = NULL;
    this->status = THREAD_DEAD;
    return THREAD_NO_ERROR;
}
