#include <stddef.h>

#define DISPLAY_HEIGHT 40
#define DISPLAY_WIDTH 80

void swap(void* val1, void* val2, size_t size);

void visualize_arr(void *ptr, size_t count, size_t size,
                   int (*to_int)(const void*));
//Comp should return -1, 0, or 1 for first < second, ==, first > second

void insertion_sort(void *ptr, size_t count, size_t size,
                    int (*comp)(const void*, const void*));

void bubble_sort(void *ptr, size_t count, size_t size,
                    int (*comp)(const void*, const void*));
