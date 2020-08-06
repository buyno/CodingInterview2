// 二叉搜索树的后序遍历序列

// root根节点是后序遍历序列的最后一位，并且左子树的值都比root的值小，右子树的值都比root的值大

#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    bool verifyPostorder(vector<int> &postorder)
    {
        if (postorder.size() == 0)
        {
            return true;
        }
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }
    bool verifyPostorder(vector<int> &postorder, int start, int end)
    {
        if (start >= end)
        {
            return true;
        }
        int midvalue = postorder[end];
        int index = start;
        while (index <= end && postorder[index] < midvalue)
        {
            index++;
        }
        int newstart = index;
        while (index < end)
        {
            if (postorder[index] < postorder[end])
            {
                return false;
            }
            index++;
        }
        return verifyPostorder(postorder, start, newstart - 1) && verifyPostorder(postorder, newstart, end - 1);
    }
};

int main()
{
    {
        vector<int> data = {1, 3, 2, 6, 5};
        Solution s;
        int res = s.verifyPostorder(data);
        assert(res == 1);
    }
    {
        vector<int> data = {1, 6, 3, 2, 5};
        Solution s;
        int res = s.verifyPostorder(data);
        assert(res == 0);
    }
    {
        vector<int> data = {5, 2, -17, -11, 25, 76, 62, 98, 92, 61};
        Solution s;
        int res = s.verifyPostorder(data);
        assert(res == 0);
    }
}
