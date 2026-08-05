#include "acronym.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
char *abbreviate(const char *phrase)
{
    
    if (phrase == NULL)
        return NULL;

    char *acronym = malloc(strlen(phrase) + 1);

    if (acronym == NULL)
        return NULL;

    if (phrase[0] == '\0')
{
    free(acronym);
    return NULL;
}
    

    int j=0;
    for (int i = 0; phrase[i] != '\0'; i++)
    {if ((i == 0 ||
     phrase[i - 1] == ' ' ||
     phrase[i - 1] == '-' ||
     phrase[i - 1] == '_') &&
    isalpha((unsigned char)phrase[i]))
{
    acronym[j++] = toupper((unsigned char)phrase[i]);
}
    }

    acronym[j] = '\0';
    return acronym;
}