#include <stdio.h>

int count_ite = 0;
int count_rec = 0;

int fib_ite_142(int n) {
    if (n <= 1) {
        count_ite++;
        return n;
    }
    else {
        int t1 = 0, t2 = 1, nextTerm;
        for (int i = 1; i <  n; ++i) {
            count_ite++;
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        }
        return nextTerm;
    }
}

int fib_rec_142(int n) {
    if (n <= 1) {
        count_rec++;
        return n;
    }
    else {
        count_rec++;
        return fib_rec_142(n - 1) + fib_rec_142(n - 2);
    }
}


int main() {
    int n;
    printf("Enter Number to find Fibonacci Value: ");
    scanf("%d", &n);
    int result_ite = fib_ite_142(n);
    printf("\n------------------------------------------");
    printf("\nEnroll Number: 142");
    printf("\nLoop Method");
    printf("\nFibonacci of Number %d is: %d", n, result_ite);
    printf("\nCount of Step of Algorithm is : %d", count_ite);
    printf("\n------------------------------------------");
    int result_rec = fib_rec_142(n);
    printf("\n------------------------------------------");
    printf("\nEnroll Number: 142");
    printf("\nRecursive Method");
    printf("\nFibonacci of Number %d is: %d", n, result_rec);
    printf("\nCount of Step of Algorithm is : %d", count_rec);
    printf("\n------------------------------------------");
    return 0;
}