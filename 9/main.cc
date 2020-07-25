//用两个栈实现一个队列

// 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

#include <stack>
#include <assert.h>

using namespace std;

class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        s1.push(value);
    }

    int deleteHead()
    {
        if (s1.empty() && s2.empty())
        {
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int value = s2.top();
        s2.pop();
        return value;
    }
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    {
        CQueue *obj = new CQueue();
        int value = 3;
        obj->appendTail(value);
        int param_2 = obj->deleteHead();
        assert(param_2 == 3);
        param_2 = obj->deleteHead();
        assert(param_2 == -1);
        delete obj;
    }
    {
        CQueue *obj = new CQueue();
        assert(obj->deleteHead() == -1);
        obj->appendTail(5);
        obj->appendTail(2);
        assert(obj->deleteHead() == 5);
        assert(obj->deleteHead() == 2);
        assert(obj->deleteHead() == -1);
        delete obj;
    }
}