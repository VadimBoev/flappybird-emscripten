cmake_minimum_required(VERSION 3.8)

project("flappybird-emscripten")

# Установите путь к Emscripten SDK
set(EMSDK "G:/emsdk")

# Установите пути к инструментам Emscripten
set(EMSDK_NODE "${EMSDK}/node/20.18.0_64bit/bin/node.exe")
set(EMSDK_PATH_NODE "${EMSDK}/node/20.18.0_64bit/bin")
set(EMSDK_PYTHON "${EMSDK}/python/3.9.2-nuget_64bit/python.exe")
set(EMSDK_EMSCRIPTEN_DIR "${EMSDK}/upstream/emscripten")
set(CLANG_PATH "${EMSDK}/upstream/bin")

# Установите CMAKE_TOOLCHAIN_FILE
set(CMAKE_TOOLCHAIN_FILE "${EMSDK_EMSCRIPTEN_DIR}/cmake/Modules/Platform/Emscripten.cmake")

# Установите флаги компиляции и линковки для Emscripten
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_WEBGL2=0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s FULL_ES2=1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s NO_EXIT_RUNTIME=1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s ALLOW_MEMORY_GROWTH=1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s FORCE_FILESYSTEM=1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"buttons\\pause.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"buttons\\menu.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"buttons\\ok.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"buttons\\resume.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"buttons\\score.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"buttons\\share.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"buttons\\start.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\0.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\1.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\2.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\3.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\4.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\5.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\6.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\7.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\8.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\9.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\0_small.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\1_small.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\2_small.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\3_small.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\4_small.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\5_small.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\6_small.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\7_small.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\8_small.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\9_small.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\background-day.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\base.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\bronze-medal.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\gameover.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\gold-medal.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\logo.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\message.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\new.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\panel.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\pipe-green.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\platinum-medal.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\silver-medal.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\sparkle-sheet.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\yellowbird-downflap.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\yellowbird-midflap.png\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"sprites\\yellowbird-upflap.png\"")

# Включите директории с заголовочными файлами
#include_directories("${EMSDK_EMSCRIPTEN_DIR}/system/lib/libcxx/include")
#include_directories("${EMSDK_EMSCRIPTEN_DIR}/system/include")
include_directories("${EMSDK_EMSCRIPTEN_DIR}/cache/sysroot/include")
#include_directories("${EMSDK_EMSCRIPTEN_DIR}/system/lib/libc/musl/include")
#include_directories("${EMSDK_EMSCRIPTEN_DIR}/system/lib/libc/musl/arch/emscripten")
#include_directories("${CMAKE_SOURCE_DIR}")

# Найдите все исходные файлы
file(GLOB SOURCES "*.c")

# Добавьте исполняемый файл
add_executable(flappybird-emscripten ${SOURCES})

# Установите стандарт C (если используется C)
# set(CMAKE_C_STANDARD 99)

# Установите свойства для выходного файла
set_target_properties(flappybird-emscripten PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  OUTPUT_NAME "index"
  SUFFIX ".html"
)

# Установите компилятор Emscripten
set(CMAKE_C_COMPILER "${EMSDK_EMSCRIPTEN_DIR}/emcc.bat")
set(CMAKE_CXX_COMPILER "${EMSDK_EMSCRIPTEN_DIR}/em++.bat")

# Проверка существования компилятора
if(NOT EXISTS "${CMAKE_C_COMPILER}")
  message(FATAL_ERROR "Emscripten compiler not found at ${CMAKE_C_COMPILER}")
endif()

if(NOT EXISTS "${CMAKE_CXX_COMPILER}")
  message(FATAL_ERROR "Emscripten C++ compiler not found at ${CMAKE_CXX_COMPILER}")
endif()

# Настройка окружения перед запуском CMake
execute_process(
  COMMAND ${EMSDK_PYTHON} ${EMSDK_EMSCRIPTEN_DIR}/emcc.py --version
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  RESULT_VARIABLE EMSCRIPTEN_SETUP_RESULT
)

if(NOT EMSCRIPTEN_SETUP_RESULT EQUAL 0)
  message(FATAL_ERROR "Failed to setup Emscripten environment")
endif()