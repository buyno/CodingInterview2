#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Definition for a Node.
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
    Node *treeToDoublyList(Node *root)
    {
        Node *head;
        if (root == nullptr)
        {
            return nullptr;
        }
        Node *left = func_left(root->left);
        root->left = left;
        left->right = root;
        Node *right = func_right(root->right);
        root->right = right;
        right->left = root;
        Node *tmp = root;
        while (tmp->left)
        {
            tmp = tmp->left;
        }
        return tmp;
    }
    //return
    Node *func_left(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        Node *left = func_left(node->left);
        node->left = left;
        left->right = node;
        Node *right = func_right(node->right);
        node->right = right;
        right->left = node;
        Node *tmp = node;
        while (tmp->right)
        {
            tmp = tmp->right;
        }
        return tmp;
    }
    Node *func_right(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        Node *left = func_left(node->left);
        node->left = left;
        left->right = node;
        Node *right = func_right(node->right);
        node->right = right;
        right->left = node;
        Node *tmp = node;
        while (tmp->left)
        {
            tmp = tmp->left;
        }
        return tmp;
    }
};

int main()
{
    // Solution s;
    // Node *root = new Node(4);
    // root->left = new Node(2);
    // root->left->left = new Node(1);
    // root->left->right = new Node(3);
    // root->right = new Node(5);
    // Node *res = s.treeToDoublyList(root);
    // assert(res->val == 1);
    printf("%d\n", 0x40000000);
    printf("%d\n", 0x40000000 << 1);
    // 计算机：0x80000000(-2147483648)  /2  ->    0x40000000(1073741824)
    // 电脑计算器：0x80000000(-2147483648)  /2 -> 0xc0000000(‭-1073741824‬)
}