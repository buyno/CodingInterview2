// 数据流中的中位数

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional> //greater<int>()
#include <assert.h>
using namespace std;

// 无序的数组，插入O(1)，查找中位数O(n)
// 有序的数组，插入O(n)，查找O(1)
// 排序的链表+两个指针，插入O(n)，查找O(1)
// 二叉搜索树
// AVL树，平衡的二叉搜索树
// 最大堆和最小堆，插入O(logn)，查找O(1)


double getMedium(int *data,int length){
    if(data == nullptr || length == 0){
        return -1;
    }
    vector<int> data1;//大顶堆
    vector<int> data2;//小顶堆
    double middle = 0;

    for(int i = 0;i < length;i++){
        //最开始，都为空，就往左边加
        if(data1.empty() && data2.empty()){
            data1.push_back(data[0]);
            make_heap(data1.begin(),data1.end());

        //小于等于p1的都加到左边大顶堆上，大于p1的加到小顶堆上
        }else if(data[i] <= data1.front()){
            data1.push_back(data[i]);
            push_heap(data1.begin(),data1.end());
            //如果超过2个，就往右移一个数
            if(data1.size() -  data2.size() > 1){
                pop_heap(data1.begin(),data1.end());
                if(data2.empty()){
                    data2.push_back(data1.back());
                    make_heap(data2.begin(),data2.end(),greater<int>());
                    data1.pop_back();
                    
                }else{
                    data2.push_back(data1.back());
                    push_heap(data2.begin(),data2.end(),greater<int>());
                    data1.pop_back();
                }    
            }
        }else {
            //大于p1，加到右边
            assert(data[i] > data1.front());
            if(data2.empty()){
                data2.push_back(data[i]);
                make_heap(data2.begin(),data2.end(),greater<int>());
            }else{
                data2.push_back(data[i]);
                push_heap(data2.begin(),data2.end(),greater<int>());
                if(data2.size() - data1.size() > 1){
                    data1.push_back(data2.front());
                    push_heap(data1.begin(),data1.end());
                    pop_heap(data2.begin(),data2.end(),greater<int>());
                    data2.pop_back();

                }
            }
        }
    }
    if((data1.size()+data2.size()) %2 == 0){
        middle = (data1.front()+data2.front())/2.0;

    }else{
        if(data1.size() > data2.size()){
            middle = data1.front();
        }else{
            middle = data2.front();
        }
    }
    return middle;
}
void test1(){
    int *data = nullptr;// 1,2,3,4,5,6,7,8,
    int length = 1;

    double res = getMedium(data,length);
    assert(res == -1);

    length = 0;
    data = new int[2]{1,2};
    length = 0;
    res = getMedium(data,length);
    assert(res == -1);
    delete []data;
}
void test2(){
    int data[] = {4,5,1,2,6,7,3,8};// 1,2,3,4,5,6,7,8,
    int length = sizeof(data)/sizeof(data[0]);

    double res = getMedium(data,length);
    assert(res == 4.5);
}
void test3(){
    int data[] = {4,1,2,3,5,1,2,6,7,8};// 1,2,3,4,5,6,7,8,
    int length = sizeof(data)/sizeof(data[0]);

    double res = getMedium(data,length);
    assert(res == 3.5);
}
void test4(){
    int data[] = {1};
    int length = sizeof(data)/sizeof(data[0]);

    double res = getMedium(data,length);
    assert(res == 1);
}
void test5(){
    int data[] = {1,10};
    int length = sizeof(data)/sizeof(data[0]);

    double res = getMedium(data,length);
    assert(res == 5.5);
}
void test6(){
    int data[] = {1,2,3,4,5,6,7};
    int length = sizeof(data)/sizeof(data[0]);

    double res = getMedium(data,length);
    assert(res == 4);
}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}