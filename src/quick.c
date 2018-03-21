#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "samsort.h"

extern int int_to_int(const void*);


// begin, end, and pivot are indices, not byte offsets
// End is inclusive
// TODO
size_t partition(void* ptr, size_t size, size_t begin, size_t end,
               int (*comp)(const void*, const void*)) {
  char* arr = (char*)ptr;
  size_t i, j;
  i = begin;
  for (j = begin; j < end; j++) {
    if (comp(arr + j * size, arr + end * size) == -1) {
      swap(arr + j * size, arr + i * size, size);
      i++;
    }
  }
  swap(arr + i * size, arr + end * size, size);
  return i;
}

void _quick_sort(void* ptr, size_t size, size_t begin, size_t end,
               int (*comp)(const void*, const void*)) {
  if (begin < end) {
    size_t pivot = partition(ptr, size, begin, end, comp);
    if (pivot > begin + 1) {
      _quick_sort(ptr, size, begin, pivot - 1, comp);
    }
    _quick_sort(ptr, size, pivot + 1, end, comp);
  }
}

// TODO
void quick_sort(void* ptr, size_t count, size_t size,
                int (*comp)(const void*, const void*)) {
  _quick_sort(ptr, size, 0, count - 1, comp);
}
