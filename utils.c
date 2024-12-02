#include <stdarg.h>
#include <stdint.h>
#include <emscripten/emscripten.h>
#include <time.h>
#include "utils.h"
#include <stdio.h>

void Log(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    // Определяем буфер для форматированной строки
    char buffer[1024];

    // Форматируем строку с помощью vsnprintf
    vsnprintf(buffer, sizeof(buffer), fmt, args);

    // Передаем форматированную строку в EM_ASM
    EM_ASM({
        console.log(UTF8ToString($0));
        }, buffer);

    va_end(args);
}

unsigned long long getTickCount()
{
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return (uint64_t)now.tv_sec * 1000 + (uint64_t)now.tv_nsec / 1000000;
}