#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int delete_element(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) return -1;
    for (int i = position; i < *size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return 0;
}

int max_profit(int prices[], int n) {
    if (n <= 0) return 0;
    int min_price = INT_MAX;
    int profit = 0;
    for (int i = 0; i < n; ++i) {
        if (prices[i] < min_price) min_price = prices[i];
        else if (prices[i] - min_price > profit) profit = prices[i] - min_price;
    }
    return profit;
}

int main(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    printf("Original array: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    delete_element(arr, &size, 2);
    printf("After deleting at position 2: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    int prices[] = {7, 1, 5, 3, 6, 4};
    printf("Maximum profit: %d\n", max_profit(prices, 6));
    return 0;
}