/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** tests_thread_const_dest.c
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "thread.h"

Test(thread_const_dest, test_impl)
{
    thread_t thread = { 0 };

    cr_assert(eq(int, THREAD_NO_ERROR, thread_init(&thread)));
    cr_assert(eq(int, THREAD_NO_ERROR, thread_destroy(&thread)));
}

Test(thread_const_dest, test_err)
{
    thread_t thread = { 0 };

    cr_assert(eq(int, THREAD_INVALID_PTR, thread_init(NULL)));
    cr_assert(eq(int, THREAD_INVALID_PTR, thread_cancel(NULL)));
    cr_assert(eq(int, THREAD_INVALID_PTR, thread_destroy(NULL)));
    cr_assert(eq(int, THREAD_CANCEL_FAILED, thread_cancel(&thread)));
}
