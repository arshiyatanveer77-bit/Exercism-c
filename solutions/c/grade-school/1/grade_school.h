#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

void init_roster(roster_t *roster);

bool add_student(roster_t *roster, const char *name, uint8_t grade);

roster_t get_grade(roster_t *roster, uint8_t grade);
roster_t get_roster(roster_t *roster);
// roster_t sort_by_gardes(student_t students[MAX_STUDENTS],size_t count);
// roster_t add_a_student(roster_t list,student_t new_student);
// roster_t get_grade(uint8_t grade,roster_t list);

#endif
