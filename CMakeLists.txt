CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

PROJECT(stones)
SET(CMAKE_VERBOSE_MAKEFILE on)


ADD_EXECUTABLE ( stones
                 src/console.h
                 src/console.c
                 src/test.h
                 src/test.c
                 src/main.c )
    
    
 
