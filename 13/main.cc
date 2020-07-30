// 机器人的运动范围
// :地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

// 机器人从(0,0)开始移动，但是只能移动到坐标为(i,j)，并且i,j各个位的和小于k。
// 比如k=5时，可以移动到(1,4)，不能移动到(1,5)
// 返回可移动的格数，和移动范围的矩阵
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        vector<vector<int>> vec;
        for (int i = 0; i < m; i++)
        {
            vector<int> tmp(n, 0);
            vec.push_back(tmp);
        }
        int x = 0;
        int y = 0;
        int result = 0;
        movingCount(m, n, 0, 0, k, result, vec);
        return result;
    }
    void movingCount(int m, int n, int x, int y, int k, int &result, vector<vector<int>> &vec)
    {
        // if(x < 0 && x >= m && y < 0 && y > n && !vec[x][y]){
        //     return;
        // }
        if (x >= 0 && x < m && y >= 0 && y < n && !vec[x][y] && available(x, y, k))
        {
            vec[x][y] = 1;
            result++;
            movingCount(m, n, x + 1, y, k, result, vec);
            // movingCount(m, n, x - 1, y, k, result, vec);
            // movingCount(m, n, x, y - 1, k, result, vec);
            movingCount(m, n, x, y + 1, k, result, vec);
        }
    }
    int available(int x, int y, int k)
    {
        int temp = 0;
        while (x)
        {
            temp += x % 10;
            x = x / 10;
        }
        while (y)
        {
            temp += y % 10;
            y = y / 10;
        }
        if (temp <= k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    // //正常功能
    // test1();
    // //k<0
    // test2();
    // // m或n == 1
    // test3();
    // test4();
    {
        Solution s;
        int res = s.movingCount(2, 3, 1);
        cout << res << endl;
        assert(res == 3);
    }
    {
        Solution s;
        int res = s.movingCount(3, 1, 0);
        cout << res << endl;
        assert(res == 1);
    }
    {
        Solution s;
        int res = s.movingCount(1, 2, 1);
        cout << res << endl;
        assert(res == 2);
    }
    {
        Solution s;
        int res = s.movingCount(0, 0, 1);
        cout << res << endl;
        assert(res == 0);
    }
    {
        Solution s;
        int res = s.movingCount(16, 16, 4);
        cout << res << endl;
        assert(res == 15);
    }
}