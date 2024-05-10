/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** tests_thread_flow.c
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "thread.h"

static void *thread_function(thread_arg_t *arg)
{
    printf("Thread's address: %p\n", arg->this);
    printf("Argument's address: %p\n", arg->arg);
    return arg->arg;
}

Test(thread_flow, test_impl)
{
    thread_t thread = { 0 };
    void *ret_val = NULL;

    cr_assert(eq(int, THREAD_NO_ERROR, thread_init(&thread)));
    cr_assert(eq(int, THREAD_NO_ERROR,
        thread_start(&thread, thread_function, (void *) &thread)));
    cr_assert(eq(int, THREAD_RUNNING, thread.status));
    cr_assert(eq(int, THREAD_NO_ERROR, thread_join(&thread, &ret_val)));
    cr_assert(eq(int, THREAD_DEAD, thread.status));
    cr_assert(eq(int, THREAD_NO_ERROR, thread_destroy(&thread)));
    cr_assert(eq(ptr, ret_val, &thread));
}
