// 包含min函数的栈,通过min()函数随时得到当前栈的最小值

// 两个栈，附加栈用于记录当前的最小值

#include <stack>
#include <assert.h>
#include <iostream>
using namespace std;

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        data.push(x);
        if (minvalue.empty())
        {
            minvalue.push(x);
        }
        else if (x <= minvalue.top())
        {
            minvalue.push(x);
        }
        else
        {
            minvalue.push(minvalue.top());
        }
    }

    void pop()
    {
        data.pop();
        minvalue.pop();
    }

    int top()
    {
        return data.top();
    }

    int min()
    {
        return minvalue.top();
    }
    stack<int> data;
    stack<int> minvalue;
};
int main()
{
    MinStack test;
    // assert(test.empty() == 1);
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
    // assert(test.empty() == 1);
}