#include <emscripten.h>
#include <emscripten/html5.h>
#include "init.h"
#include "utils.h"
#include "mouse.h"

#define TARGET_FPS 60
#define TARGET_FRAME_TIME (1.0f / TARGET_FPS)

double g_Time = 0.0;
float DeltaTime = 0.0f;
double g_LastFrameTime = 0.0;

bool handle_input(int eventType, const EmscriptenMouseEvent* mouseEvent, void* userData) {
    if (eventType == EMSCRIPTEN_EVENT_MOUSEDOWN) {
        mouse.x = mouseEvent->canvasX;
        mouse.y = mouseEvent->canvasY;
        mouse.isDown = true;
    } else if (eventType == EMSCRIPTEN_EVENT_MOUSEUP) {
        mouse.x = mouseEvent->canvasX;
        mouse.y = mouseEvent->canvasY;
        mouse.isReleased = true;
    } else if (eventType == EMSCRIPTEN_EVENT_MOUSEMOVE) {
        mouse.x = mouseEvent->canvasX;
        mouse.y = mouseEvent->canvasY;
        mouse.isMoved = true;
    }
    return true; // Return true to indicate that the event has been handled
}

void main_loop() {
    if (g_Initialized) {
        struct timespec current_timespec;
        clock_gettime(CLOCK_MONOTONIC, &current_timespec);
        double current_time = (double)(current_timespec.tv_sec) + (current_timespec.tv_nsec / 1000000000.0);

        // calc delta time
        DeltaTime = g_Time > 0.0 ? (float)(current_time - g_Time) : (float)TARGET_FRAME_TIME;

        // checking if enough time has passed for a new frame
        if (current_time - g_LastFrameTime >= TARGET_FRAME_TIME) {
            MainLoopStep();
            MouseReset(&mouse);

            // update time last frame
            g_LastFrameTime = current_time;
        }

        g_Time = current_time;
    }
}

int main(int argc, char** argv) {
    emscripten_set_mousemove_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, 1, handle_input);
    emscripten_set_mousedown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, 1, handle_input);
    emscripten_set_mouseup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, 1, handle_input);

    Init(); // Pass NULL or adapt to Web environment
    emscripten_set_main_loop(main_loop, 0, 1);
    return 0;
}