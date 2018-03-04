#include <limits.h>
#include "minunit.h"
#include "common.c"

extern int tests_run;

static char * int_to_int_1() {
  int val = 0;
  void * void_val = &val;
  mu_assert("error, val != 5", int_to_int(void_val) == 0);
  return 0;
}

static char * int_to_int_2() {
  int val = INT_MAX;
  void * void_val = &val;
  mu_assert("error, val != INT_MAX", int_to_int(void_val) == INT_MAX);
  return 0;
}

static char * int_to_int_3() {
  int val = INT_MIN;
  void * void_val = &val;
  mu_assert("error, val != INT_MIN", int_to_int(void_val) == INT_MIN);
  return 0;
}

char * common_tests() {
  mu_run_test(int_to_int_1);
  mu_run_test(int_to_int_2);
  mu_run_test(int_to_int_3);
  return 0;
}
