#include <emscripten.h>
#include <emscripten/html5.h>
#include <GLES2/gl2.h>
#include <stdio.h>

void main_loop() {
    // Очищаем буфер цвета в синий цвет
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Обновляем экран
    emscripten_webgl_commit_frame();
}

int main() {
    // Инициализация WebGL
    EmscriptenWebGLContextAttributes attrs;
    emscripten_webgl_init_context_attributes(&attrs);
    attrs.majorVersion = 1;
    attrs.minorVersion = 0;

    EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context = emscripten_webgl_create_context("#canvas", &attrs);
    if (context <= 0) {
        printf("Failed to create WebGL context!\n");
        return -1;
    }

    // Делаем контекст текущим
    emscripten_webgl_make_context_current(context);

    // Запускаем главный цикл
    emscripten_set_main_loop(main_loop, 0, 0);

    return 0;
}