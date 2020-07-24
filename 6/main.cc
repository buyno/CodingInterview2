// 从尾到头打印链表
// 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）
// 输入：head = [1,3,2]
// 输出：[2,3,1]

// 直接用栈保存中间值，效率反而更高
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        stack<int> ss;
        auto iter = head;
        while (iter)
        {
            ss.push(iter->val);
            iter = iter->next;
        }
        vector<int> res;
        while (!ss.empty())
        {
            res.push_back(ss.top());
            ss.pop();
        }
        return res;
    }
};

int main()
{
    {
        Solution s;

        // s.reversePrint()
    }
}