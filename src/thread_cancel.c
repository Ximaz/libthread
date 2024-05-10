/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** thread_cancel.c
*/

#include <stddef.h>
#include "thread.h"

NO_DISCARD thread_error_t thread_cancel(thread_t *this)
{
    if (NULL == this)
        return THREAD_INVALID_PTR;
    if (THREAD_RUNNING != this->_status || 0 != pthread_cancel(this->_thread))
        return THREAD_CANCEL_FAILED;
    this->_status = THREAD_DEAD;
    return THREAD_NO_ERROR;
}
