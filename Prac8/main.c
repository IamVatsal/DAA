#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int amount) {
    int dp[100];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub = dp[i - coins[j]];
                if (sub != INT_MAX && sub + 1 < dp[i]) {
                    dp[i] = sub + 1;
                }
            }
        }
    }
    return dp[amount];
}

int main() {
    int coins[100], n, amount;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter coin values: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &coins[i]);
    }
    printf("Enter amount: ");
    scanf("%d", &amount);

    int result = minCoins(coins, n, amount);
    printf("Minimum coins required = %d\n", result);
    return 0;
}
