// 数据流中的中位数

#include <iostream>
#include <queue>
using namespace std;

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (dataleft.empty())
        {
            dataleft.push(num);
        }
        else if (dataright.empty())
        {
            if (num > dataleft.top())
            {
                dataright.push(num);
            }
            else
            {
                int temp = dataleft.top();
                dataleft.pop();
                dataleft.push(num);
                dataright.push(temp);
                // dataleft.erase(dataleft.begin());
                // dataleft.insert(num);
                // dataright.insert(temp);
            }
        }
        else if (dataleft.size() == dataright.size())
        {
            if (num <= dataright.top())
            {
                // dataleft.insert(num);
                dataleft.push(num);
            }
            else
            {
                int temp = dataright.top();
                dataleft.push(temp);
                dataright.pop();
                dataright.push(num);
                // dataleft.insert(temp);
                // dataright.erase(dataright.begin());
                // dataright.insert(num);
            }
        }
        else if (dataleft.size() - dataright.size() == 1)
        {
            if (num >= dataleft.top())
            {
                dataright.push(num);
            }
            else
            {
                int temp = dataleft.top();
                dataright.push(temp);
                dataleft.pop();
                dataleft.push(num);
                // dataleft.erase(dataleft.begin());
                // dataleft.insert(num);
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }

    double findMedian()
    {
        if (dataleft.size() == dataright.size())
        {
            return (dataleft.top() + dataright.top()) / 2.0;
        }
        else
        {
            return dataleft.top();
        }
    }
    priority_queue<int> dataleft;
    priority_queue<int, vector<int>, greater<int>> dataright;
};
int main()
{
    MedianFinder s;
    s.addNum(6);
    cout << s.findMedian() << endl;
    s.addNum(10);
    cout << s.findMedian() << endl;
    s.addNum(2);
    cout << s.findMedian() << endl;
    s.addNum(6);
    cout << s.findMedian() << endl;
    s.addNum(5);
    cout << s.findMedian() << endl;
    s.addNum(0);
    cout << s.findMedian() << endl;
    s.addNum(6);
    cout << s.findMedian() << endl;
    s.addNum(3);
    cout << s.findMedian() << endl;
    s.addNum(1);
    cout << s.findMedian() << endl;
    s.addNum(0);
    cout << s.findMedian() << endl;
    s.addNum(0);
    cout << s.findMedian() << endl;
}