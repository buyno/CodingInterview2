// 判断是否是平衡二叉树
// 1) 递归。会重复遍历
// 2）后续遍历.所有节点只需要遍历一次
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
int getTreeDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left, right;
    left = getTreeDepth(root->left);
    right = getTreeDepth(root->right);
    return left > right ? left + 1 : right + 1;
}
int balancedTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return 1;
    }
    int left, right;
    left = getTreeDepth(root->left);
    right = getTreeDepth(root->right);
    if (left - right >= -1 && left - right <= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// return是否平衡，depth返回的深度
int postorder(TreeNode *root, int &depth)
{
    if (root == nullptr)
    {
        depth = 0;
        return 1;
    }
    int left, right;
    int res1, res2;
    res1 = postorder(root->left, left);
    res2 = postorder(root->right, right);
    depth = left > right ? left + 1 : right + 1;
    if (res1 && res2 && (left - right >= -1 && left - right <= 1))
    {

        return 1;
    }
    else
    {
        return 0;
    }
}
int balancedTree_2(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left, right;
    int res1, res2;
    res1 = postorder(root->left, left);
    res2 = postorder(root->right, right);
    if (res1 && res2)
    {
        if (left - right <= 1 && left - right >= -1)
        {
            return 1;
        }
    }
    return 0;
}
// 完全二叉树
// 一般的平衡二叉树
// 一般的不平衡二叉树
// 全左/全右+平衡/不平衡
//
void test0()
{
    assert(balancedTree(nullptr) == 1);
    assert(balancedTree_2(nullptr) == 1);
}
void test1()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    int res;
    res = balancedTree(root);
    assert(res == 1);
    res = balancedTree_2(root);
    assert(res == 1);
}
void test2()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    int res;
    res = balancedTree(root);
    assert(res == 1);
    res = balancedTree_2(root);
    assert(res == 1);
}
void test3()
{
    TreeNode *root = new TreeNode(5);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    int res;
    res = balancedTree(root);
    assert(res == 0);
    res = balancedTree_2(root);
    assert(res == 0);
}
void test4()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    int res;
    res = balancedTree(root);
    assert(res == 0);
    res = balancedTree_2(root);
    assert(res == 0);
}
void test5()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);

    int res;
    res = balancedTree(root);
    assert(res == 1);
    res = balancedTree_2(root);
    assert(res == 1);
}
void test6()
{
    TreeNode *root = new TreeNode(5);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    int res;
    res = balancedTree(root);
    assert(res == 0);
    res = balancedTree_2(root);
    assert(res == 0);
}
void test7()
{
    TreeNode *root = new TreeNode(5);
    root->right = new TreeNode(7);

    int res;
    res = balancedTree(root);
    assert(res == 1);
    res = balancedTree_2(root);
    assert(res == 1);
}
void test8()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    // root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(2);
    root->right->right->right = new TreeNode(8);
    int res;
    // res = balancedTree(root);
    // assert(res == 0);
    res = balancedTree_2(root);
    assert(res == 0);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
}