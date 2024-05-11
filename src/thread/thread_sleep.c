/*
** EPITECH PROJECT, 2024
** Thread in C
** File description:
** thread_sleep.c
*/

#include <stddef.h>
#include <sys/time.h>
#include <time.h>
#include "thread.h"

static thread_error_t thread_prepare_clock(struct timespec *timeout, long sec,
    long nsec)
{
    struct timeval timeval = { 0 };

    if (0 > sec || 0 > nsec)
        return THREAD_SLEEP_INVALID_VALUES;
    if (0 != gettimeofday(&timeval, NULL))
        return THREAD_SLEEP_CLOCK_GETTIME_FAILED;
    timeout->tv_sec = timeval.tv_sec + sec;
    timeout->tv_nsec = timeval.tv_usec * 1000 + nsec;
    return THREAD_NO_ERROR;
}

static thread_error_t thread_pre_sleep(thread_t *this)
{
    this->_status = THREAD_SLEEPING;
    if (0 != pthread_mutex_init(&(this->_mutex), NULL))
        return THREAD_MUTEX_INIT_FAILED;
    if (0 != pthread_cond_init(&(this->_cond), NULL)) {
        pthread_mutex_destroy(&(this->_mutex));
        return THREAD_COND_INIT_FAILED;
    }
    return THREAD_NO_ERROR;
}

static thread_error_t thread_post_sleep(thread_t *this)
{
    thread_error_t err = THREAD_NO_ERROR;

    if (0 != pthread_mutex_destroy(&(this->_mutex)))
        err = THREAD_MUTEX_DESTROY_FAILED;
    if (0 != pthread_cond_destroy(&(this->_cond)))
        err = THREAD_COND_DESTROY_FAILED;
    this->_status = THREAD_RUNNING;
    return err;
}

thread_error_t thread_sleep(thread_t *this, long sec, long nsec)
{
    struct timespec timeout = { 0, 0 };
    thread_error_t err = THREAD_NO_ERROR;

    if (NULL == this || THREAD_RUNNING != this->_status)
        return THREAD_INVALID_PTR;
    err = thread_prepare_clock(&timeout, sec, nsec);
    if (THREAD_NO_ERROR != err)
        return err;
    err = thread_pre_sleep(this);
    if (THREAD_NO_ERROR != err)
        return err;
    if (0 != pthread_cond_timedwait(&(this->_cond), &(this->_mutex), &timeout))
        err = THREAD_COND_TIMEDWAIT_FAILED;
    this->_status = THREAD_RUNNING;
    if (THREAD_NO_ERROR == err)
        err = thread_post_sleep(this);
    else
        thread_post_sleep(this);
    return err;
}
