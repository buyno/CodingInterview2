// 队列的最大值，要求时间复杂度为O(1)
// 实现一个队列，包含max函数，要求max(),push_back(),pop_front()时间复杂度为O(1)
// 队列：一边进，另一边出（栈的话可以用辅助数组记录每一位对应的最大值）
// 队列的最大值

// 1)构造最大堆
// 2)类似滑动窗口的算法，窗口大小为整个队列长度，只是不考虑出窗口过期的问题。
// 记录一个双端队列，队头是最大值的index，队尾是最小值
//
#include <assert.h>
#include <queue>
#include <deque>
#include <iostream>
using namespace std;

class MaxQueue
{
public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (temp.empty())
        {
            return -1;
        }
        return temp.front();
    }

    void push_back(int value)
    {
        data.push(value);
        while (!temp.empty() && value > temp.back())
        {
            temp.pop_back();
        }
        temp.push_back(value);
        // while(!temp.empty() && )
    }

    int pop_front()
    {
        if (data.empty())
        {
            return -1;
        }
        int res = data.front();
        data.pop();
        cout << res << ":" << temp.front() << endl;
        if (res == temp.front())
        {
            temp.pop_front();
        }
        return res;
    }
    queue<int> data;
    deque<int> temp;
};

int main()
{
    MaxQueue *obj = new MaxQueue();
    int param_1 = obj->max_value();
    obj->push_back(1);
    obj->push_back(2);
    cout << obj->max_value() << endl;
    obj->pop_front();
    cout << obj->max_value() << endl;
    int param_3 = obj->pop_front();
}