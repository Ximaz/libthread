/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** thread.h
*/

#ifndef __THREAD_H_
    #define __THREAD_H_
    #include <pthread.h>
    #define NO_DISCARD __attribute__((warn_unused_result))

typedef enum e_thread_error {
    THREAD_NO_ERROR,
    THREAD_INVALID_PTR,
    THREAD_INIT_FAILED,
    THREAD_MUTEX_INIT_FAILED,
    THREAD_COND_INIT_FAILED,
    THREAD_DESTROY_FAILED,
    THREAD_MUTEX_DESTROY_FAILED,
    THREAD_COND_DESTROY_FAILED,
    THREAD_COND_TIMEDWAIT_FAILED,
    THREAD_CANCEL_FAILED,
    THREAD_START_FAILED,
    THREAD_JOIN_FAILED,
    THREAD_SLEEP_FAILED,
    THREAD_SLEEP_INVALID_VALUES,
    THREAD_SLEEP_CLOCK_GETTIME_FAILED
} thread_error_t;

typedef enum e_thread_status {
    THREAD_DEAD,
    THREAD_RUNNING,
    THREAD_SLEEPING
} thread_status_t;

struct s_thread;

typedef struct s_thread_arg {
    struct s_thread *this_thread;
    void *arg;
} thread_arg_t;

typedef void *(*thread_function_t)(thread_arg_t *arg);

typedef struct s_thread {
    thread_status_t _status;
    thread_arg_t _arg;
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
    pthread_t _thread;
} thread_t;

NO_DISCARD thread_error_t thread_init(thread_t *this);

thread_error_t thread_destroy(thread_t *this);

NO_DISCARD thread_error_t thread_cancel(thread_t *this);

NO_DISCARD thread_error_t thread_start(thread_t *this, thread_function_t func,
    void *arg);

NO_DISCARD thread_error_t thread_join(thread_t *this, void **ret_val);

thread_error_t thread_sleep(thread_t *this, long sec, long nsec);

#endif /* !__THREAD_H_ */
