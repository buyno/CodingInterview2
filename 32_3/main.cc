// 之字形打印二叉树
// 两个栈 或者 一个双端队列
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        stack<TreeNode *> s1; //偶数层
        stack<TreeNode *> s2;
        TreeNode *node = root;
        s1.push(node);
        vector<vector<int>> result;
        int level = 0;
        result.push_back(vector<int>());
        while (node)
        {
            if (level % 2 == 0)
            {
                int size = s1.size();
                while (size)
                {
                    node = s1.top();
                    s1.pop();
                    result[level].push_back(node->val);
                    if (node->left)
                    {
                        s2.push(node->left);
                    }
                    if (node->right)
                    {
                        s2.push(node->right);
                    }
                    size--;
                }

                if (s2.empty())
                {
                    break;
                }
                else
                {
                    level++;
                    result.push_back(vector<int>());
                }
            }
            else
            {
                int size = s2.size();
                while (size)
                {
                    node = s2.top();
                    s2.pop();
                    result[level].push_back(node->val);
                    if (node->right)
                    {
                        s1.push(node->right);
                    }
                    if (node->left)
                    {
                        s1.push(node->left);
                    }
                    size--;
                }
                if (s1.empty())
                {
                    break;
                }
                else
                {
                    level++;
                    result.push_back(vector<int>());
                }
            }
        }
        return result;
    }
};

int main()
{
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
    {
        TreeNode *root = new TreeNode(3);
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
    {
        TreeNode *root = nullptr;
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
}
