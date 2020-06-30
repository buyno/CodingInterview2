// 包含min函数的栈,通过min()函数随时得到当前栈的最小值

// 两个栈，附加栈用于记录当前的最小值

// 在每次pop和top之前都判断一次栈是否为空
#include <stack>
#include <stdio.h>
#include <assert.h>

using namespace std;

template <typename T>
class MyStack{
public:
    T min();
    void pop();
    int top();
    void push(T number);
    int empty(){
        return data.empty();
    }
    stack<T> data;
    stack<T> mins;
    T minnumber;
};
template <typename T>
int MyStack<T>::top(){
    return data.top();
}
template <typename T>
void MyStack<T>::pop(){
    if(data.empty()){
        return;
    }
    data.pop();
    mins.pop();
    if(!data.empty()){
        minnumber = mins.top();
    }
}
template <typename T>
void MyStack<T>::push(T number){
    data.push(number);
    if(mins.empty()){
        mins.push(number);
    }else{
        if(mins.top() > number){
            mins.push(number);
        }else{
            mins.push(mins.top());
        }
    }

    minnumber = mins.top();
}
template <typename T>
T MyStack<T>::min(){
    return minnumber;
}

int main(){
    MyStack<int> test;
    assert(test.empty() == 1);
    test.push(10);
    assert(test.min() == 10);

    test.push(2);
    assert(test.min() == 2);
    test.push(3);
    assert(test.min() == 2);
    test.pop();
    assert(test.min() == 2);
    test.pop();
    assert(test.min() == 10);
    test.pop();
    assert(test.empty() == 1);
}