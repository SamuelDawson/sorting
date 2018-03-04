#include "samsort.h"
#include <stdlib.h>
#include <string.h>

extern int int_to_int(const void*);

void bubble_sort(void *ptr, size_t count, size_t size,
                    int (*comp)(const void*, const void*)) {
  int swapped;
  size_t i;
  char* arr = (char*) ptr;
  
  if (count <= 1) {
    return;
  }
  do {
    swapped = 0;
    for (i = size; i < count*size; i+=size) {
      if (comp((void*) (arr + i - size), (void*) (arr + i)) == 1) { 
        swap(arr + i - size, arr + i, size);
        swapped = 1;
      }
    }
	//visualize_arr(ptr, count, size, int_to_int);
  } while (swapped);
}
