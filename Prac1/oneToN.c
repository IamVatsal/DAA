#include <stdio.h>

int count_ite = 0;
int count_rec = 0;
int count_eq = 0;

int sum_i_142(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        count_ite++;
        sum += i;
    }
    return sum;
}

int sum_e_142(int n) {
    int sum = 1;
    sum = (n * (n + 1)) / 2;
    count_eq++;
    return sum;
}

int sum_r_142(int n) {
    if (n == 0) {
        count_rec++;
        return 0;
    }
    else
    if (n == 1) {
        count_rec++;
        return 1;
    }
    else {
        count_rec++;
        return n + sum_r_142(n - 1);
    }
}

int main() {
    int n;
    printf("Give Me Number To Sum of Numbers from 1 to N You want Sum of: ");
    scanf("%d", &n);
    int result_ite = sum_i_142(n);
    printf("\n------------------------------------------");
    printf("\nEnroll Number: 142");
    printf("\nLoop Method");
    printf("\nSum of 1 to %d Number is: %d", n, result_ite);
    printf("\nCount of Step of Algorithm is : %d", count_ite);
    printf("\n------------------------------------------");
    int result_eq = sum_e_142(n);
    printf("\n------------------------------------------");
    printf("\nEnroll Number: 142");
    printf("\nEquation Method");
    printf("\nSum of 1 to %d Number is: %d", n, result_eq);
    printf("\nCount of Step of Algorithm is : %d", count_eq);
    printf("\n------------------------------------------");
    int result_rec = sum_r_142(n);
    printf("\n------------------------------------------");
    printf("\nEnroll Number: 142");
    printf("\nRecursive Method");
    printf("\nSum of 1 to %d Number is: %d", n, result_rec);
    printf("\nCount of Step of Algorithm is : %d", count_rec);
    printf("\n------------------------------------------");
    return 0;
}