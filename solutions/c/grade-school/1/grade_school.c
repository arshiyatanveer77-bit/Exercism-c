#include "grade_school.h"
#include <string.h>

void init_roster(roster_t *roster)
{
    roster->count = 0;
}

bool add_student(roster_t *roster, const char *name, uint8_t grade)
{
    for (size_t i = 0; i < roster->count; i++)
    {
        if (strcmp(roster->students[i].name, name) == 0)
        {
            return false;
        }
    }

    if (roster->count >= MAX_STUDENTS)
    {
        return false;
    }

    size_t position = roster->count;

    for (size_t i = 0; i < roster->count; i++)
    {
        if (grade < roster->students[i].grade)
        {
            position = i;
            break;
        }

        if (grade == roster->students[i].grade &&
            strcmp(name, roster->students[i].name) < 0)
        {
            position = i;
            break;
        }
    }

    for (size_t i = roster->count; i > position; i--)
    {
        roster->students[i] = roster->students[i - 1];
    }

    roster->students[position].grade = grade;
    strcpy(roster->students[position].name, name);
    roster->count++;

    return true;
}

roster_t get_grade(roster_t *roster, uint8_t grade)
{
    roster_t result;
    result.count = 0;

    for (size_t i = 0; i < roster->count; i++)
    {
        if (roster->students[i].grade == grade)
        {
            result.students[result.count] = roster->students[i];
            result.count++;
        }
    }

    /* Sort names alphabetically */
    for (size_t i = 0; i + 1 < result.count; i++)
    {
        for (size_t j = 0; j + 1 < result.count - i; j++)
        {
            if (strcmp(result.students[j].name,
                       result.students[j + 1].name) > 0)
            {
                student_t temp = result.students[j];
                result.students[j] = result.students[j + 1];
                result.students[j + 1] = temp;
            }
        }
    }

    return result;
}

roster_t get_roster(roster_t *roster)
{
    roster_t result = *roster;

    for (size_t i = 0; i + 1 < result.count; i++)
    {
        for (size_t j = 0; j + 1 < result.count - i; j++)
        {
            if (result.students[j].grade > result.students[j + 1].grade)
            {
                student_t temp = result.students[j];
                result.students[j] = result.students[j + 1];
                result.students[j + 1] = temp;
            }
            else if (result.students[j].grade == result.students[j + 1].grade &&
                     strcmp(result.students[j].name,
                            result.students[j + 1].name) > 0)
            {
                student_t temp = result.students[j];
                result.students[j] = result.students[j + 1];
                result.students[j + 1] = temp;
            }
        }
    }

    return result;
}