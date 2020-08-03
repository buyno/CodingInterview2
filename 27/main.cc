// 输入一个二叉树，该函数输出它的镜像,不用new新节点
// 返回一颗树，新树是原树的镜像
#include <iostream>
#include <assert.h>
using namespace std;
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
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (root)
        {
            mirrorTree(root->left);
            mirrorTree(root->right);
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        return root;
    }
};
int main()
{
    {
        Solution s;
        TreeNode *root = new TreeNode(10);
        root->left = new TreeNode(1);
        root->right = new TreeNode(7);
        auto res = s.mirrorTree(root);
        assert(res->val == 10 && res->left->val == 7 && res->right->val == 1);
    }
}
