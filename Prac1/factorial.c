#include <stdio.h>

int count_ite = 0;
int count_rec = 0;

int fact_i(int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        count_ite++;
        result *= i;
    }
    return result;
}

int fact_r(int n){
    if (n == 0 || n == 1){
        count_rec++;
        return 1;
    }else{
        count_rec++;
        return n * fact_r(n - 1);
    }
}

int main(){
    int n;
    printf("Enter Number to find Factorial: ");
    scanf("%d", &n);
    int result_ite = fact_i(n);
    printf("\n------------------------------------------");
    printf("\nLoop Method");
    printf("\nFactorial of Number %d is: %d", n, result_ite);
    printf("\nCount of Step of Algorithm is : %d", count_ite);
    printf("\n------------------------------------------");
    int result_rec = fact_r(n);
    printf("\n------------------------------------------");
    printf("\nRecursive Method");
    printf("\nFactorial of Number %d is: %d", n, result_rec);
    printf("\nCount of Step of Algorithm is : %d", count_rec);
    printf("\n------------------------------------------");
    fact_i(n);
    
}