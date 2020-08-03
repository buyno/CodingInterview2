// 判断二叉树是否对称
// 所谓对称就是节点的左子树等于节点的右子树。
// 用两个指针代表两个树,一个是原树，一个是想象的对称树
// 递归比较原树左子树与对称树的右子树，原树右子树与对称树的左子树
// X解决：前序遍历序列和前序遍历镜像序列相同X
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
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *iter1 = root;
        TreeNode *iter2 = root;
        return isSymmetric(iter1, iter2);
    }
    bool isSymmetric(TreeNode *iter1, TreeNode *iter2)
    {
        if (!iter1 && !iter2)
        {
            return true;
        }
        if (!iter1 || !iter2)
        {
            return false;
        }
        if (iter1 && iter2 && iter1->val == iter2->val)
        {
            return isSymmetric(iter1->left, iter2->right) && isSymmetric(iter1->right, iter2->left);
        }
        return false;
    }
};

int main()
{
    {
        Solution s;
    }
}