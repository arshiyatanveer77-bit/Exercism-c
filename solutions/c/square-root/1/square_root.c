#include "square_root.h"

int square_root(int target)
{
    for (int i = 1; i <= target / i; i++) {
        if (i * i == target) {
            return i;
        }
    }

    return -1;
}