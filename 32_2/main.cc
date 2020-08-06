// 分行从上到下打印二叉树

// 用队列，但是需要记录当前层还没有打印的节点数和下一层的节点数目

#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//解法1：记录每层的节点树
// class Solution
// {
// public:
//     vector<vector<int>> levelOrder(TreeNode *root)
//     {
//         if (!root)
//         {
//             return {};
//         }
//         queue<TreeNode *> temp;
//         TreeNode *node = root;
//         vector<int> vec;
//         vector<vector<int>> result;
//         int levelnumber = 0;
//         int currentlineremain = 1;
//         while (node)
//         {
//             // cout << node->val << endl;
//             vec.push_back(node->val);
//             currentlineremain--;

//             if (node->left)
//             {
//                 temp.push(node->left);
//                 levelnumber++;
//             }
//             if (node->right)
//             {
//                 temp.push(node->right);
//                 levelnumber++;
//             }
//             if (!temp.empty())
//             {
//                 node = temp.front();
//                 temp.pop();
//             }
//             else
//             {
//                 break;
//             }
//             if (currentlineremain == 0)
//             {
//                 currentlineremain = levelnumber;
//                 levelnumber = 0;
//                 result.push_back(vec);
//                 vec.clear();
//             }
//         }
//         result.push_back(vec);
//         return result;
//     }
// };
// 解法2：一种比较巧妙的方法，
// 每个循环开始时记录queue的大小，这个大小就是当前层的节点数，
// 然后在队列中依次取出来加到vector中并将子树加到队列中(加到队列后队列大小就变了，所以要在开始时记录)
//
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        queue<TreeNode *> temp;
        vector<vector<int>> result;
        temp.push(root);
        // int column = 0;
        while (!temp.empty())
        {
            // result.push_back(vector<int>());
            vector<int> vec;
            for (int i = temp.size(); i > 0; i--)
            {
                auto node = temp.front();
                temp.pop();
                vec.push_back(node->val);
                if (node->left)
                {
                    temp.push(node->left);
                }
                if (node->right)
                {
                    temp.push(node->right);
                }
            }
            result.push_back(vec);
            // column++;
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
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}