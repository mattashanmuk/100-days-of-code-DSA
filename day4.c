#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void reverse_array(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left++] = arr[right];
        arr[right--] = temp;
    }
}

int remove_element(int nums[], int n, int val) {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != val) nums[k++] = nums[i];
    }
    return k;
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    printf("Original array: ");
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
    reverse_array(arr, n);
    printf("Reversed array: ");
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");

    int nums[] = {3, 2, 2, 3};
    int length = remove_element(nums, 4, 3);
    printf("New length: %d\nModified array: ", length);
    for (int i = 0; i < length; ++i) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}