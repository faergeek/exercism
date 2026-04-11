#include "grade_school.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_students(const void *, const void *);

int compare_students(const void *void_a, const void *void_b) {
  student_t *a = (student_t *)void_a;
  student_t *b = (student_t *)void_b;

  int grade_compare_result = (int)a->grade - b->grade;

  return grade_compare_result == 0 ? strcmp(a->name, b->name)
                                   : grade_compare_result;
}

void init_roster(roster_t *roster) { memset(roster, 0, sizeof(roster_t)); }

bool add_student(roster_t *roster, const char *name, uint8_t grade) {
  student_t *student;

  for (size_t i = 0; i < roster->count; i++) {
    student = &roster->students[i];

    if (strcmp(student->name, name) == 0) {
      return false;
    }
  }

  student = &roster->students[roster->count++];
  student->grade = grade;
  strncpy(student->name, name, MAX_NAME_LENGTH);

  qsort(roster->students, roster->count, sizeof(student_t), compare_students);

  return true;
}

roster_t get_grade(roster_t *roster, uint8_t grade) {
  roster_t grade_roster;
  init_roster(&grade_roster);

  for (size_t i = 0; i < roster->count; i++) {
    student_t *student = &roster->students[i];

    if (student->grade == grade) {
      memcpy(&grade_roster.students[grade_roster.count], student,
             sizeof(student_t));

      grade_roster.count++;
    }
  }

  return grade_roster;
}
