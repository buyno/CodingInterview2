// 二叉搜索树的第K大节点

#include <assert.h>
#include <stdio.h>

// struct TreeNode
// {
//     TreeNode() : value(0) {}
//     TreeNode(int val) : value(val) {}
//     int value;
//     TreeNode *left;
//     TreeNode *right;
// };
// TreeNode *getFirstKValue(TreeNode *root, int K, int *pcount)
// {
//     if (root == nullptr)
//     {

//         return nullptr;
//     }
//     else
//     {
//         if (TreeNode *res = getFirstKValue(root->left, K, pcount))
//         {
//             return res;
//         }
//         // printf("%d ", root->value);
//         // *pcount++;
//         if (++(*pcount) == K)
//         {
//             return root;
//         }
//         if (TreeNode *res = getFirstKValue(root->right, K, pcount))
//         {
//             return res;
//         }
//         return nullptr;
//     }
// }
// int getFirstKValue(TreeNode *root, int k)
// {
//     if (root == nullptr)
//     {
//         return -1; //log
//     }
//     int count = 0;
//     TreeNode *res;
//     res = getFirstKValue(root, k, &count);
//     if (res == nullptr)
//     {
//         printf("not found\n");
//         return -1;
//     }

//     return res->value;
// }
// void test1()
// {
//     TreeNode *root = new TreeNode(5);
//     root->left = new TreeNode(3);
//     root->right = new TreeNode(7);
//     root->left->left = new TreeNode(2);
//     root->left->right = new TreeNode(4);
//     root->right->left = new TreeNode(6);
//     root->right->right = new TreeNode(8);
//     int res;
//     assert(getFirstKValue(nullptr, 3) == -1);
//     assert(getFirstKValue(root, 100) == -1);
//     assert(getFirstKValue(root, -1) == -1);
//     assert(getFirstKValue(root, 0) == -1);
//     assert(getFirstKValue(root, 8) == -1);

//     res = getFirstKValue(root, 3);
//     assert(res == 4);
//     res = getFirstKValue(root, 1);
//     assert(res == 2);
//     res = getFirstKValue(root, 2);
//     assert(res == 3);
//     res = getFirstKValue(root, 7);
//     assert(res == 8);
// }
// void test2()
// {
//     TreeNode *root = new TreeNode(5);
//     root->left = new TreeNode(3);
//     root->left->left = new TreeNode(2);
//     int res;

//     res = getFirstKValue(root, 1);
//     assert(res == 2);
//     res = getFirstKValue(root, 2);
//     assert(res == 3);
//     res = getFirstKValue(root, 3);
//     assert(res == 5);
//     res = getFirstKValue(root, 7);
//     assert(res == -1);
// }
// void test3()
// {
//     TreeNode *root = new TreeNode(5);
//     root->right = new TreeNode(7);
//     root->right->right = new TreeNode(8);
//     int res;

//     res = getFirstKValue(root, 1);
//     assert(res == 5);
//     res = getFirstKValue(root, 2);
//     assert(res == 7);
//     res = getFirstKValue(root, 3);
//     assert(res == 8);
//     res = getFirstKValue(root, 7);
//     assert(res == -1);
// }
// int main()
// {
//     test1();
//     test2();
//     test3();
// }
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