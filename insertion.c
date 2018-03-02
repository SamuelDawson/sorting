#include "samsort.h"
#include <stdlib.h>
#include <string.h>

extern int int_to_int(const void*);

void insertion_sort(void *ptr, size_t count, size_t size,
                    int (*comp)(const void*, const void*)) {
  int i;
  char* arr = (char*) ptr;
  if (count <=1) {
    return;
  }
  for (i = size; i < count*size; i+=size) {
    int j;
    for (j = i; j > 0; j-=size) {
      if (comp((void*) (arr + j - size), (void*) (arr + j)) == 1) { 
        swap(arr + j - size, arr + j, size);
      } else {
        break;
      }
    }
	//visualize_arr(ptr, count, size, int_to_int);
  }
}
