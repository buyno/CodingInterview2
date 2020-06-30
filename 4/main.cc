// 二维数组的查找

#include <assert.h>
int find(int *numbers,int rows,int cols,int num){
    if(!numbers)return 0;

    int row = 0;
    int col = cols-1;
    while(row < rows && col >= 0){
        if(numbers[row*cols+col] == num){
            return 1;//找到
        }
        if(numbers[row*cols+col] > num){
            col--;
            continue;
        }
        if(numbers[row*cols+col] < num){
            row ++;
            continue;
        }
    }
    return 0;//没找到
}
void test1(){
    int numbers[] = {1,2,3,4,5,6};
    int number = 5;
    int rows = 2;
    int cols = 3;
    int res = find(numbers,rows,cols,number);
    assert(res == 1);
}
void test2(){
    int numbers[] = {1,2,3,4,7,6};
    int number = 5;
    int rows = 2;
    int cols = 3;
    int res = find(numbers,rows,cols,number);
    assert(res == 0);
}
void test3(){
    int *numbers = nullptr;
    int number = 5;
    int rows = 2;
    int cols = 3;
    int res = find(numbers,rows,cols,number);
    assert(res == 0);
}
int main(){
    test1();
    test2();
    test3();
}