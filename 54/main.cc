// 二叉搜索树的第K大节点
// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
// ：中序遍历+提前返回
#include <assert.h>
#include <iostream>
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
    int kthLargest(TreeNode *root, int k)
    {

        return func(root, k);
        // return -1;
    }
    // 因为数的范围是0~n-1，所以返回值为>=0时表示
    int func(TreeNode *root, int &k)
    {
        if (!root)
        {
            return -1;
        }
        int res;
        if ((res = func(root->right, k)) != -1)
        {
            return res;
        }
        k--;
        if (k == 0)
        {
            return root->val;
        }

        if ((res = func(root->left, k)) != -1)
        {
            return res;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int res = s.kthLargest(root, 2);
    cout << res << endl;
    assert(res == 3);
}