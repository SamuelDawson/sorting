#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include "samsort.h"

#define ARR_SIZE_DEFAULT 10000
#define MAX_VAL 10000

extern int compare_int(const void*, const void*);

int main(int argc, char *argv[]) {
  int arr_size;
  int print_flag;
  int i;
  int* arr_1, * arr_2, * arr_3;
  int success = 1;
  if (argc > 1) {
    arr_size = atoi(argv[1]);
  } else {
    arr_size = ARR_SIZE_DEFAULT;
  }
  if (argc > 2) {
    print_flag = (strcmp(argv[2], "print") == 0); 
  } else {
    print_flag = 0;
  }

  srand(time(NULL));
  //Allocate and fill arrays
  arr_1 = malloc(sizeof(*arr_1) * arr_size);
  arr_2 = malloc(sizeof(*arr_2) * arr_size);
  arr_3 = malloc(sizeof(*arr_3) * arr_size);
  for (i = 0; i < arr_size; i++) {
    arr_1[i] = rand() % MAX_VAL;
    if (print_flag) {
      printf("%d ", arr_1[i]);
    }
  }
  if (print_flag) {
    puts("");
  }
  //Qsort will work on arr_1, our sort will work on arr_2
  memcpy(arr_2, arr_1, sizeof(*arr_1) * arr_size);
  qsort(arr_2, arr_size, sizeof(*arr_1), compare_int);
  printf("qsort done\n");
  fflush(stdout);
  //memcpy(arr_3, arr_1, sizeof(*arr_1) * arr_size);
  //insertion_sort(arr_3, arr_size, sizeof(*arr_1), compare_int);
  //printf("Insertion sort done\n");
  //fflush(stdout);
  //memcpy(arr_3, arr_1, sizeof(*arr_1) * arr_size);
  //bubble_sort(arr_3, arr_size, sizeof(*arr_1), compare_int);
  //printf("Bubble sort done\n");
  //fflush(stdout);
  //memcpy(arr_3, arr_1, sizeof(*arr_1) * arr_size);
  //bogo_sort(arr_3, arr_size, sizeof(*arr_1), compare_int);
  //printf("Bogo sort done\n");
  memcpy(arr_3, arr_1, sizeof(*arr_1) * arr_size);
  merge_sort(arr_3, arr_size, sizeof(*arr_1), compare_int);
  printf("Merge sort done\n");
  fflush(stdout);
  
  //Compare results
  for (i = 0; i < arr_size; i++) {
    if(print_flag) {
      printf("%d ", arr_3[i]);
    }
    if (arr_2[i] != arr_3[i]) {
      success = 0;
    }
  }
  if (print_flag) {
    puts("");
  }
  printf("Success: %d\n", success);
}
