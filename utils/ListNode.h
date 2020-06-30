#include <stdio.h>

struct ListNode
{
    int value;
    ListNode *pNext;
};
void addToTail(ListNode **head, int value)
{
    ListNode *pNode = new ListNode();
    pNode->value = value;
    if (*head)
    {
        ListNode *tail = *head;
        while (tail->pNext)
        {
            tail = tail->pNext;
        }
        tail->pNext = pNode;
    }
    else
    {
        *head = pNode;
    }
}
void printListNode(ListNode *head)
{
    ListNode *node = head;
    while (node->pNext)
    {
        printf("%d\n", node->value);
        node = node->pNext;
    }
    printf("%d\n", node->value);
}
void printListNodeReverse(ListNode *head)
{
    if (head == nullptr)
        return;
    if (head->pNext)
    {
        printListNodeReverse(head->pNext);
        printf("%d\n", head->value);
    }
    else
    {
        printf("%d\n", head->value);
    }
}

void destroyListNode(ListNode *head)
{
    ListNode *node = head;
    while (node)
    {
        ListNode *next = node->pNext;
        delete node;
        node = next;
    }
}