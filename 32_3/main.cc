// 之字形打印二叉树
#include <stdio.h>
#include <vector>
#include <stack>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty() || !s2.empty())
        {
            vector<int> vec;
            while (!s1.empty())
            {
                TreeNode *tmp = s1.top();
                vec.push_back(tmp->val);
                s1.pop();
                if (tmp->left)
                {
                    s2.push(tmp->left);
                }
                if (tmp->right)
                {
                    s2.push(tmp->right);
                }
            }
            if (!vec.empty())
            {
                res.push_back(vec);
                vec.clear();
            }

            while (!s2.empty())
            {
                TreeNode *tmp = s2.top();
                vec.push_back(tmp->val);
                s2.pop();
                if (tmp->right)
                {
                    s1.push(tmp->right);
                }
                if (tmp->left)
                {
                    s1.push(tmp->left);
                }
            }
            if (!vec.empty())
                res.push_back(vec);
        }
        return res;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    auto res = s.levelOrder(root);
    for (auto x : res)
    {
        for (auto y : x)
        {
            printf("%d ", y);
        }
        printf("\n");
    }
}
