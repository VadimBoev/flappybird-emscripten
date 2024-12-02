cmake_minimum_required(VERSION 3.8)

project("flappybird-emscripten")

set(EMSDK "G:/emsdk")

set(EMSDK_NODE "${EMSDK}/node/20.18.0_64bit/bin/node.exe")
set(EMSDK_PATH_NODE "${EMSDK}/node/20.18.0_64bit/bin")
set(EMSDK_PYTHON "${EMSDK}/python/3.9.2-nuget_64bit/python.exe")
set(EMSDK_EMSCRIPTEN_DIR "${EMSDK}/upstream/emscripten")
set(CLANG_PATH "${EMSDK}/upstream/bin")

set(CMAKE_TOOLCHAIN_FILE "${EMSDK_EMSCRIPTEN_DIR}/cmake/Modules/Platform/Emscripten.cmake")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s WASM=1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_WEBGL2=0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s FULL_ES2=1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s NO_EXIT_RUNTIME=1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s ALLOW_MEMORY_GROWTH=1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s FORCE_FILESYSTEM=1")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"../../../buttons\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"../../../sprites\"")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file \"../../../audio\"")

#include_directories("${EMSDK_EMSCRIPTEN_DIR}/system/lib/libcxx/include")
#include_directories("${EMSDK_EMSCRIPTEN_DIR}/system/include")
include_directories("${EMSDK_EMSCRIPTEN_DIR}/cache/sysroot/include")
#include_directories("${EMSDK_EMSCRIPTEN_DIR}/system/lib/libc/musl/include")
#include_directories("${EMSDK_EMSCRIPTEN_DIR}/system/lib/libc/musl/arch/emscripten")
#include_directories("${CMAKE_SOURCE_DIR}")

set(SOURCE_FILES
    game.c
    init.c
    mouse.c
    shaders.c
    texture.c
    upng.c
    utils.c
    audio.c
    main.c
)

add_executable(flappybird-emscripten ${SOURCE_FILES})

set(CMAKE_C_COMPILER "${EMSDK_EMSCRIPTEN_DIR}/emcc.bat")

if(NOT EXISTS "${CMAKE_C_COMPILER}")
  message(FATAL_ERROR "Emscripten compiler not found at ${CMAKE_C_COMPILER}")
endif()

execute_process(
  COMMAND ${EMSDK_PYTHON} ${EMSDK_EMSCRIPTEN_DIR}/emcc.py --version
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  RESULT_VARIABLE EMSCRIPTEN_SETUP_RESULT
)

if(NOT EMSCRIPTEN_SETUP_RESULT EQUAL 0)
  message(FATAL_ERROR "Failed to setup Emscripten environment")
endif()