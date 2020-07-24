//利用中序遍历序列和前序遍历序列构造二叉树

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]

// 前序遍历序列的第一个值一定是root节点
// root节点的后一个值一定是root的左子树的根节点，
// 并且前序遍历序列中root的后面一串中，一定是前面一部分是左子树的，后面一部分是右子树的。
// 比如说3后面的9，10是左子树的，且9是左子树的根节点，15，7是右子树的节点且15是右子树的根节点
//
#include <iostream>
#include <assert.h>
#include <vector>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
        {
            return nullptr;
        }
        return buildSubTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *buildSubTree(vector<int> &preorder, vector<int> &inorder, int preorderleft, int preorderright, int inorderleft, int inorderright)
    {
        if (inorderleft > inorderright)
        {
            return nullptr;
        }
        // preorder的第一个值一定是根节点
        int rootvalue = preorder[preorderleft];
        TreeNode *root = new TreeNode(rootvalue);
        int leftlength = 0; //左子树的节点个数
        while (inorder[inorderleft + leftlength] != rootvalue)
        {
            leftlength++;
        }
        //根据左子树的节点个数就可以确定递归时的边界
        root->left = buildSubTree(preorder, inorder, preorderleft + 1, preorderleft + leftlength, inorderleft, inorderleft + leftlength - 1);
        root->right = buildSubTree(preorder, inorder, preorderleft + leftlength + 1, preorderright, inorderleft + leftlength + 1, inorderright);
        return root;
    }
};

int main()
{
    {
        Solution s;
        vector<int> inorder = {3, 9, 20, 15, 7};
        vector<int> preorder = {9, 3, 15, 20, 7};

        auto root = s.buildTree(inorder, preorder);
        assert(root->val == 3);
        assert(root->left->val == 9);
        assert(root->right->val == 20);
        assert(root->left->left == nullptr);
        assert(root->left->right == nullptr);
        assert(root->right->left->val == 15);
        assert(root->right->right->val == 7);
        assert(root->right->left->left == nullptr);
        assert(root->right->left->right == nullptr);
        assert(root->right->right->left == nullptr);
        assert(root->right->right->right == nullptr);
    }
    {
        Solution s;
        vector<int> inorder = {3};
        vector<int> preorder = {3};

        auto root = s.buildTree(inorder, preorder);
        assert(root->val == 3);
        assert(root->left == nullptr);
        assert(root->right == nullptr);
    }
    {
        Solution s;
        vector<int> inorder;
        vector<int> preorder;
        auto root = s.buildTree(inorder, preorder);
        assert(root == nullptr);
    }
}
