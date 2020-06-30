// 判断二叉树是否对称
// 所谓对称就是节点的左子树等于节点的右子树。
// 用两个指针代表两个树,一个是原树，一个是想象的对称树
// 递归比较原树左子树与对称树的右子树，原树右子树与对称树的左子树
// X解决：前序遍历序列和前序遍历镜像序列相同X
#include <stdio.h>
#include <assert.h>
#include "../utils/Tree.h"
// return 1 是镜像； 0不是镜像树
int isTreeMirror(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return 1;
    }
    if (root1 == nullptr || root2 == nullptr)
    {
        return 0;
    }

    if (root1->value != root2->value)
    {
        return 0;
    }
    else
    {
        return isTreeMirror(root1->left, root2->right) && isTreeMirror(root1->right, root2->left);
    }
}
int isTreeMirror(TreeNode *root)
{
    return isTreeMirror(root, root);

    // return 0;
}
void Test1()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(5);
    int res = isTreeMirror(root);
    assert(res == 1);
}
void Test2()
{
    TreeNode *root = nullptr;
    int res = isTreeMirror(root);
    assert(res == 1);
}
void Test3()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);
    int res = isTreeMirror(root);
    assert(res == 0);
}
void Test4()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(7);
    int res = isTreeMirror(root);
    assert(res == 0);
}
void Test5()
{
    TreeNode *root = new TreeNode(8);

    int res = isTreeMirror(root);
    assert(res == 1);
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
}