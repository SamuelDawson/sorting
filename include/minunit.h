/* JTN002 - MinUnit -- a minimal unit testing framework for C
   http://www.jera.com/techinfo/jtns/jtn002.html
*/

#ifndef MINUNIT_H
#define MINUNIT_H

#include <stdio.h>

#define COLORS 1

#if COLORS == 1

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#else

#define KNRM
#define KRED
#define KGRN
#define KYEL
#define KBLU
#define KMAG
#define KCYN
#define KWHT

#endif

#define mu_assert(message, test) \
  do {                           \
    if (!(test)) return message; \
  } while (0)
/*
#define mu_run_test(test)        \
  do {                           \
    char* message = test();      \
    tests_run++;                 \
    if (message) return message; \
  } while (0)
*/

#define mu_run_test(test)                   \
  do {                                      \
    char* message = test();                 \
    tests_run++;                            \
    printf("Test: %s: ", #test);            \
    if (!message) {                         \
      printf(KGRN "Passed");                \
      tests_passed++;                       \
    }                                       \
    else {                                  \
      printf(KRED "Failed");                \
      printf("%s", message);                \
    }                                       \
    printf("\n" KNRM);                      \
  } while (0);

extern int tests_run;
extern int tests_passed;

#endif
