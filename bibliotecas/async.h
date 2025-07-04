/* async.h – Header‑only Windows async threading helper (C99)
 * MIT‑licensed – include this file to enable async_run()/async_run0(), async_join(), async_detach().
 * Usage: #include "async.h" in your main.c; compile only main.c:
 *   gcc -std=c99 -mthreads main.c -o demo.exe
 */

#ifndef ASYNC_H
#define ASYNC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <windows.h>

/// Opaque handle representando uma thread.
typedef HANDLE async_thread_t;

/// Wrapper para funções sem parâmetro.
static DWORD WINAPI thread_wrapper0(LPVOID param) {
    void (*func)(void) = (void (*)(void))param;
    func();
    return 0;
}

/// Inicia uma função sem parâmetros em nova thread.
/// @param func Ponteiro para função `void func(void)`.
static inline async_thread_t async_run0_impl(void (*func)(void)) {
    return CreateThread(NULL, 0, thread_wrapper0, (LPVOID)func, 0, NULL);
}

/// Estrutura de contexto para função com parâmetro.
typedef struct thread_ctx { void (*func)(void*); void *arg; } thread_ctx;

/// Wrapper para funções com parâmetro.
static DWORD WINAPI thread_wrapper(LPVOID param) {
    thread_ctx *ctx = (thread_ctx*)param;
    ctx->func(ctx->arg);
    HeapFree(GetProcessHeap(), 0, ctx);
    return 0;
}

/// Inicia uma função com parâmetro em nova thread.
/// @param func Ponteiro para função `void func(void*)`.
/// @param arg  Ponteiro genérico (struct, string, int*, etc.).
static inline async_thread_t async_run_impl(void (*func)(void*), void *arg) {
    thread_ctx *ctx = (thread_ctx*)HeapAlloc(GetProcessHeap(), 0, sizeof(thread_ctx));
    ctx->func = func;
    ctx->arg  = arg;
    return CreateThread(NULL, 0, thread_wrapper, ctx, 0, NULL);
}

/// Aguarda thread finalizar e fecha handle.
static inline void async_join(async_thread_t thr) {
    WaitForSingleObject(thr, INFINITE);
    CloseHandle(thr);
}

/// Fecha handle da thread sem aguardar término.
static inline void async_detach(async_thread_t thr) {
    CloseHandle(thr);
}

/// Macro para iniciar thread sem parâmetros.
#define async_run0(func)      async_run0_impl((void (*)(void))(func))
/// Macro para iniciar thread com parâmetro.
#define async_run(func, arg)  async_run_impl((void (*)(void*))(func), (void*)(arg))

#ifdef __cplusplus
}
#endif

#endif /* ASYNC_H */
