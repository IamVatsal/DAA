#include <stdio.h>

int coinChange(int coins[], int num_coins, int amount) {
    int count = 0;
    for (int i = 0; i < num_coins; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return count;
}

int main() {
    int coins[] = {25, 10, 5, 1};
    int num_coins = sizeof(coins) / sizeof(coins[0]);
    printf("Available coins: ");
    for (int i = 0; i < num_coins; i++) {
        printf("%d ", coins[i]);
    }
    int amount;
    printf("\nEnter the amount: ");
    scanf("%d", &amount);

    int min_coins = coinChange(coins, num_coins, amount);

    printf("Minimum coins needed: %d\n", min_coins);
    return 0;
}