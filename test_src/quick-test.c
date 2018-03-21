#include "quick.c"
#include <limits.h>
#include "minunit.h"
#include "testbench.h"

#define ARR_SIZE 100
#define MAX_VAL INT_MAX

extern int compare_int(const void *, const void *);

static char *test_partition_1() {
  int *arr;
  int i;
  int pivot_idx = 0;
  int success = 1;
  //Create and populate array
  arr = malloc(sizeof(*arr) * ARR_SIZE);
  for (i = 0; i < ARR_SIZE; i++) {
    arr[i] = (rand() % MAX_VAL * 2) - MAX_VAL;
  }

  //Partition
  pivot_idx = partition(arr, sizeof(int), 0, ARR_SIZE - 1, compare_int);

  //Check that smaller values are to the left of pivot, larger to the right
  for (int i = 0; i < pivot_idx; i++) {
    if (arr[i] > arr[pivot_idx]) {
      success = 0;
      break;
    }
  }
  for (int i = pivot_idx + 1; i < ARR_SIZE; i++) {
    if (arr[i] < arr[pivot_idx]) {
      success = 0;
      break;
    }
  }
  mu_assert("Values not on correct side of pivot", success == 1);
  return 0;
}

void quick_tests() {
  mu_run_test(test_partition_1);
}
