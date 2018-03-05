#include "common.c"
#include <limits.h>
#include "minunit.h"

extern int tests_run;

static char* int_to_int_1() {
  int val = 0;
  void* void_val = &val;
  mu_assert("error, val != 5", int_to_int(void_val) == 0);
  return 0;
}

static char* int_to_int_2() {
  int val = INT_MAX;
  void* void_val = &val;
  mu_assert("error, val != INT_MAX", int_to_int(void_val) == INT_MAX);
  return 0;
}

static char* int_to_int_3() {
  int val = INT_MIN;
  void* void_val = &val;
  mu_assert("error, val != INT_MIN", int_to_int(void_val) == INT_MIN);
  return 0;
}

static char* swap_1() {
  int a = INT_MIN;
  int b = INT_MAX;
  swap(&a, &b, sizeof(a));
  mu_assert("error, int swap failed", a == INT_MAX && b == INT_MIN);
  return 0;
}

static char* swap_2() {
  struct test_type {
    int int_val;
    char char_val;
  };
  struct test_type a = {INT_MIN, CHAR_MIN};
  struct test_type b = {INT_MAX, CHAR_MAX};
  swap(&a, &b, sizeof(a));
  mu_assert("error, struct swap failed",
            a.int_val == INT_MAX && a.char_val == CHAR_MAX &&
                b.int_val == INT_MIN && b.char_val == CHAR_MIN);
  return 0;
}

static char* swap_3() {
  double a = -1.1;
  double b = 100;
  swap(&a, &b, sizeof(a));
  swap(&a, &b, sizeof(a));
  mu_assert("error, swap twice failed", a == -1.1 && b == 100);
  return 0;
}

char* common_tests() {
  mu_run_test(int_to_int_1);
  mu_run_test(int_to_int_2);
  mu_run_test(int_to_int_3);
  mu_run_test(swap_1);
  mu_run_test(swap_2);
  mu_run_test(swap_3);
  return 0;
}
