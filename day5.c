#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void arrange_logs(char *logs[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool is_digit_i = isdigit(logs[i][strcspn(logs[i], " ")+1]);
            bool is_digit_j = isdigit(logs[j][strcspn(logs[j], " ")+1]);
            if (!is_digit_i && !is_digit_j) {
                int cmp = strcmp(logs[i] + strcspn(logs[i], " ")+1, logs[j] + strcspn(logs[j], " ")+1);
                if (cmp > 0 || (cmp == 0 && strcmp(logs[i], logs[j]) > 0)) {
                    char *tmp = logs[i];
                    logs[i] = logs[j];
                    logs[j] = tmp;
                }
            } else if (!is_digit_j) {
                char *tmp = logs[i]; logs[i] = logs[j]; logs[j] = tmp;
            }
        }
    }
}

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
}

int main(void) {
    char *logs[] = {"let1 art can", "a1 9 2 3 1", "zo4 4 7", "ab1 off key dog", "a8 act zoo"};
    int n = 5;
    arrange_logs(logs, n);
    printf("Reordered logs:\n");
    for (int i = 0; i < n; ++i) printf("%s\n", logs[i]);

    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    printf("Merged array: ");
    for (int i = 0; i < 6; ++i) printf("%d ", nums1[i]);
    printf("\n");
    return 0;
}