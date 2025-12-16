#include <stdio.h>

int sum_i(int n){
    int count = 0, sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
        count++;
    }
    printf("\n------------------------------------------\n");
    printf("Loop Method\n");
    printf("Sum of 1 to %d Number is: %d\n", n, sum);
    printf("Count of Step of Algorithm is : %d\n", count);
    printf("------------------------------------------\n");
    return sum;
}

int sum_e(int n){
    int count = 0, sum = 0;
    sum = ( n / 2 ) * ( n + 1 );
    count++;
    printf("\n------------------------------------------\n");
    printf("Equation Method\n");
    printf("Sum of 1 to %d Number is: %d\n", n, sum);
    printf("Count of Step of Algorithm is : %d\n", count);
    printf("------------------------------------------\n");
    return sum;
}

int sum_r(int n, int *count){
    if (n != 0){
        *count = *count + 1;
        return n + sum_r(n - 1, count);
    }else{
        return n;
    }
}

int get_sum(int n){
    sum_i(n);
    sum_e(n);
    int count = 0;
    int sum = sum_r(n, &count);
    printf("\n------------------------------------------\n");
    printf("Recursion Method\n");
    printf("Sum of 1 to %d Number is: %d\n", n, sum);
    printf("Count of Step of Algorithm is : %d\n", count);
    printf("------------------------------------------\n");
}

int main(){
    int n;
    printf("Give Me Number You want Sum of: ");
    scanf("%d",&n);
    get_sum(n);
    return 0;
}