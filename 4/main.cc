// 二维数组的查找

// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// 给定 target = 5，返回 true。
// 给定 target = 20，返回 false。

#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        // {},{{}}
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        //从左下角开始查找
        int i = matrix.size() - 1;
        int j = 0; //matrix[i].size();
        while (i >= 0 && j <= matrix[i].size() - 1)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] < target)
            {
                j++;
            }
            else
            {
                i--;
            }
        }
        return false;
    }
};
int main()
{
    {
        Solution s;
        vector<vector<int>> matrix;
        int target = 11;
        bool res = s.findNumberIn2DArray(matrix, target);
        cout << res << endl;
        assert(res == false);
    }
    {
        Solution s;
        vector<vector<int>> matrix = {
            {1, 2, 8, 9},
            {2, 4, 9, 12},
            {4, 7, 10, 13},
            {6, 8, 11, 15}};
        int target = 11;
        bool res = s.findNumberIn2DArray(matrix, target);
        cout << res << endl;
        assert(res == true);
    }
    {
        Solution s;
        vector<vector<int>> matrix = {
            {1, 2, 8, 9},
            {2, 4, 9, 12},
            {4, 7, 10, 13},
            {6, 8, 11, 15}};
        int target = 14;
        bool res = s.findNumberIn2DArray(matrix, target);
        cout << res << endl;
        assert(res == false);
    }
    {
        Solution s;
        vector<vector<int>> matrix = {
            {1, 2, 8, 9}};
        int target = 14;
        bool res = s.findNumberIn2DArray(matrix, target);
        cout << res << endl;
        assert(res == false);
    }
    {
        Solution s;
        vector<vector<int>> matrix = {
            {1, 2, 8, 9}};
        int target = 8;
        bool res = s.findNumberIn2DArray(matrix, target);
        cout << res << endl;
        assert(res == true);
    }
    {
        Solution s;
        vector<vector<int>> matrix = {
            {1},
            {2},
            {4},
            {6}};
        int target = 14;
        bool res = s.findNumberIn2DArray(matrix, target);
        cout << res << endl;
        assert(res == false);
    }
    {
        Solution s;
        vector<vector<int>> matrix = {
            {1},
            {2},
            {4},
            {6}};
        int target = 4;
        bool res = s.findNumberIn2DArray(matrix, target);
        cout << res << endl;
        assert(res == true);
    }
}