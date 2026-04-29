#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void insert_element(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size) {
        return;
    }
    for (int i = *size; i > position; --i) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void two_sum(int nums[], int n, int target, int result[2]) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return;
            }
        }
    }
    result[0] = result[1] = -1;
}

int main(void) {
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    printf("Original array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    insert_element(arr, &size, 10, 2);
    printf("After inserting 10 at position 2: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    int nums[] = {2, 7, 11, 15};
    int result[2];
    two_sum(nums, 4, 9, result);
    printf("Indices for target 9: [%d, %d]\n", result[0], result[1]);
    return 0;
}