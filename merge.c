#include "samsort.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern int int_to_int(const void*);

//begin, middle, and end are byte offsets in the array, not indices
//End is not inclusive
static void merge(void* src, void* dest, size_t size, 
                  size_t begin, size_t middle, size_t end,
                  int (*comp)(const void*, const void*)) {
  size_t i, j, k;
  char* arr_src = src;
  char* arr_dest = dest;
  i = begin;
  j = middle;
  //Left source starts at begin, right source starts at middle, ends at begin
  for (k = i; k < end; k+=size) {
    if (i < middle) {
      if (j >= end || (comp(arr_src + i, arr_src + j) != 1)) {
        memcpy(arr_dest + k, arr_src + i, size);
        i+=size;
      } else {
        memcpy(arr_dest + k, arr_src + j, size);
        j+=size;
      }
    } else {
      memcpy(arr_dest + k, arr_src + j, size);
      j+=size;
    }
  }
}

void _merge_sort(void* src, void* dest, size_t size, size_t begin, size_t end,
                 int (*comp)(const void*, const void*)) {
  int middle;
  if (end - begin < size * 2) { //Run size == 1
    return;
  }
  //Need to split by indices so the rounding is right
  //(e.g. not in the middle of a multi-byte element)
  middle = (((begin + end) / size) / 2) * size;
  _merge_sort(dest, src, size, begin, middle, comp);
  _merge_sort(dest, src, size, middle, end, comp);
  merge(src, dest, size, begin, middle, end, comp);
}

void merge_sort(void *ptr, size_t count, size_t size,
                    int (*comp)(const void*, const void*)) {
  void* temp_arr = malloc(count*size);
  memcpy(temp_arr, ptr, count*size);
  _merge_sort(temp_arr, ptr, size, 0, count*size, comp); 
  free(temp_arr);
}


