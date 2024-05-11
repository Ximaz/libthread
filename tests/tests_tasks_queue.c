/*
** EPITECH PROJECT, 2024
** Threads in C
** File description:
** tests_tasks_queue.c
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "tasks_queue.h"

static void *func_1(thread_arg_t *arg)
{
    return arg->arg;
}

static void *func_2(thread_arg_t *arg)
{
    return arg->arg;
}

Test(tasks_queue, test_impl)
{
    tasks_queue_t queue = { 0 };

    cr_assert(eq(int, THREAD_INVALID_PTR, tasks_queue_init(NULL)));
    cr_assert(eq(int, THREAD_INVALID_PTR, tasks_queue_destroy(NULL)));
    cr_assert(eq(int, THREAD_INVALID_PTR, tasks_queue_push(NULL, func_1)));
    cr_assert(eq(int, THREAD_INVALID_PTR, tasks_queue_push(&queue, NULL)));
    cr_assert(eq(ptr, NULL, tasks_queue_pop(NULL)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_init(&queue)));
    cr_assert(eq(int, 1, tasks_queue_is_empty(&queue)));
    cr_assert(eq(ptr, NULL, tasks_queue_pop(&queue)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_push(&queue, func_1)));
    cr_assert(eq(int, 0, tasks_queue_is_empty(&queue)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_push(&queue, func_2)));
    cr_assert(eq(int, 0, tasks_queue_is_empty(&queue)));
    cr_assert(eq(ptr, func_1, tasks_queue_pop(&queue)));
    cr_assert(eq(int, 0, tasks_queue_is_empty(&queue)));
    cr_assert(eq(ptr, func_2, tasks_queue_pop(&queue)));
    cr_assert(eq(int, 1, tasks_queue_is_empty(&queue)));
    cr_assert(eq(ptr, NULL, queue._front));
    cr_assert(eq(ptr, NULL, queue._rear));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_push(&queue, func_1)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_push(&queue, func_1)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_push(&queue, func_1)));
    cr_assert(eq(int, TASKS_QUEUE_NO_ERROR, tasks_queue_destroy(&queue)));
}
