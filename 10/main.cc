// 斐波那契数列

#include <stdio.h>
long fib(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    return fib(n-1)+fib(n-2);
}
long fib2(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    long result = 0;
    long first = 0,second = 1;
    for(int i =2;i<=n;i++){
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}
int main(){
    int num[] = {0,1,2,3,4,5,6,7,8,9,10,100,200};
    for(int n : num){
        printf("%d::%ld\n",n,fib2(n));
    }
    // for(int n : num){
    //     printf("%d::%ld\n",n,fib(n));
    // }
}