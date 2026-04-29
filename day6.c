#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int remove_duplicates(int nums[], int n) {
    if (n == 0) return 0;
    int k = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[i - 1]) nums[k++] = nums[i];
    }
    return k;
}

void move_zeroes(int nums[], int n) {
    int insert = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) nums[insert++] = nums[i];
    }
    while (insert < n) nums[insert++] = 0;
}

int main(void) {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len = remove_duplicates(nums, 10);
    printf("After removing duplicates: ");
    for (int i = 0; i < len; ++i) printf("%d ", nums[i]);
    printf("\n");

    int zeros[] = {0, 1, 0, 3, 12};
    move_zeroes(zeros, 5);
    printf("After moving zeroes: ");
    for (int i = 0; i < 5; ++i) printf("%d ", zeros[i]);
    printf("\n");
    return 0;
}