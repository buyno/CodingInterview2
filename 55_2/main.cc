// 判断是否是平衡二叉树
// 1) 递归。会重复遍历
// 2）后续遍历.所有节点只需要遍历一次
#include <stdio.h>
#include <assert.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // 相当于后序遍历
    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        int left = getDepth(root->left);
        if (left == -1)
        {
            return false;
        }
        int right = getDepth(root->right);
        if (right == -1)
        {
            return false;
        }
        if (left > right)
        {
            if (left - right <= 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (right - left <= 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    // 如果子树是平衡的就返回它的高度，如果不是平衡的直接返回-1
    int getDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left = getDepth(root->left);
        if (left == -1)
        {
            return -1;
        }
        int right = getDepth(root->right);
        if (right == -1)
        {
            return -1;
        }
        if (left > right)
        {
            if (left - right <= 1)
            {
                return left + 1;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            if (right - left <= 1)
            {
                return right + 1;
            }
            else
            {
                return -1;
            }
        }
    }
};