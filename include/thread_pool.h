/*
** EPITECH PROJECT, 2024
** Threads in C
** File description:
** thread_pool.h
*/

#ifndef __THREAD_POOL_H_
    #define __THREAD_POOL_H_
    #include <stddef.h>
    #include "thread.h"
    #include "tasks_queue.h"

typedef enum e_thread_pool_error {
    THREAD_POOL_NO_ERROR,
    THREAD_POOL_INVALID_PTR,
    THREAD_POOL_INVALID_SIZE,
    THREAD_POOL_INIT_FAILED
} thread_pool_error_t;

typedef struct s_thread_pool {
    size_t _pool_size;
    thread_t *_threads;
    tasks_queue_t *_tasks;
} thread_pool_t;

thread_pool_error_t thread_pool_init(thread_pool_t *this, size_t pool_size,
    tasks_queue_t *tasks);

thread_pool_error_t thread_pool_run(thread_pool_t *this);

thread_pool_error_t thread_pool_destroy(thread_pool_t *this);

#endif /* !__THREAD_POOL_H_ */
