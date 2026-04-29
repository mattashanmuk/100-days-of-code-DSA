#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int linear_search(int arr[], int n, int target, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; ++i) {
        (*comparisons)++;
        if (arr[i] == target) return i;
    }
    return -1;
}

int missing_number(int nums[], int n) {
    int expected = n * (n + 1) / 2;
    int actual = 0;
    for (int i = 0; i < n; ++i) actual += nums[i];
    return expected - actual;
}

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int comparisons;
    int index = linear_search(arr, 5, 30, &comparisons);
    printf("Index: %d, Comparisons: %d\n", index, comparisons);

    int nums[] = {3, 0, 1};
    printf("Missing number: %d\n", missing_number(nums, 3));
    return 0;
}