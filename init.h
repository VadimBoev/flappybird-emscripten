#ifndef INIT_H
#define INIT_H

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <stdbool.h>

extern bool g_Initialized;
extern int32_t WindowSizeX;
extern int32_t WindowSizeY;

extern GLuint textureProgram;

extern GLuint colorProgram;
extern GLuint gPositionHandle;
extern GLuint gColorHandle;


void Init();
void MainLoopStep();
void Shutdown();

#endif // INIT_H