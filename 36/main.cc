// 二叉搜索树与双向链表
// 将一个二叉搜索树转换为一个双向链表，要求不能新建任何节点，只是调整指针的方向

// 二叉搜索树的中序遍历序列就是递增序列
// 最开始有一个空节点tail，表示双向链表的尾巴
// 按照中序遍历，会先遍历右子树，在右子树的遍历中，肯定第一个遍历最右边，也就是最小的元素，将它作为tail序列的第一个节点
// 这时tail已经有了一个节点
// 下一个遍历的是最右节点的父节点，加它加到tail中，其他节点同理
// 返回到root节点时，将root加到tail上，再依次遍历右子树

#include "../utils/Tree.h"
#include <stdio.h>
#include "assert.h"
void buildLinkedList(TreeNode *root, TreeNode **tail)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        buildLinkedList(root->left, tail);
        if (*tail == nullptr)
        {
            *tail = root;
        }
        else
        {
            (*tail)->right = root;
            root->left = *tail;
            *tail = root;
        }
        buildLinkedList(root->right, tail);
    }
}
TreeNode *buildLinkedList(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode *tail = nullptr;
    buildLinkedList(root->left, &tail);

    if (tail)
    {
        tail->right = root;
        root->left = tail;
        tail = root;
    }
    else
    {
        tail = root;
    }

    buildLinkedList(root->right, &tail);
    TreeNode *head;
    while (tail->left)
    {
        tail = tail->left;
    }
    head = tail;

    return head;
}

void test1()
{
    TreeNode *root = nullptr;

    TreeNode *head = buildLinkedList(root);
    assert(head == nullptr);
}
void test2()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(14);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(16);
    TreeNode *head = buildLinkedList(root);
    assert(head->value == 4);
}
void test3()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->left->left = new TreeNode(4);
    TreeNode *head = buildLinkedList(root);
    assert(head->value == 4);
    assert(head->left == nullptr);
    assert(head->right->value == 6);
    assert(head->right->right->value == 10);
    assert(head->right->right->right == nullptr);
}
void test4()
{
    TreeNode *root = new TreeNode(10);
    root->right = new TreeNode(14);
    root->right->right = new TreeNode(16);
    TreeNode *head = buildLinkedList(root);
    assert(head->value == 10);
    assert(head->left == nullptr);
    assert(head->right->value == 14);
    assert(head->right->right->value == 16);
    assert(head->right->right->right == nullptr);
}
void test5()
{
    TreeNode *root = new TreeNode(10);
    TreeNode *head = buildLinkedList(root);
    assert(head->value == 10);
    assert(head->left == nullptr);
    assert(head->right == nullptr);
}
int main()
{

    test1();
    test2();
    test3();
    test4();
    test5();
}