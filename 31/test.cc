// 逻辑比之前的解法更清晰，在leetcode还有一种代码行数更少的解法，资源消耗是一样的

#include <vector>
#include <stack>
#include <assert.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        if (pushed.size() == 0 || popped.size() == 0)
        {
            return true;
        }
        stack<int> mystack;
        int i = 0, j = 0;
        while (!mystack.empty() || i < pushed.size())
        {
            // 如果栈顶和popped相等，直接出栈一个值，同时popped减一个值
            if (!mystack.empty() && mystack.top() == popped[j])
            {
                mystack.pop();
                j++;
                continue;
            }
            // 如果不相等，那就在pushed中找到下一个相等的值，将这个值入栈再出栈，同时popped减一个值
            else
            {
                while (i < pushed.size() && pushed[i] != popped[j])
                {
                    mystack.push(pushed[i]);
                    i++;
                }
                if (i >= pushed.size())
                    return false;
                // mystack.push(pushed[i]);
                i++;
                // mystack.pop();
                j++;
            }
        }
        return true;
    }
};

void test1()
{
    vector<int> inquery = {1, 2, 3, 4, 5};
    vector<int> outquery = {4, 5, 3, 2, 1};
    Solution s;
    int res = s.validateStackSequences(inquery, outquery);
    assert(res == 1);
}
void test2()
{
    // vector<int> inquery = {1, 2, 3, 4, 5};
    // vector<int> outquery = {6, 5, 3, 2, 1};
    vector<int> inquery = {1, 2, 3, 4, 5};
    vector<int> outquery = {4, 3, 5, 1, 2};
    Solution s;
    int res = s.validateStackSequences(inquery, outquery);
    assert(res == 0);
}
void test3()
{
    vector<int> inquery = {1, 2, 3, 4, 5};
    vector<int> outquery = {4, 5, 3, 2};
    Solution s;
    int res = s.validateStackSequences(inquery, outquery);
    assert(res == 0);
}
void test4()
{
    vector<int> inquery = {1, 2, 3, 4, 5};
    vector<int> outquery = {4, 5, 3, 1, 2};
    Solution s;
    int res = s.validateStackSequences(inquery, outquery);
    assert(res == 0);
}
void test5()
{
    vector<int> inquery = {1};
    vector<int> outquery = {1};
    Solution s;
    int res = s.validateStackSequences(inquery, outquery);
    assert(res == 1);
}
void test6()
{
    vector<int> inquery = {1};
    vector<int> outquery = {2};
    Solution s;
    int res = s.validateStackSequences(inquery, outquery);
    assert(res == 0);
}
void test7()
{
    vector<int> inquery = {};
    vector<int> outquery = {};
    Solution s;
    int res = s.validateStackSequences(inquery, outquery);
    assert(res == 1);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}