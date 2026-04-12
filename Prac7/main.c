#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int coinChange(int coins[], int num_coins, float amount, int coins_used[]) {
    sortDescending(coins, num_coins); // Sort coins in descending order
    int count = 0;
    for (int i = 0; i < num_coins; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
            coins_used[i]++;
        }
    }
    return count;
}

int main() {
    int n;
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    int coins[n];
    printf("Enter the coin values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    float amount;
    printf("Enter the amount: ");
    scanf("%f", &amount);

    int coins_used[n]; // Initialize coins used array to 0
    for (int i = 0; i < n; i++) {
        coins_used[i] = 0;
    }

    int min_coins = coinChange(coins, n, amount, coins_used);

    printf("-- Coin Change Problem ---\n");
    printf("Minimum coins needed: %d\n", min_coins);
    printf("Coin Used: ");
    for (int i = 0; i < n; i++) {
        printf("%d : %d", coins[i], coins_used[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    return 0;
}