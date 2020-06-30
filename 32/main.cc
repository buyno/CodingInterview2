// 从上到下打印二叉树

// 用一个队列保存子节点

#include <stdio.h>
#include <queue>
#include "../utils/Tree.h"
using namespace std;

void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<TreeNode *> data;
    data.push(root);
    while (!data.empty())
    {
        TreeNode *tmp = data.front();
        data.pop();
        printf("%d ", tmp->value);
        if (tmp->left)
        {
            data.push(tmp->left);
        }
        if (tmp->right)
        {
            data.push(tmp->right);
        }
    }
    printf("\n");
}
int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(11);

    printTree(root);
    // printTree(nullptr);
}