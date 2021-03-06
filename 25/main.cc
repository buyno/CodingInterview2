// 25,合并两个排序的链表
// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(-1);
        ListNode *tail = result;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
                tail->next = nullptr;
            }
            else
            {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
                tail->next = nullptr;
            }
        }
        if (l1)
        {
            tail->next = l1;
        }
        if (l2)
        {
            tail->next = l2;
        }
        ListNode *temp = result->next;
        delete result;
        return temp;
    }
};