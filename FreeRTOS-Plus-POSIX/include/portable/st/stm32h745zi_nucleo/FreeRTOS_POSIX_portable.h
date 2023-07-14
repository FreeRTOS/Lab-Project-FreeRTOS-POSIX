/*
 * Amazon FreeRTOS+POSIX V1.0.4
 * Copyright (C) 2018 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/**
 * @file FreeRTOS_POSIX_portable.h
 * @brief STM32 + GNU tools Port-specific configuration of FreeRTOS+POSIX.
 */

#ifndef _FREERTOS_POSIX_PORTABLE_H_
#define _FREERTOS_POSIX_PORTABLE_H_

/*
 * GNU Tools for STM32 already defines timespec and itimerspec.
 */
#define posixconfigENABLE_TIMESPEC 0
#include <sys/_timespec.h>

#define posixconfigENABLE_ITIMERSPEC 0
#include <sys/timespec.h>

/*
 * GNU Tools for STM32 already defines mode_t and clockit_t.
 */
#define posixconfigENABLE_MODE_T 0
#define posixconfigENABLE_CLOCKID_T 0

/* Disable timer_t from GNU Tools to avoid compilation warnings
 * of pointer to integer conversion.
 */
#define __timer_t_defined 1

/* Define _SYS__PTHREADTYPES_H_ to disable GNU Tools for STM32
 * definitions that differ from FreeRTOS+POSIX implementation.
 */
#define _SYS__PTHREADTYPES_H_
#include <sys/types.h>

/* Define posixconfigENABLE_SCHED_PARAM to skip our sched_param.
 * Excluding the entire header with _FREERTOS_POSIX_SCHED_H_
 * would miss sched_get_priority_max/min and sched_yield.
 */
#define posixconfigENABLE_SCHED_PARAM 0
#include <sys/sched.h>


#endif /* _FREERTOS_POSIX_PORTABLE_H_ */
