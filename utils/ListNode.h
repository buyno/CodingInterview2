struct ListNode
{
    int value;
    ListNode *pNext;
};
void addToTail(ListNode **head, int value);
void printListNode(ListNode *head);
void printListNodeReverse(ListNode *head);
void destroyListNode(ListNode *head);