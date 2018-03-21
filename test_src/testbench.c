#include "testbench.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "minunit.h"
#include "samsort.h"

#define ARR_SIZE_DEFAULT 10000
#define MAX_VAL INT_MAX

extern int compare_int(const void*, const void*);
int tests_run, tests_passed;

struct test_struct {
  int dummy1;
  char dummy2;
  uint64_t val;
  short dummy3;
};

// A standard comp function
int compare_test_struct(const void* v1, const void* v2) {
  struct test_struct a = *(struct test_struct*)v1;
  struct test_struct b = *(struct test_struct*)v2;
  if (a.val < b.val)
    return -1;
  else if (a.val == b.val)
    return 0;
  else
    return 1;
}

static int sort_test_struct(void (*sort)(), size_t arr_size) {
  struct test_struct *arr_1, *arr_2, *arr_3;
  size_t i;
  int success = 1;
  arr_1 = malloc(sizeof(*arr_1) * arr_size);
  arr_2 = malloc(sizeof(*arr_2) * arr_size);
  arr_3 = malloc(sizeof(*arr_3) * arr_size);
  for (i = 0; i < arr_size; i++) {
    arr_1[i].val = (rand() % MAX_VAL * 2) - MAX_VAL;
  }
  memcpy(arr_2, arr_1, sizeof(*arr_1) * arr_size);
  qsort(arr_2, arr_size, sizeof(*arr_2), compare_test_struct);
  memcpy(arr_3, arr_1, sizeof(*arr_1) * arr_size);
  sort(arr_3, arr_size, sizeof(*arr_3), compare_test_struct);
  // Compare results
  for (i = 0; i < arr_size; i++) {
    if (arr_2[i].val != arr_3[i].val) {
      success = 0;
    }
  }
  free(arr_1);
  free(arr_2);
  free(arr_3);
  return success;
}

static int sort_test_int(void (*sort)(), size_t arr_size) {
  int *arr_1, *arr_2, *arr_3;
  size_t i;
  int success = 1;
  arr_1 = malloc(sizeof(*arr_1) * arr_size);
  arr_2 = malloc(sizeof(*arr_2) * arr_size);
  arr_3 = malloc(sizeof(*arr_3) * arr_size);
  for (i = 0; i < arr_size; i++) {
    arr_1[i] = (rand() % MAX_VAL * 2) - MAX_VAL;
  }
  memcpy(arr_2, arr_1, sizeof(*arr_1) * arr_size);
  qsort(arr_2, arr_size, sizeof(*arr_2), compare_int);
  memcpy(arr_3, arr_1, sizeof(*arr_1) * arr_size);
  sort(arr_3, arr_size, sizeof(*arr_3), compare_int);
  // Compare results
  for (i = 0; i < arr_size; i++) {
    if (arr_2[i] != arr_3[i]) {
      success = 0;
      break;
    }
  }
  free(arr_1);
  free(arr_2);
  free(arr_3);
  return success;
}

static char* test_bogo_1() {
  int result = sort_test_int(bogo_sort, 5);
  mu_assert("Bogo sort ints not successful", result == 1);
  return 0;
}
static char* test_bogo_2() {
  int result = sort_test_struct(bogo_sort, 5);
  mu_assert("Bogo sort structs not successful", result == 1);
  return 0;
}

static char* test_bubble_1() {
  int result = sort_test_int(bubble_sort, 1000);
  mu_assert("Bubble sort ints not successful", result == 1);
  return 0;
}
static char* test_bubble_2() {
  int result = sort_test_struct(bubble_sort, 1000);
  mu_assert("Bubble sort structs not successful", result == 1);
  return 0;
}

static char* test_insertion_1() {
  int result = sort_test_int(insertion_sort, 1000);
  mu_assert("Insertion sort ints not successful", result == 1);
  return 0;
}
static char* test_insertion_2() {
  int result = sort_test_struct(insertion_sort, 1000);
  mu_assert("Insertion sort structs not successful", result == 1);
  return 0;
}

static char* test_merge_1() {
  int result = sort_test_int(merge_sort, 1000);
  mu_assert("Merge sort ints not successful", result == 1);
  return 0;
}
static char* test_merge_2() {
  int result = sort_test_struct(merge_sort, 1000);
  mu_assert("Merge sort structs not successful", result == 1);
  return 0;
}

static char* test_quick_1() {
  int result = sort_test_int(quick_sort, 1000);
  mu_assert("Quick sort ints not successful", result == 1);
  return 0;
}
static char* test_quick_2() {
  int result = sort_test_struct(quick_sort, 1000);
  mu_assert("Quick sort structs not successful", result == 1);
  return 0;
}

void all_sort_tests() {
  mu_run_test(test_bogo_1);
  mu_run_test(test_bogo_2);
  mu_run_test(test_bubble_1);
  mu_run_test(test_bubble_2);
  mu_run_test(test_insertion_1);
  mu_run_test(test_insertion_2);
  mu_run_test(test_merge_1);
  mu_run_test(test_merge_2);
  mu_run_test(test_quick_1);
  mu_run_test(test_quick_2);
}

int main(int argc, char* argv[]) {
  argc = argc;
  argv = argv;
  srand(time(NULL));

  tests_run = tests_passed = 0;
  // Unit tests
  common_tests();
  quick_tests();
  // Sort tests
  all_sort_tests();
  printf("Tests passed: %d / %d\n", tests_passed, tests_run);
  
  return 0;
}
