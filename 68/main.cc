#include <iostream>
#include <assert.h>
using namespace std;

// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
// :因为是二叉搜素树，所以只需要比较root/p/q的大小
// 如果root比p和q都大，应该递归左子树
// 如果root比p和q都小，应该递归右子树
// 如果root在p/q中间，说明当前root就是公共祖先

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *iter = root;
        while (iter)
        {
            if (iter->val < p->val && iter->val < q->val)
            {
                iter = iter->right;
            }
            else if (iter->val > q->val && iter->val > p->val)
            {
                iter = iter->left;
            }
            else
            {
                break;
            }
        }
        return iter;
    }
};

int main()
{
    {
        Solution s;
        TreeNode *root = new TreeNode(6);
        root->left = new TreeNode(2);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(4);
        root->left->right->left = new TreeNode(3);
        root->left->right->right = new TreeNode(5);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(9);
        auto res = s.lowestCommonAncestor(root, root->left, root->right);
        cout << res->val << endl;
        assert(res->val == 6);
    }
    {
        Solution s;
        TreeNode *root = new TreeNode(6);
        root->left = new TreeNode(2);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(4);
        root->left->right->left = new TreeNode(3);
        root->left->right->right = new TreeNode(5);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(9);
        auto res = s.lowestCommonAncestor(root, root->left->right->left, root->left->right->right);
        cout << res->val << endl;
        assert(res->val == 4);
    }
    {
        Solution s;
        TreeNode *root = new TreeNode(6);
        root->left = new TreeNode(2);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(4);
        root->left->right->left = new TreeNode(3);
        root->left->right->right = new TreeNode(5);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(9);
        auto res = s.lowestCommonAncestor(root, root, root);
        cout << res->val << endl;
        assert(res->val == 6);
    }
    {
        Solution s;
        TreeNode *root = new TreeNode(6);
        root->left = new TreeNode(2);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(4);
        root->left->right->left = new TreeNode(3);
        root->left->right->right = new TreeNode(5);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(9);
        auto res = s.lowestCommonAncestor(root, root->left->right->left, root->left->left);
        cout << res->val << endl;
        assert(res->val == 2);
    }
    {
        Solution s;
        TreeNode *root = new TreeNode(6);
        root->left = new TreeNode(2);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(0);
        root->left->right = new TreeNode(4);
        root->left->right->left = new TreeNode(3);
        root->left->right->right = new TreeNode(5);
        root->right->left = new TreeNode(7);
        root->right->right = new TreeNode(9);
        auto res = s.lowestCommonAncestor(root, root->left->right->left, root->right);
        cout << res->val << endl;
        assert(res->val == 6);
    }
}