cmake_minimum_required(VERSION 3.8)

project("flappybird-emscripten")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s WASM=1")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_WEBGL2=0 -s FULL_ES2=1 -s NO_EXIT_RUNTIME=1 -s ALLOW_MEMORY_GROWTH=1")

include_directories("G:/emsdk/upstream/emscripten/system/include")

add_executable(flappybird-emscripten "main.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET flappybird-emscripten PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(flappybird-emscripten PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  OUTPUT_NAME "index"
  SUFFIX ".html"
)