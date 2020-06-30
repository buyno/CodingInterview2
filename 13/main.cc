// 机器人的运动范围
// 机器人从(0,0)开始移动，但是只能移动到坐标为(i,j)，并且i,j各个位的和小于k。
// 比如k=5时，可以移动到(1,4)，不能移动到(1,5)
// 返回可移动的格数，和移动范围的矩阵
#include <assert.h>
#include <stdio.h>
int getSum(int x,int y){
    int sum = 0;
    while(x){
        sum = sum + x%10;
        x = x/10;
    }
    while(y){
        sum = sum + y%10;
        y = y/10;
    }
    return sum;
}
int search(int k,int x,int y,int *result,int *visited,int m,int n){
    if(x<0 || y < 0 || x >=m || y >= n || (visited[x*n+y] == 1)){
        return 0;
    }
    visited[x*n+y] = 1;
    if(getSum(x,y) <= k){
        result[x*n+y] = 1;
        return 1 + search(k,x-1,y,result,visited,m,n) 
                + search(k,x,y-1,result,visited,m,n) 
                + search(k,x+1,y,result,visited,m,n)
                + search(k,x,y+1,result,visited,m,n);
    }else{
        return 0;
    }
}
void test1(){
    int k = 5;
    int m = 10,n = 10;//m行n列
    int visited[m*n];
    int result[m*n];
    for(int i = 0;i<m*n;i++){
        visited[i] = 0;
        result[i] = 0;
    }
    int i= 0,j=0;
    int count = search(k,i,j,result,visited,m,n);
    assert(count == 21);
}
void test2(){
    int k = -11;
    int m = 10,n = 10;//m行n列
    int visited[m*n];
    int result[m*n];
    for(int i = 0;i<m*n;i++){
        visited[i] = 0;
        result[i] = 0;
    }
    int i= 0,j=0;
    int count = search(k,i,j,result,visited,m,n);
    assert(count == 0); 
}
void test3(){
    int k = 5;
    int m = 1,n = 10;//m行n列
    int visited[m*n];
    int result[m*n];
    for(int i = 0;i<m*n;i++){
        visited[i] = 0;
        result[i] = 0;
    }
    int i= 0,j=0;
    int count = search(k,i,j,result,visited,m,n);
    assert(count == 6); 
}
void test4(){
    int k = 5;
    int m = 10,n = 1;//m行n列
    int visited[m*n];
    int result[m*n];
    for(int i = 0;i<m*n;i++){
        visited[i] = 0;
        result[i] = 0;
    }
    int i= 0,j=0;
    int count = search(k,i,j,result,visited,m,n);
    assert(count == 6); 
}
int main(){
    //正常功能
    test1();
    //k<0
    test2();
    // m或n == 1
    test3();
    test4();
}