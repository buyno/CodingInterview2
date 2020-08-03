//很简单
// 24,反转链表
// 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
#include <unistd.h>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *result = new ListNode(-1);
        while (head)
        {
            ListNode *temp = result->next;
            result->next = head;
            head = head->next;
            result->next->next = temp;
        }
        return result->next;
    }
};