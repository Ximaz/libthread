/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** tasks_queue.h
*/

#ifndef __TASKS_QUEUE_H_
    #define __TASKS_QUEUE_H_
    #include "thread.h"

typedef struct s_internal_tasks_queue {
    thread_task_t _task;
    struct s_internal_tasks_queue *_next;
} internal_tasks_queue_t;

typedef struct s_tasks_queue {
    pthread_mutex_t _mutex;
    internal_tasks_queue_t *_front;
    internal_tasks_queue_t *_rear;
} tasks_queue_t;

typedef enum e_tasks_queue_error {
    TASKS_QUEUE_NO_ERROR,
    TASKS_QUEUE_INVALID_PTR,
    TASKS_QUEUE_INIT_FAILED,
    TASKS_QUEUE_MUTEX_INIT_FAILED,
    TASKS_QUEUE_MUTEX_LOCK_FAILED,
    TASKS_QUEUE_MUTEX_DESTROY_FAILED,
    TASKS_QUEUE_PUSH_MEMORY_ALLOCATION_FAILED
} tasks_queue_error_t;

tasks_queue_error_t tasks_queue_init(tasks_queue_t *this);

tasks_queue_error_t tasks_queue_push(tasks_queue_t *this, thread_task_t task);

int tasks_queue_is_empty(tasks_queue_t *this);

thread_task_t tasks_queue_pop(tasks_queue_t *this);

tasks_queue_error_t tasks_queue_destroy(tasks_queue_t *this);

#endif /* !__TASKS_QUEUE_H_ */
