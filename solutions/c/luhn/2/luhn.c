#include "luhn.h"
#include "luhn.h"
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool luhn(const char *num)
{
    int sum = 0;
    int digits = 0;
    bool double_digit = false;

    for (int i = strlen(num) - 1; i >= 0; i--)
    {
        if (num[i] == ' ')
        {
            continue;
        }

        if (!isdigit((unsigned char)num[i]))
        {
            return false;
        }

        int digit = num[i] - '0';
        digits++;

        if (double_digit)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
        double_digit = !double_digit;
    }

    if (digits < 2)
    {
        return false;
    }

    return sum % 10 == 0;
}
   