/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** tests_thread_cancel.c
*/

#include <stdio.h>
#include <limits.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "thread.h"

static void *thread_function(thread_arg_t *arg)
{
    unsigned long long i = 0;

    for (; i < ((unsigned long long) 1 << 63); ++i)
        ;
    return arg->arg;
}

Test(thread_cancel, test_impl)
{
    thread_t thread = { 0 };

    cr_assert(eq(int, THREAD_NO_ERROR, thread_init(&thread)));
    cr_assert(eq(int, THREAD_NO_ERROR,
        thread_start(&thread, thread_function, (void *) &thread)));
    cr_assert(eq(int, THREAD_RUNNING, thread.status));
    cr_assert(eq(int, THREAD_NO_ERROR, thread_cancel(&thread)));
    cr_assert(eq(int, THREAD_DEAD, thread.status));
    cr_assert(eq(int, THREAD_NO_ERROR, thread_destroy(&thread)));
}

Test(thread_cancel, test_err)
{
    thread_t thread = { 0 };

    cr_assert(eq(int, THREAD_INVALID_PTR, thread_cancel(NULL)));
    cr_assert(eq(int, THREAD_CANCEL_FAILED, thread_cancel(&thread)));
}
