//
// signal.h
//
// Signal handling
//
// Copyright (C) 2002 Michael Ringgaard. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 
// 1. Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.  
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.  
// 3. Neither the name of the project nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
// SUCH DAMAGE.
// 

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef SIGNAL_H
#define SIGNAL_H

#ifndef osapi
#define osapi __declspec(dllimport)
#endif

#ifndef SIGINT

#define SIGINT          2               // Interrupt
#define SIGILL          4               // Illegal instruction
#define SIGFPE          8               // Floating point exception
#define SIGSEGV         11              // Segment violation
#define SIGTERM         15              // Software termination signal
#define SIGBREAK        21              // Ctrl-Break sequence
#define SIGABRT         22              // Abnormal termination
#define SIGBUS          23              // Bus error
#define SIGTRAP         24              // Debug trap
#define SIGGUARD        25              // Guard page trap

#endif

#ifndef _SIGHANDLER_T_DEFINED
#define _SIGHANDLER_T_DEFINED
typedef void (*sighandler_t)(int signum);
#endif

#ifndef SIG_DFL

#define SIG_DFL ((sighandler_t) 0)
#define SIG_IGN ((sighandler_t) 1)
#define SIG_ERR ((sighandler_t) -1)

#endif

#ifdef  __cplusplus
extern "C" {
#endif

osapi sighandler_t signal(int signum, sighandler_t handler);
osapi void raise(int signum);

#ifdef  __cplusplus
}
#endif

#endif
