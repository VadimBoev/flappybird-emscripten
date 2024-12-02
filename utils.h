#ifndef UTILS_H
#define UTILS_H

void Log(const char* fmt, ...);

//#if defined(__aarch64__)
unsigned long long getTickCount();
//#else
//uint32_t getTickCount();
//#endif

#endif // UTILS_H