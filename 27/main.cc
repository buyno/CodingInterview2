// 输出二叉树的镜像
// 返回一颗新树，新树是原树的镜像

#include "../Tree.h"
#include <stdio.h>

TreeNode *getMirrorTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode *node = new TreeNode(root->value);
    // if(root->left)
    node->right = getMirrorTree(root->left);
    // if(root->right)
    node->left = getMirrorTree(root->right);
    return node;
}
//先序遍历
void printTree_preorder(TreeNode *root)
{
    if (root != nullptr)
    {
        printf("%d ", root->value);
        printTree_preorder(root->left);
        printTree_preorder(root->right);
    }
}
//中序遍历
void printTree_inorder(TreeNode *root)
{
    if (root != nullptr)
    {
        printTree_inorder(root->left);
        printf("%d ", root->value);

        printTree_inorder(root->right);
    }
}
void Test1()
{
    printf("Test1 starts\n");
    TreeNode *root = nullptr;
    root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(11);

    printTree_preorder(root);
    printf("\n");
    printTree_inorder(root);
    TreeNode *newroot = getMirrorTree(root);
    printf("\nmirror:\n");
    printTree_preorder(newroot);
    printf("\n");
    printTree_inorder(newroot);
    printf("\n");
}
void Test2()
{
    printf("Test2 starts\n");
    TreeNode *root = nullptr;
    root = new TreeNode(8);
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(6);
    root->left->left->left = new TreeNode(5);
    root->left->left->left->left = new TreeNode(4);

    printTree_preorder(root);
    printf("\n");
    printTree_inorder(root);
    TreeNode *newroot = getMirrorTree(root);
    printf("\nmirror:\n");
    printTree_preorder(newroot);
    printf("\n");
    printTree_inorder(newroot);
    printf("\n");
}
void Test3()
{
    printf("Test3 starts\n");
    TreeNode *root = nullptr;
    root = new TreeNode(8);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(5);
    root->right->right->right->right = new TreeNode(4);

    printTree_preorder(root);
    printf("\n");
    printTree_inorder(root);
    TreeNode *newroot = getMirrorTree(root);
    printf("\nmirror:\n");
    printTree_preorder(newroot);
    printf("\n");
    printTree_inorder(newroot);
    printf("\n");
}
void Test4()
{
    printf("Test4 starts\n");
    TreeNode *root = nullptr;

    printTree_preorder(root);
    printf("\n");
    printTree_inorder(root);
    TreeNode *newroot = getMirrorTree(root);
    printf("\nmirror:\n");
    printTree_preorder(newroot);
    printf("\n");
    printTree_inorder(newroot);
    printf("\n");
}
void Test5()
{
    printf("Test5 starts\n");
    TreeNode *root = nullptr;
    root = new TreeNode(8);

    printTree_preorder(root);
    printf("\n");
    printTree_inorder(root);
    TreeNode *newroot = getMirrorTree(root);
    printf("\nmirror:\n");
    printTree_preorder(newroot);
    printf("\n");
    printTree_inorder(newroot);
    printf("\n");
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
}
