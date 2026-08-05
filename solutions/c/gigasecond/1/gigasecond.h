#ifndef GIGASECOND_H
#define GIGASECOND_H

#include <time.h>

void gigasecond(time_t input, char *output, size_t size);
size_t strftime(
    char *str,
    size_t maxsize,
    const char *format,
    const struct tm *timeptr
);

#endif
