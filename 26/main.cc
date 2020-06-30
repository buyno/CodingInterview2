//https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// #include
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
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr || A == nullptr)
        {
            return false;
        }
        if (A->val == B->val)
        {
            if (isSubStructure_helper(A, B))
            {
                return true;
            }
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool isSubStructure_helper(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr)
        {
            return true;
        }
        if (A == nullptr)
        {
            return false;
        }
        if (A->val == B->val)
        {
            return isSubStructure_helper(A->left, B->left) && isSubStructure_helper(A->right, B->right);
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    TreeNode *A = nullptr;
    TreeNode *B;
    Solution s;
    // A = new TreeNode(3);
    // A->left = new TreeNode(4);
    // A->right = new TreeNode(5);
    // A->left->left = new TreeNode(1);
    // A->left->right = new TreeNode(2);

    // B = new TreeNode(4);
    // B->left = new TreeNode(1);

    // assert(s.isSubStructure(A, B) == true);

    // A = new TreeNode(1);
    // A->left = new TreeNode(2);
    // A->right = new TreeNode(3);
    // A->left->left = new TreeNode(4);
    // B = new TreeNode(3);
    // B->left = new TreeNode(1);
    // assert(s.isSubStructure(A, B) == true);

    // A = new TreeNode(-1);
    // A->left = new TreeNode(3);
    // A->right = new TreeNode(2);
    // A->left->left = new TreeNode(0);
    // B = nullptr;
    // assert(s.isSubStructure(A, B) == false);

    // A = new TreeNode(4);
    // A->left = new TreeNode(2);
    // A->right = new TreeNode(3);
    // A->left->left = new TreeNode(4);
    // A->left->right = new TreeNode(5);
    // A->right->left = new TreeNode(6);
    // A->right->right = new TreeNode(7);
    // A->left->left->left = new TreeNode(8);
    // A->left->left->right = new TreeNode(9);
    // B = new TreeNode(2);
    // B->right = new TreeNode(8);
    // B->left = new TreeNode(9);
    // assert(s.isSubStructure(A, B) == true);

    A = new TreeNode(1);
    A->left = new TreeNode(0);
    A->right = new TreeNode(1);
    A->left->left = new TreeNode(-4);
    A->left->right = new TreeNode(-3);
    B = new TreeNode(1);
    B->left = new TreeNode(-4);
    s.isSubStructure(A, B);
    assert(s.isSubStructure(A, B) == false);
}