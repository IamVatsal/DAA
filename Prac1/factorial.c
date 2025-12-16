#include <stdio.h>

int fact_i(int n){
    int count = 0, result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
        count++;
    }
    printf("\n------------------------------------------\n");
    printf("Loop Method\n");
    printf("Factorial of Number %d is: %d\n", n, result);
    printf("Count of Step of Algorithm is : %d\n", count);
    printf("------------------------------------------\n");
    return result;
}

int fact_r(int n, int *count){
    if (n == 0 || n == 1){
        *count = *count + 1;
        return 1;
    }else{
        *count = *count + 1;
        return n * fact_r(n - 1, count);
    }
}

int get_sum(int n){
    fact_i(n);
    int count = 0;
    int result = fact_r(n, &count);
    printf("\n------------------------------------------\n");
    printf("Recursion Method\n");
    printf("Factorial of Number %d is: %d\n", n, result);
    printf("Count of Step of Algorithm is : %d\n", count);
    printf("------------------------------------------\n");
}

int main(){
    int n;
    printf("Give Me Number You want Factorial of: ");
    scanf("%d",&n);
    get_sum(n);
    return 0;
}