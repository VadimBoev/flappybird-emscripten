#include <emscripten.h>
#include <emscripten/html5.h>
#include "init.h"
#include "utils.h"
#include "mouse.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define TARGET_FPS 60
#define TARGET_FRAME_TIME (1.0f / TARGET_FPS)

double g_Time = 0.0;
float DeltaTime = 0.0f;
double g_LastFrameTime = 0.0;

bool handle_input(int eventType, const EmscriptenMouseEvent* mouseEvent, void* userData)
{
    if (eventType == EMSCRIPTEN_EVENT_MOUSEDOWN)
    {
        mouse.x = mouseEvent->clientX;
        mouse.y = mouseEvent->clientY;
        mouse.isDown = true;
    }
    else if (eventType == EMSCRIPTEN_EVENT_MOUSEUP)
    {
        mouse.x = mouseEvent->clientX;
        mouse.y = mouseEvent->clientY;
        mouse.isReleased = true;
    }
    else if (eventType == EMSCRIPTEN_EVENT_MOUSEMOVE)
    {
        mouse.x = mouseEvent->clientX;
        mouse.y = mouseEvent->clientY;
        mouse.isMoved = true;
    }
    return true;
}

void main_loop()
{
    struct timespec current_timespec;
    clock_gettime(CLOCK_MONOTONIC, &current_timespec);
    double current_time = (double)(current_timespec.tv_sec) + (current_timespec.tv_nsec / 1000000000.0);

    // calc delta time
    DeltaTime = g_Time > 0.0 ? (float)(current_time - g_Time) : (float)TARGET_FRAME_TIME;

    // checking if enough time has passed for a new frame
    if (current_time - g_LastFrameTime >= TARGET_FRAME_TIME)
    {
        MainLoopStep();
        MouseReset(&mouse);

        // update time last frame
        g_LastFrameTime = current_time;
    }

    g_Time = current_time;
}

int main()
{
    emscripten_set_canvas_element_size("#canvas", WindowSizeX, WindowSizeY);
    emscripten_set_mousemove_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, 1, handle_input);
    emscripten_set_mousedown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, 1, handle_input);
    emscripten_set_mouseup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, 1, handle_input);

    MouseInit(&mouse);

    Init();

    emscripten_set_main_loop(main_loop, 0, 1);

    return 0;
}