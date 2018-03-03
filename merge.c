#include "samsort.h"
#include <stdlib.h>
#include <string.h>

extern int int_to_int(const void*);

static void merge(void* src, void* dest, size_t size,
                  size_t begin, size_t middle, size_t end) {
  size_t i, j, k;
  i = begin;
  j = middle;
  //Left source starts at begin, right source starts at middle, ends at begin
  for (k = i; k < end; k++) {
    if (i < middle) {
      if (j >= end || A[i] <= A[j]) {
        //***copy(dest[k], src[k], size
      }
      
    }
  }
}

void merge_sort(void *ptr, size_t count, size_t size,
                    int (*comp)(const void*, const void*)) {
  
}
