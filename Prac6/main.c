#include <stdio.h>

int sort(float ratio[], float weight[], float profit[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // swap ratio
                float temp_ratio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp_ratio;
                // swap weight
                float temp_weight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp_weight;
                // swap profit
                float temp_profit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp_profit;
            }
        }
    }
}

float knapsack(float weight[], float profit[], int capacity, int n) {
    // get profit/weight ratio and sort items by ratio in descending order
    float ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)profit[i] / weight[i];
    }
    sort(ratio, weight, profit, n);
    float total_profit = 0;
    for (int i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            total_profit += profit[i];
            capacity -= weight[i];
        } else {
            total_profit += ratio[i] * capacity;
            break;
        }
    } 
    return total_profit;
}


int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    float weight[n];
    float profit[n];
    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit for item %d: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
    }
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    float max_profit = knapsack(weight, profit, capacity, n);
    printf("Maximum profit: %f\n", max_profit);

    return 0;
}