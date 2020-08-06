// 二叉搜索树与双向链表
// 将一个二叉搜索树转换为一个双向链表，要求不能新建任何节点，只是调整指针的方向

// 方法1，比较复杂
// 二叉搜索树的中序遍历序列就是递增序列
// 最开始有一个空节点tail，表示双向链表的尾巴
// 按照中序遍历，会先遍历右子树，在右子树的遍历中，肯定第一个遍历最右边，也就是最小的元素，将它作为tail序列的第一个节点
// 这时tail已经有了一个节点
// 下一个遍历的是最右节点的父节点，加它加到tail中，其他节点同理
// 返回到root节点时，将root加到tail上，再依次遍历右子树
//
// 方法2
// 递归，维护一个head指针和pre指针,利用中序遍历的模板，最开始pre时null，当第一次到最左节点时，pre一定是null，他就是head。同时调整指针，pre=cur。
// 然后到中序遍历的下一个节点，这时候pre已经保存为前一个节点，调整指针即可。
#include "assert.h"
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    Node *pre, *head;
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
        {
            return nullptr;
        }
        pre = nullptr;

        dfs(root);
        head->left = pre;
        pre->right = head;

        return head;
    }
    void dfs(Node *cur)
    {
        if (!cur)
        {
            return;
        }
        dfs(cur->left);
        if (!pre)
        {
            head = cur;
            pre = cur;
            // cur->left = nullptr;
        }
        else
        {
            cur->left = pre;
            pre->right = cur;
            pre = cur;
        }
        // cout << cur->val << endl;
        dfs(cur->right);
        return;
    }
};
typedef Node TreeNode;
int main()
{
    {
        TreeNode *root = new TreeNode(10);
        root->left = new TreeNode(6);
        root->right = new TreeNode(14);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(8);
        root->right->left = new TreeNode(12);
        root->right->right = new TreeNode(16);
        Solution s;
        Node *result = s.treeToDoublyList(root);

        Node *start = result;
        do
        {
            cout << start->val << endl;
            start = start->right;
        } while (start != result);
    }
    {
        TreeNode *root = nullptr;
        Solution s;
        Node *result = s.treeToDoublyList(root);
        assert(result == nullptr);
    }
    {
        TreeNode *root = new TreeNode(10);
        Solution s;
        Node *result = s.treeToDoublyList(root);

        Node *start = result;
        do
        {
            cout << start->val << endl;
            start = start->right;
        } while (start != result);
    }
    {
        TreeNode *root = new TreeNode(10);
        root->left = new TreeNode(6);
        // root->right = new TreeNode(14);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(8);
        // root->right->left = new TreeNode(12);
        // root->right->right = new TreeNode(16);
        Solution s;
        Node *result = s.treeToDoublyList(root);

        Node *start = result;
        do
        {
            cout << start->val << endl;
            start = start->right;
        } while (start != result);
    }
}