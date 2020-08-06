// 二叉树中和为某一值的路径

//用vector模拟栈记录路径

#include <vector>
#include <stdio.h>
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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (!root)
        {
            return {};
        }
        vector<int> path;
        vector<vector<int>> result;
        pathSum(root, sum, path, result);
        return result;
    }
    int pathSum(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &result)
    {
        if (!root->left && !root->right)
        {
            if (sum == root->val)
            {
                path.push_back(root->val);
                result.push_back(path);
                path.pop_back();
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            path.push_back(root->val);
            int res = 0;
            if (root->left)
            {
                res = pathSum(root->left, sum - root->val, path, result) || res;
            }
            if (root->right)
            {
                res = pathSum(root->right, sum - root->val, path, result) || res;
            }
            path.pop_back();
            return res;
        }
    }
};
int main()
{
    {
        TreeNode *root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->right = new TreeNode(13);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(6);
        Solution s;
        auto res = s.pathSum(root, 22);
        for (auto x : res)
        {
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }
    {
        TreeNode *root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->right = new TreeNode(8);
        root->left->left = new TreeNode(11);
        root->right->left = new TreeNode(13);
        root->right->right = new TreeNode(4);
        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);
        root->right->right->left = new TreeNode(5);
        root->right->right->right = new TreeNode(1);
        Solution s;
        auto res = s.pathSum(root, 22);
        for (auto x : res)
        {
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }
}