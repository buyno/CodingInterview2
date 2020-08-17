#include <vector>
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
//解法一，递归法：返回值表示这个子树是否有p或者q。
// 如果左右子树都返回非空，表示当前节点是共同祖先，返回当前节点，
// 如果只有一边非空，另一边返回空，说明pq都在一边的子树上，返回对应边的递归返回值即可
// 如果两边都返回空，说明pq在另外的子树上，返回空即可
// 还要考虑p在q的子树中的情况
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root == p)
        {
            return p;
        }
        else if (root == q)
        {
            return q;
        }
        auto res1 = lowestCommonAncestor(root->left, p, q);
        auto res2 = lowestCommonAncestor(root->right, p, q);
        if (res1 && res2)
        {
            return root;
        }
        else if (res1)
        {
            return res1;
        }
        else if (res2)
        {
            return res2;
        }

        return nullptr;
    }
};
// 解法二，相当于先序遍历，将遍历的中间节点保存到一个vector中(模拟一个栈),可以得到根节点到p/q的路径
// 然后就是找这个链表的最近公共祖先了

// class Solution
// {
// public:
//     vector<TreeNode *> data;
//     vector<TreeNode *> temp1;
//     vector<TreeNode *> temp2;
//     int temp1ofound = 0;
//     int temp2ofound = 0;
//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         if (p->val == q->val)
//         {
//             return p;
//         }
//         dfs(root, p, q);
//         int index = 0;
//         TreeNode *pre = root;
//         // 找两个链表的公共节点
//         while (index < temp1.size() || index < temp2.size())
//         {
//             if (index == temp1.size())
//             {
//                 pre = temp1[temp1.size() - 1];
//                 break;
//             }
//             else if (index == temp2.size())
//             {
//                 pre = temp2[temp2.size() - 1];
//                 break;
//             }
//             if (temp1[index] != temp2[index])
//             {
//                 break;
//             }
//             else
//             {
//                 pre = temp1[index];
//                 index++;
//             }
//         }
//         return pre;
//     }
//     void dfs(TreeNode *node, TreeNode *p, TreeNode *q)
//     {
//         if (node == nullptr)
//         {
//             return;
//         }
//         data.push_back(node);
//         if (node->val == p->val)
//         {
//             temp1 = data;
//             if (temp2ofound)
//             {
//                 return;
//             }
//             temp1ofound = 1;
//         }
//         else if (node->val == q->val)
//         {
//             temp2 = data;
//             if (temp1ofound)
//             {
//                 return;
//             }
//             temp2ofound = 1;
//         }

//         dfs(node->left, p, q);
//         dfs(node->right, p, q);
//         data.pop_back();
//     }
// };
int main()
{
    {
        Solution s;
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(7);
        root->left->right->right = new TreeNode(4);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);
        auto res = s.lowestCommonAncestor(root, root->left, root->right);
        cout << res->val << endl;
        assert(res->val == 3);
    }
    {
        Solution s;
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(7);
        root->left->right->right = new TreeNode(4);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);
        auto res = s.lowestCommonAncestor(root, root->left->right->left, root->left->right->right);
        cout << res->val << endl;
        assert(res->val == 2);
    }
    {
        Solution s;
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(7);
        root->left->right->right = new TreeNode(4);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);
        auto res = s.lowestCommonAncestor(root, root, root);
        cout << res->val << endl;
        assert(res->val == 3);
    }
    {
        Solution s;
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(7);
        root->left->right->right = new TreeNode(4);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);
        auto res = s.lowestCommonAncestor(root, root->left->right->left, root->left->left);
        cout << res->val << endl;
        assert(res->val == 5);
    }
    {
        Solution s;
        TreeNode *root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(7);
        root->left->right->right = new TreeNode(4);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);
        auto res = s.lowestCommonAncestor(root, root->left->right->left, root->right);
        cout << res->val << endl;
        assert(res->val == 3);
    }
}