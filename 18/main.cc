// O(1)时间复杂度下，删除链表的一个结点
// 已知头指针和要删除的节点的指针
// 要删除的节点一定在链表上
#include <assert.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 1;
    }
    ListNode(int a)
    {
        val = a;
    }
};
//leetcode中将这题简单化了。O(1)解法参考deleteNode(ListNode *head, ListNode *node),不过这种解法删尾节点时复杂度仍然为O(n)
class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        // ListNode* prenode,current;
        ListNode *prenode = nullptr;
        ListNode *current = head;
        if (head->val == val)
        {
            ListNode *tmp = head->next;
            // delete head;
            return tmp;
        }
        while (current)
        {
            if (current->val == val)
            {
                prenode->next = current->next;
                // delete current;
                break;
            }
            else
            {
                prenode = current;
                current = current->next;
            }
        }
        return head;
    }
    // O(1)
    ListNode *deleteNode(ListNode *head, ListNode *node)
    {
        if (!head)
        {
            return nullptr;
        }
        //考虑删除尾节点
        if (!node->next)
        {
            //考虑只有一个节点
            if (!head->next && node == head)
            {
                return nullptr;
            }
            ListNode *iter = head, *pre = head;
            while (iter->next)
            {
                pre = iter;
                iter = iter->next;
            }
            pre->next = nullptr;
            return head;
        }
        node->val = node->next->val;
        node->next = node->next->next;
        return head;
    }
};

int main()
{
    {
        ListNode *root = new ListNode(1);
        Solution s;
        ListNode *newroot = s.deleteNode(root, 1);
        assert(newroot == nullptr);
    }
    {
        ListNode *root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);

        Solution s;
        s.deleteNode(root, 2);
        assert(root->val == 1 && root->next->val == 3);
    }
    {
        ListNode *root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);

        Solution s;
        root = s.deleteNode(root, 1);
        assert(root->val == 2 && root->next->val == 3);
    }
    {
        ListNode *root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);

        Solution s;
        root = s.deleteNode(root, root->next);
        assert(root->val == 1 && root->next->val == 3);
    }
    {
        ListNode *root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);

        Solution s;
        root = s.deleteNode(root, root);
        assert(root->val == 2 && root->next->val == 3);
    }
    {
        ListNode *root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);

        Solution s;
        root = s.deleteNode(root, root->next->next);
        assert(root->val == 1 && root->next->val == 2);
    }
    {
        ListNode *root = new ListNode(1);
        root->next = new ListNode(2);
        // root->next->next = new ListNode(3);

        Solution s;
        root = s.deleteNode(root, root->next);
        assert(root->val == 1 && root->next == nullptr);
    }
    {
        ListNode *root = new ListNode(1);
        root->next = new ListNode(2);
        // root->next->next = new ListNode(3);

        Solution s;
        root = s.deleteNode(root, root);
        assert(root->val == 2 && root->next == nullptr);
    }
    {
        ListNode *root = new ListNode(1);
        // root->next = new ListNode(2);
        // root->next->next = new ListNode(3);

        Solution s;
        root = s.deleteNode(root, root);
        assert(root == nullptr);
    }
    {
        ListNode *root = nullptr;
        ListNode *node = new ListNode(2);
        // root->next->next = new ListNode(3);

        Solution s;
        root = s.deleteNode(root, node);
        assert(root == nullptr);
    }
    {
        ListNode *root = new ListNode(1);
        root->next = new ListNode(2);
        root->next->next = new ListNode(3);
        ListNode *node = new ListNode(22);
        Solution s;
        root = s.deleteNode(root, node);
        // assert(root == nullptr);
    }
}