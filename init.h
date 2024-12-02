#ifndef INIT_H
#define INIT_H

#include <stdbool.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>

extern bool g_Initialized;
extern int WindowSizeX;
extern int WindowSizeY;

extern GLuint textureProgram;

extern GLuint colorProgram;
extern GLuint gPositionHandle;
extern GLuint gColorHandle;


void Init();
void MainLoopStep();
void Shutdown();

#endif // INIT_H