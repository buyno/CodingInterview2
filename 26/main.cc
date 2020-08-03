//https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
// 树的子结构
// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
#include <stdlib.h>
#include <stdio.h>
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
    bool isSubStructure_helper(TreeNode *A, TreeNode *B)
    {

        if (A && B)
        {

            if (A->val == B->val && isSubStructure_helper(A->left, B->left) && isSubStructure_helper(A->right, B->right))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if (!A && !B)
        {
            return true;
        }
        if (!A && B)
        {
            return false;
        }
        if (A && !B)
        {
            return true;
        }
        return false;
    }
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (!B || !A)
        {
            return false;
        }
        if (isSubStructure_helper(A, B))
        {
            return true;
        }
        else
        {
            return isSubStructure(A->left, B) || isSubStructure(A->right, B);
        }
    }
};
int main()
{
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

        // A = new TreeNode(1);
        // A->left = new TreeNode(0);
        // A->right = new TreeNode(1);
        // A->left->left = new TreeNode(-4);
        // A->left->right = new TreeNode(-3);
        B = new TreeNode(1);
        B->left = new TreeNode(-4);
        s.isSubStructure(A, B);
        assert(s.isSubStructure(A, B) == false);
    }
    {
        TreeNode *A = nullptr;
        TreeNode *B;
        Solution s;
        // A = new TreeNode(3);
        // A->left = new TreeNode(4);
        // A->right = new TreeNode(5);
        // A->left->left = new TreeNode(1);
        // A->left->right = new TreeNode(2);

        B = new TreeNode(4);
        // B->left = new TreeNode(1);

        assert(s.isSubStructure(A, B) == false);
    }
    {
        TreeNode *A;
        TreeNode *B = nullptr;
        Solution s;
        A = new TreeNode(3);
        // A->left = new TreeNode(4);
        // A->right = new TreeNode(5);
        // A->left->left = new TreeNode(1);
        // A->left->right = new TreeNode(2);

        // B = new TreeNode(4);
        // B->left = new TreeNode(1);

        assert(s.isSubStructure(A, B) == false);
    }
    {
        TreeNode *A;
        TreeNode *B = nullptr;
        Solution s;
        A = new TreeNode(3);
        A->left = new TreeNode(4);
        A->right = new TreeNode(5);
        A->left->left = new TreeNode(1);
        A->left->right = new TreeNode(2);

        B = new TreeNode(4);
        B->left = new TreeNode(1);

        assert(s.isSubStructure(A, B) == true);
    }
    {
        TreeNode *A;
        TreeNode *B = nullptr;
        Solution s;
        A = new TreeNode(3);
        A->left = new TreeNode(4);
        A->right = new TreeNode(5);
        A->left->left = new TreeNode(1);
        A->left->right = new TreeNode(2);

        B = new TreeNode(3);
        B->right = new TreeNode(5);

        assert(s.isSubStructure(A, B) == true);
    }
    {
        TreeNode *A;
        TreeNode *B = nullptr;
        Solution s;
        A = new TreeNode(3);
        A->left = new TreeNode(4);
        A->right = new TreeNode(5);
        A->left->left = new TreeNode(1);
        A->left->right = new TreeNode(2);

        B = new TreeNode(3);
        B->right = new TreeNode(5);

        assert(s.isSubStructure(A, B) == true);
    }
    {
        TreeNode *A;
        TreeNode *B = nullptr;
        Solution s;
        A = new TreeNode(10);
        A->left = new TreeNode(12);
        A->right = new TreeNode(6);
        A->left->left = new TreeNode(8);
        A->left->right = new TreeNode(3);
        A->right->left = new TreeNode(11);

        B = new TreeNode(10);
        B->left = new TreeNode(12);
        B->right = new TreeNode(6);
        B->left->left = new TreeNode(8);

        assert(s.isSubStructure(A, B) == true);
    }
    {
        TreeNode *A;
        TreeNode *B = nullptr;
        Solution s;
        A = new TreeNode(1);
        A->left = new TreeNode(0);
        A->right = new TreeNode(1);
        A->left->left = new TreeNode(-4);
        A->left->right = new TreeNode(-3);
        // A->right->left = new TreeNode(11);

        B = new TreeNode(1);
        B->left = new TreeNode(-4);

        assert(s.isSubStructure(A, B) == false);
    }
    {
        TreeNode *A;
        TreeNode *B = nullptr;
        Solution s;
        A = new TreeNode(1);
        A->left = new TreeNode(0);
        A->right = new TreeNode(1);
        A->left->left = new TreeNode(-4);
        A->left->right = new TreeNode(-3);
        // A->right->left = new TreeNode(11);

        B = new TreeNode(0);
        B->left = new TreeNode(-4);

        assert(s.isSubStructure(A, B) == true);
    }
}