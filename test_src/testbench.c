#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include "samsort.h"
#include "minunit.h"
#include "testbench.h"

#define ARR_SIZE_DEFAULT 10000
#define MAX_VAL 10000

extern int compare_int(const void*, const void*);
int tests_run;

//static int sort_test(void (*sort)(void *ptr, size_t count, size_t size,
//                     int (*comp)(const void*, const void*)),
//                     size_t arr_size) {
static int sort_test(void (*sort)(),
                     size_t arr_size) {
  int* arr_1, * arr_2, * arr_3;
  size_t i;
  int success = 1;
  arr_1 = malloc(sizeof(*arr_1) * arr_size);
  arr_2 = malloc(sizeof(*arr_2) * arr_size);
  arr_3 = malloc(sizeof(*arr_3) * arr_size);
  for (i = 0; i < arr_size; i++) {
    arr_1[i] = (rand() % MAX_VAL*2) - MAX_VAL;
  }
  memcpy(arr_2, arr_1, sizeof(*arr_1) * arr_size);
  qsort(arr_2, arr_size, sizeof(*arr_2), compare_int);
  memcpy(arr_3, arr_1, sizeof(*arr_1) * arr_size);
  sort(arr_3, arr_size, sizeof(*arr_3), compare_int);
  //Compare results
  for (i = 0; i < arr_size; i++) {
    if (arr_2[i] != arr_3[i]) {
      success = 0;
    }
  }
  free(arr_1);
  free(arr_2);
  free(arr_3);
  return success;
}

static char *test_bogo() {
  int result = sort_test(bogo_sort, 8);
  mu_assert("error, bogo sort not successful", result == 1);
  return 0;
}
static char *test_bubble() {
  int result = sort_test(bubble_sort, 10000);
  mu_assert("error, bubble sort not successful", result == 1);
  return 0;
}
static char *test_insertion() {
  int result = sort_test(insertion_sort, 10000);
  mu_assert("error, insertion sort not successful", result == 1);
  return 0;
}
static char *test_merge() {
  int result = sort_test(merge_sort, 10000);
  mu_assert("error, merge sort not successful", result == 1);
  return 0;
}

static char *all_sort_tests() {
  mu_run_test(test_bogo);
  mu_run_test(test_bubble);
  mu_run_test(test_insertion);
  mu_run_test(test_merge);
  return 0;
}

int main(int argc, char *argv[]) {
  argc = argc;
  argv = argv;
  char *result;
  srand(time(NULL));
  
  //Sort tests
  tests_run = 0;
  result = all_sort_tests();
  if (result != 0) {
	 printf("%s\n", result);
  }
  else {
	 printf("ALL SORT TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);
  
  //Unit tests
  tests_run = 0;
  result = common_tests();
  if (result != 0) {
	 printf("%s\n", result);
  }
  else {
	 printf("ALL COMMON TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}
