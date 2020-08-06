// 复杂链表的复制
// 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

// 三种方法，第一种n*n，每次都顺序查找节点
// 第二种用map保存新旧节点的对应关系，找random时直接查找(map和unordered_map)。时间复杂度O(N),空间复杂度O(N),不考虑new的节点
// 第三种在每个节点后面copy一个相同节点，在找random时直接取next即可。最后再将结果从链表中取出。时间复杂度O(N),空间复杂度O(1),不考虑new的节点
#include <map>
#include <assert.h>
using namespace std;

#include <iostream>
#include <unordered_map>
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }
        Node *iter = head;
        while (iter)
        {
            Node *newnode = new Node(iter->val);
            Node *temp = iter->next;
            iter->next = newnode;
            newnode->next = temp;
            iter = iter->next->next;
        }
        iter = head;
        while (iter)
        {
            if (iter->random)
            {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        Node *result = new Node(-1);
        Node *newiter = result;
        iter = head;
        while (iter)
        {
            newiter->next = iter->next;
            iter->next = iter->next->next;
            // newiter->next = temp;
            newiter->next->next = nullptr;
            iter = iter->next;
            newiter = newiter->next;
        }
        Node *temp = result;
        result = result->next;
        delete temp;
        return result;
    }
};
int main()
{
    Solution s;
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    auto res = s.copyRandomList(head);
}