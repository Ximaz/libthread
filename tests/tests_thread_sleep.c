/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** tests_thread_sleep.c
*/

#include <sys/time.h>
#include <time.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "thread.h"

static struct timeval before = { 0, 0 };
static struct timeval after = { 0, 0 };
static const long sec = 3;

static void *thread_function(thread_arg_t *arg)
{
    gettimeofday(&before, NULL);
    thread_sleep(arg->this_thread, sec, 0);
    gettimeofday(&after, NULL);
    cr_assert(eq(long, sec, after.tv_sec - before.tv_sec));
    return arg->arg;
}

Test(thread_sleep, test_impl)
{
    thread_t thread = { 0 };
    void *ret_val = NULL;

    cr_assert(eq(int, THREAD_NO_ERROR, thread_init(&thread)));
    cr_assert(eq(int, THREAD_NO_ERROR,
        thread_start(&thread, thread_function, (void *) &thread)));
    cr_assert(eq(int, THREAD_NO_ERROR, thread_join(&thread, &ret_val)));
    cr_assert(eq(int, THREAD_NO_ERROR, thread_destroy(&thread)));
    cr_assert(eq(ptr, ret_val, &thread));
}

Test(thread_sleep, test_err)
{
    thread_t thread = { 0 };

    cr_assert(eq(int, THREAD_INVALID_PTR, thread_sleep(NULL, 1, 1)));
    cr_assert(eq(int, THREAD_INVALID_PTR,
        thread_sleep(&thread, 5, 0)));
    thread._status = THREAD_RUNNING;
    cr_assert(eq(int, THREAD_SLEEP_INVALID_VALUES,
        thread_sleep(&thread, -1, 0)));
    cr_assert(eq(int, THREAD_SLEEP_INVALID_VALUES,
        thread_sleep(&thread, 0, -1)));
    cr_assert(ne(int, THREAD_SLEEP_INVALID_VALUES,
        thread_sleep(&thread, 0, 0)));
}
