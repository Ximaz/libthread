/*
** EPITECH PROJECT, 2024
** Threads in C
** File description:
** tests_thread_pool.c
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include "thread_pool.h"

static void *func(thread_arg_t *arg)
{
    write(1, "1", 1);
    return arg->arg;
}

Test(thread_pool, test_impl, .init = cr_redirect_stdout)
{
    tasks_queue_t tasks = { 0 };
    thread_pool_t pool = { 0 };

    cr_assert(eq(int, THREAD_POOL_INVALID_PTR,
        thread_pool_init(NULL, 100, &tasks)));
    cr_assert(eq(int, THREAD_POOL_INVALID_PTR,
        thread_pool_init(&pool, 100, NULL)));
    cr_assert(eq(int, THREAD_POOL_INVALID_SIZE,
        thread_pool_init(&pool, 0, &tasks)));
    cr_assert(eq(int, THREAD_POOL_INVALID_PTR, thread_pool_run(NULL)));
    cr_assert(eq(int, THREAD_POOL_INVALID_PTR, thread_pool_destroy(NULL)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_init(&tasks)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_push(&tasks, func)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_push(&tasks, func)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_push(&tasks, func)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_push(&tasks, func)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_push(&tasks, func)));
    cr_assert(eq(int, THREAD_POOL_NO_ERROR, thread_pool_init(&pool, 2, &tasks)));
    cr_assert(eq(int, THREAD_POOL_NO_ERROR, thread_pool_run(&pool)));
    cr_assert(eq(int, THREAD_POOL_NO_ERROR, thread_pool_destroy(&pool)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_destroy(&tasks)));
    cr_assert_stdout_eq_str("11111");
}
