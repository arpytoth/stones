#include "console.h"


// Set terminal color.
// color The color. Should be one of the values from the ConsoleColor enum.
void SetConsoleColor(ConsoleColor color)
{
#ifdef _WIN32
    // Default
    WORD fore = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
    WORD back = 0;


    switch (color) {
    case ColorRed:
        fore = FOREGROUND_RED | FOREGROUND_INTENSITY;
        break;
    case ColorYellow:
        fore = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
        break;
    case ColorWhite:
        fore = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
        break;
    default:
        fprintf(stderr, "Invalid text color specified.");
        exit(1);
        break;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fore | 0);
#else
    printf("\033[0m");
    switch (color) {
    case ColorRed:
        printf("\33[31m");
        break;
    case ColorYellow:
        printf("\33[93m");
        break;
    case ColorWhite:
        printf("\33[0m");
        break;
    default:
        fprintf(stderr, "Invalid text color specified.");
        exit(1);
        break;
    }
#endif
}

// Print a text colored. This helps out other implementation with
// varidic arguments.
void ColorWriteHelper(ConsoleColor color, const char* format, va_list args)
{
  SetConsoleColor(color);
  vprintf(format, args);
  SetConsoleColor(ColorWhite);
}

// Similar to printf but support the color parameter that
// will cause your text to be printed colored.
void ColorWrite(ConsoleColor color, const char* format, ...)
{
  va_list args;
  va_start (args, format);

  ColorWriteHelper(color, format, args);

  va_end (args);
}

// Similar to printf but will first print out a prefix with
// a specified color than will print out the message with
// another specified color and then will print out endline.
void PrefixWriteHelper(ConsoleColor prefixColor, const char* prefix,
                  ConsoleColor textColor, const char* format, va_list args)
{
  ColorWrite(prefixColor, prefix);
  ColorWriteHelper(textColor, format, args);
  printf("\n");
}

// Write an error message to the console.
void WriteError(const char* format, ...)
{
  va_list args;
  va_start (args, format);

  PrefixWriteHelper(ColorRed, "[  ERROR   ] ", ColorWhite, format, args);

  va_end (args);
}

// Write a message with H1 style.
void WriteH1(const char* format, ...)
{
  va_list args;
  va_start (args, format);

  PrefixWriteHelper(ColorYellow, "[----------] ", ColorWhite, format, args);

  va_end (args);
}


// Write a message with H2 style.
void WriteH2(const char* format, ...)
{
  va_list args;
  va_start (args, format);

  PrefixWriteHelper(ColorYellow, "[==========] ", ColorWhite, format, args);

  va_end (args);
}

// Write a PASSED message.
void WritePassed(const char* format, ...)
{
  va_list args;
  va_start (args, format);

  PrefixWriteHelper(ColorYellow, "[  PASSED  ] ", ColorWhite, format, args);

  va_end (args);
}

// Write a RUN message.
void WriteRun(const char* format, ...)
{
  va_list args;
  va_start (args, format);

  PrefixWriteHelper(ColorYellow, "[ RUN      ] ", ColorWhite, format, args);

  va_end (args);
}

// Write an OK message.
void WriteOK(const char* format, ...)
{
  va_list args;
  va_start (args, format);

  PrefixWriteHelper(ColorYellow, "[       OK ] ", ColorWhite, format, args);

  va_end (args);
}

