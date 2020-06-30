// 求二叉树的深度

// 1)递归，分别求左右子树的深度，再+1（后序遍历）
#include <stdio.h>
#include <assert.h>

struct TreeNode
{
    TreeNode() : value(0) {}
    TreeNode(int val) : value(val) {}
    int value;
    TreeNode *left;
    TreeNode *right;
};
int getDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = getDepth(root->left);
    int right = getDepth(root->right);
    if (left > right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}
//空
// 完全二叉树
// 一般二叉树
// 只有右子树
// 只有左子树
//一个节点
void test1()
{
    assert(getDepth(nullptr) == 0);
}
void test2()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    int res;
    res = getDepth(root);
    assert(res == 3);
}
void test3()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    int res;
    res = getDepth(root);
    assert(res == 3);
}
void test4()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    int res;
    res = getDepth(root);
    assert(res == 3);
}
void test5()
{
    TreeNode *root = new TreeNode(5);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    int res;
    res = getDepth(root);
    assert(res == 3);
}
void test6()
{
    TreeNode *root = new TreeNode(5);

    int res;
    res = getDepth(root);
    assert(res == 1);
}
int main()
{

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}