#include "triangle.h"
#include <math.h>

#define EPSILON 1e-10

static bool equal(double x, double y)
{
    return fabs(x - y) < EPSILON;
}

static bool valid_triangle(triangle_t sides)
{
    if (sides.a <= 0 || sides.b <= 0 || sides.c <= 0)
        return false;

    if (sides.a + sides.b < sides.c ||
        equal(sides.a + sides.b, sides.c))
        return false;

    if (sides.a + sides.c < sides.b ||
        equal(sides.a + sides.c, sides.b))
        return false;

    if (sides.b + sides.c < sides.a ||
        equal(sides.b + sides.c, sides.a))
        return false;

    return true;
}

bool is_equilateral(triangle_t sides)
{
    if (!valid_triangle(sides))
        return false;

    return equal(sides.a, sides.b) &&
           equal(sides.b, sides.c);
}

bool is_isosceles(triangle_t sides)
{
    if (!valid_triangle(sides))
        return false;

    return equal(sides.a, sides.b) ||
           equal(sides.b, sides.c) ||
           equal(sides.a, sides.c);
}

bool is_scalene(triangle_t sides)
{
    if (!valid_triangle(sides))
        return false;

    return !equal(sides.a, sides.b) &&
           !equal(sides.b, sides.c) &&
           !equal(sides.a, sides.c);
}