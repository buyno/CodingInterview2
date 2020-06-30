// 两个链表的第一个公共节点
#include <assert.h>

struct ListNode
{
    ListNode() : value(0) {}
    ListNode(int val) : value(val) {}
    int value;
    ListNode *pNext;
};
ListNode *getShareNode(ListNode *root1, ListNode *root2)
{
    int length1 = 0;
    int length2 = 0;
    ListNode *tmp = root1;
    while (tmp)
    {
        length1++;
        tmp = tmp->pNext;
    }
    tmp = root2;
    while (tmp)
    {
        length2++;
        tmp = tmp->pNext;
    }
    if (length1 > length2)
    {
        for (int i = 0; i < length1 - length2; i++)
        {
            root1 = root1->pNext;
        }
    }
    else
    {
        for (int i = 0; i < length2 - length1; i++)
        {
            root2 = root2->pNext;
        }
    }
    while (root1 != root2)
    {
        root1 = root1->pNext;
        root2 = root2->pNext;
    }

    return root1;
}
void test1()
{
    assert(getShareNode(nullptr, nullptr) == nullptr);
    ListNode *root1 = new ListNode(1);
    assert(getShareNode(root1, nullptr) == nullptr);
    assert(getShareNode(nullptr, root1) == nullptr);
}
void test2()
{
    ListNode *root1 = new ListNode(1);

    root1->pNext = new ListNode(2);
    root1->pNext->pNext = new ListNode(3);
    ListNode *tmp = root1->pNext->pNext->pNext = new ListNode(6);
    root1->pNext->pNext->pNext->pNext = new ListNode(7);
    ListNode *root2 = new ListNode(4);
    root2->pNext = new ListNode(5);
    root2->pNext->pNext = tmp;
    ListNode *res = getShareNode(root1, root2);
    assert(res->value == 6);
    res = getShareNode(root2, root1);
    assert(res->value == 6);
}
// →1->2->3->6->7
//  ↑
void test3()
{
    ListNode *root1 = new ListNode(1);

    root1->pNext = new ListNode(2);
    root1->pNext->pNext = new ListNode(3);
    ListNode *tmp = root1->pNext->pNext->pNext = new ListNode(6);
    root1->pNext->pNext->pNext->pNext = new ListNode(7);
    ListNode *root2 = root1;
    // root2->pNext = new ListNode(5);
    // root2->pNext->pNext = tmp;
    ListNode *res = getShareNode(root1, root2);
    assert(res->value == 1);
    res = getShareNode(root2, root1);
    assert(res->value == 1);
}
// →1->2->3->6->7
//         4->5-↑
void test4()
{
    ListNode *root1 = new ListNode(1);

    root1->pNext = new ListNode(2);
    root1->pNext->pNext = new ListNode(3);
    root1->pNext->pNext->pNext = new ListNode(6);
    ListNode *tmp = root1->pNext->pNext->pNext->pNext = new ListNode(7);
    ListNode *root2 = new ListNode(4);
    root2->pNext = new ListNode(5);
    root2->pNext->pNext = tmp;
    ListNode *res = getShareNode(root1, root2);
    assert(res->value == 7);
    res = getShareNode(root2, root1);
    assert(res->value == 7);
}
//没有交集
// →1->2->3->6->7
// →4->5
void test5()
{
    ListNode *root1 = new ListNode(1);

    root1->pNext = new ListNode(2);
    root1->pNext->pNext = new ListNode(3);
    root1->pNext->pNext->pNext = new ListNode(6);
    ListNode *tmp = root1->pNext->pNext->pNext->pNext = new ListNode(7);
    ListNode *root2 = new ListNode(4);
    root2->pNext = new ListNode(5);
    ListNode *res = getShareNode(root1, root2);
    assert(res == nullptr);
    res = getShareNode(root2, root1);
    assert(res == nullptr);
}
int main()
{

    test1();
    test2();
    test3();
    test4();
    test5();
}