//找出数组中任意一个重复的数字

#include <iostream>
#include <assert.h>
using namespace std;
void sort(int *numbers,int length){
    for(int i=0;i<length - 1;i++){
        int low = i;
        for(int j = i+1;j<length;j++){
            if(*(numbers + low) > *(numbers + j)){
                low = j;
            }
        }
        if(low != i){
            int temp  = *(numbers + i);
            *(numbers + i) = *(numbers + low);
            *(numbers + low) = temp;
        }
    }
}
int find_repeat_number(int *numbers,int length,int *result){
    if(!numbers)return 0;
    sort(numbers,length);
    for(int i = 0;i<length - 1;i++){
        if(*(numbers+i) == *(numbers+i+1)){
            *result = *(numbers+i);
            return 1;
        }
    }
    return 0;
}
void test1(){
    int length = 10;
    int numbers[] = {33,23,22,32,23,1,2,6,3,3};
    int result = -1;
    int res = find_repeat_number(numbers,length,&result);
    assert(res == 1);
    assert((
        result == 23) || (result == 3));
}
void test2(){
     int length = 0;
    int numbers[] = {};

    int result = -1;
    int res = find_repeat_number(numbers,length,&result);
    assert(res == 0);
    assert(result == -1);
}
void test3(){
    int length = 10;
    int numbers[] = {1,2,3,4,5,6,7,8,9,10};

    int result = -1;
    int res = find_repeat_number(numbers,length,&result);
    assert(res == 0);
    assert(result == -1);
}
int main(){
    test1();
    test2();
    test3();
}