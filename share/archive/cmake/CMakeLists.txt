cmake_minimum_required(VERSION 3.16)

#set(CMAKE_C_COMPILER "gcc")

project(MORSE_CODE_DECODER LANGUAGES C)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(MORSELIB "${SRC}/morse_lib")

file(GLOB_RECURSE SOURCE "${MORSELIB}/*.c")
#add_library(MORSE STATIC ${SOURCE})
#target_include_directories(MORSE PUBLIC ${HEADERS})
#target_compile_options(MORSE PRIVATE -ggdb3 -std=c17 -Wall -Wextra)

add_executable(MorseCodeDecoder ${SRC}/main.c ${SOURCE})
target_include_directories(MorseCodeDecoder PUBLIC ${HEADERS})
target_compile_options(MorseCodeDecoder PRIVATE -ggdb3 -std=c17 -Wall -Wextra)
