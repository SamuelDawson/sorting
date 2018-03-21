#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "samsort.h"

void bogo_sort(void *ptr, size_t count, size_t size,
               int (*comp) (const void *, const void *)) {
  int in_order;
  char *arr = ptr;
  srand(time(NULL));
  if (count <= 1) {
    return;
  }
  do {
    // Shuffle
    size_t i;
    for (i = 0; i < count * size; i += size) {
      // Choose a "random" index to swap this one with
      // Note that count << RAND_MAX for this to be very random
      size_t j = i + size * (rand() / (RAND_MAX / (count - i / size) + 1));
      swap(arr + j, arr + i, size);
    }
    // Check if sorted
    in_order = 1;
    for (i = size; i < count * size; i += size) {
      if (comp((void *)(arr + i - size), (void *)(arr + i)) != -1) {
        in_order = 0;
        break;
      }
    }
  } while (!in_order);
}
