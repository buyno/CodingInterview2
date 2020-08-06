// 从上到下打印二叉树

// 用一个队列保存子节点

#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> temp;
        TreeNode *node = root;
        vector<int> result;
        while (node)
        {
            result.push_back(node->val);
            // cout << node->val << endl;
            if (node->left)
            {
                temp.push(node->left);
            }
            if (node->right)
            {
                temp.push(node->right);
            }
            if (temp.empty())
            {
                break;
            }
            node = temp.front();
            temp.pop();
        }
        return result;
    }
};
int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(11);

    Solution s;
    auto res = s.levelOrder(root);
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}
s