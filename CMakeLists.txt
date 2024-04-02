cmake_minimum_required(VERSION 3.16)
#ONLY SUITABLE FOR PERSONAL PROJECTS
#COMPIER
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_C_COMPILER "gcc") # GCC version > 10 #x86_64-w64-mingw32-gcc does not work
set(CMAKE_C_STANDARD 17)  # THE DOCUMENTATION OF THIS STANDARD USED WHILE CODING   
set(CMAKE_C_STANDARD_REQUIRED ON) # Therefore this is set on
#FLAGS
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -ggdb3") 
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
#PROJECT
project(MORSE_CODE_DECODER LANGUAGES C)
enable_language(C)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
# HOW TO COMPILE AND FILE LOCATIONS
set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/src") # set main.c dir and sub directory style library but can be libries without any change.
set(INC "${CMAKE_CURRENT_SOURCE_DIR}/inc") # INCLUDE_DIRECTORY ./inc/  where all headers *.h files are. main.h links them all.
file(GLOB_RECURSE LIB_SRC "${SRC}/*/*.c") # GET LIB_SRC. You can have multiple libraries and it will compile to 1 static library .a file that gets linked but here only src/morse_lib
# LINK FILES
add_library(MORSE_LIB STATIC ${LIB_SRC}) # Add library .c files
add_executable(MorseCodeDecoder ${SRC}/main.c) #Add main.c
target_link_libraries(MorseCodeDecoder MORSE_LIB) # LINK main.c and static libraries src/morse_lib
include_directories(BEFORE ${INC}) # COMMON HEADERS DIRECTORY main.h is ONLY HEADER need 
