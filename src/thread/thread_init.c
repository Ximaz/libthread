/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** thread_init.c
*/

#include <stddef.h>
#include "thread.h"

thread_error_t thread_init(thread_t *this)
{
    if (NULL == this)
        return THREAD_INVALID_PTR;
    this->_arg.this_thread = this;
    this->_arg.arg = NULL;
    this->_status = THREAD_DEAD;
    return THREAD_NO_ERROR;
}
