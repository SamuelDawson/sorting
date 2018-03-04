#include "samsort.h"
#include <stdio.h>
#include <unistd.h>

//A standard comp function
int compare_int(const void* v1, const void* v2) {
  int a = *(int*)v1;
  int b = *(int*)v2;
  if (a < b) return -1;
  else if (a == b) return 0;
  else return 1;
}

int int_to_int(const void* v) {
  return *(int*) v;
}

void visualize_arr(void *ptr, size_t count, size_t size,
                   int (*to_int)(const void*)) { 
  int max, display_count;
  int height_step, width_step;
  size_t i;
  char* arr = (char*) ptr;
  if (count == 0) {
    return;
  } else if (count <= DISPLAY_HEIGHT) {
    display_count = count;
  } else {
    display_count = DISPLAY_HEIGHT;
  }
  //Clear screen
  for (i  = 0; i < DISPLAY_HEIGHT*5; i++) {
    puts("");
  }
  fflush(stdout);

  max = to_int(arr);
  for (i = size; i < count*size; i+=size) {
    int val = to_int(arr+i);
    if (val > max) {
      max = val;
    }
  }
  height_step = (max + (DISPLAY_WIDTH - 1)) / DISPLAY_WIDTH;
  width_step = count / display_count; 
  for (i = 0; i < count*size; i+=size*width_step) {
    int val = to_int(arr+i);
    int num_dots = (val + (height_step - 1)) / height_step;
    int j;
    for (j = 0; j < num_dots; j++) {
      printf(".");
    }
    printf("\n");
  }
  fflush(stdout);
  sleep(1);
}

void swap(void* val1, void* val2, size_t size) {
  char* a = val1;
  char* b = val2;
  char tmp;
  size_t i;
  for (i = 0; i < size; i++) {
    tmp = *a;
    *a++ = *b;
    *b++ = tmp;
  }
}
