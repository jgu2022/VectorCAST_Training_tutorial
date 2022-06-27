#ifndef MACRO_REDEFINATION
#define MACRO_REDEFINATION

#include <stdio.h>
#define __FILENAME__ __FILE__

struct register_a
{
	int a;
	float b;
};

#define STM0   ((*(struct register_a*)0xF0001000u))

#endif