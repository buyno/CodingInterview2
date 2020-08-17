// 队列的最大值，要求时间复杂度为O(1)
// 实现一个队列，包含max函数，要求max(),push_back(),pop_front()时间复杂度为O(1)
// 队列：一边进，另一边出（栈的话可以用辅助数组记录每一位对应的最大值）

// 1)构造最大堆
// 2)类似滑动窗口的算法，窗口大小为整个队列长度。记录一个双端队列，队头是最大值的index，队尾是最小值
//
#include <assert.h>
#include <queue>
#include <stdio.h>

// template <class T>
// class Queue
// {
// public:
//     void push_back(T value)
//     {
//         data.push(value);
//         if (value > maxseq.front())
//         {
//             while (!maxseq.empty())
//             {
//                 maxseq.pop_front();
//             }
//             maxseq.push_back(value);
//         }
//         else
//         {
//             while (maxseq.back() < value)
//             {
//                 maxseq.pop_back();
//             }
//             maxseq.push_back(value);
//         }
//     }
//     void pop_front()
//     {
//         if (!empty())
//         {
//             if (data.front() == maxseq.front())
//             {
//                 maxseq.pop_front();
//             }
//             data.pop();
//         }
//     }
//     int empty()
//     {
//         return data.empty();
//     }
//     T front()
//     {
//         return data.front();
//     }
//     T max()
//     {
//         return maxseq.front();
//     }
//     std::queue<T> data;
//     std::deque<T> maxseq;
// };
// int main()
// {
//     Queue<int> myqueue;
//     myqueue.push_back(2);
//     assert(myqueue.max() == 2);
//     myqueue.push_back(3);
//     assert(myqueue.max() == 3);
//     myqueue.push_back(4);
//     assert(myqueue.max() == 4);
//     myqueue.push_back(2);
//     assert(myqueue.max() == 4);
//     myqueue.pop_front();
//     assert(myqueue.max() == 4);
//     myqueue.pop_front();
//     assert(myqueue.max() == 4);
//     myqueue.pop_front();
//     assert(myqueue.max() == 2);
//     myqueue.push_back(6);
//     assert(myqueue.max() == 6);
//     myqueue.push_back(2);
//     assert(myqueue.max() == 6);
//     myqueue.push_back(5);
//     assert(myqueue.max() == 6);
//     myqueue.pop_front();
//     assert(myqueue.max() == 6);
//     myqueue.pop_front();
//     assert(myqueue.max() == 5);
//     myqueue.pop_front();
//     assert(myqueue.max() == 5);
//     myqueue.push_back(5);
//     assert(myqueue.max() == 5);
// }
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