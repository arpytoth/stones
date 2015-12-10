#ifndef _STONES_CONSOLE_H_
#define _STONES_CONSOLE_H_

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// Enumeration of all supported text colors.
typedef enum ConsoleColor
{
  ColorWhite,
  ColorRed,
  ColorYellow,
} ConsoleColor;


void WriteError(const char* format, ...);
void WriteH1(const char* format, ...);
void WriteH2(const char* format, ...);
void WritePassed(const char* format, ...);
void WriteRun(const char* format, ...);
void WriteOK(const char* format, ...);

#endif // _STONES_CONSOLE_H_
