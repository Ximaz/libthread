/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** thread_join.c
*/

#include <stddef.h>
#include "thread.h"

NO_DISCARD thread_error_t thread_join(thread_t *this, void **ret_val)
{
    if (0 != pthread_join(this->_thread, ret_val))
        return THREAD_JOIN_FAILED;
    this->status = THREAD_DEAD;
    return THREAD_NO_ERROR;
}
