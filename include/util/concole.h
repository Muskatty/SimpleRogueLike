#ifndef CONSOLE_H
#define CONSOLE_H

#include <stdio.h>

#define SCREEN_SIZE 50

//Macro to print string "a  ...  b" of length SCREEN_SIZE
#define JUSTIFY(a, b) printf("%s%*s\n",a.c_str(), (int)(SCREEN_SIZE - a.length()), b.c_str())

void clear();

#endif