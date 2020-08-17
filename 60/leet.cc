#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <math.h>
//循环解法
// 这种方法只使用了2n的空间
// 时间复杂度O(n*n)，空间复杂度O(n)
using namespace std;

class Solution
{
public:
    vector<double> twoSum(int n)
    {
        faces = 6;
        touziNumber = n;
        // vector<double> res;
        int data[2][faces * n + 1];
        for (int i = 0; i < faces * n + 1; i++)
        {
            data[0][i] = 0;
            data[1][i] = 0;
        }
        int flag = 0;
        //掷第一个色子
        for (int i = 1; i <= faces; i++)
        {
            data[flag][i] = 1;
        }
        flag = 1 - flag;
        // 掷第2到最后一个色子
        for (int i = 2; i <= n; i++)
        {
            //第x个色子时，和不可能小于x
            for (int j = 0; j < i; j++)
            {
                data[flag][j] = 0;
            }
            //投剩下的色子，最小值时i，最大值是i*faces
            for (int j = i; j <= i * faces; j++)
            {
                data[flag][j] = 0;
                // 每次投，就往前找六位，求和
                for (int k = 1; k <= faces; k++)
                {
                    if (j - k >= 0)
                    {
                        data[flag][j] += data[1 - flag][j - k];
                    }
                    else
                    {
                        break;
                    }
                }
            }
            flag = 1 - flag;
        }
        vector<double> res;
        double sum = pow(faces, n);
        for (int i = n; i <= n * faces; i++)
        {
            res.push_back(data[1 - flag][i] / sum);
        }
        return res;
    }

    int faces;
    int touziNumber;
};

int main()
{
    {
        Solution s;
        int n = 1;
        vector<double> res = s.twoSum(n);
        for (double d : res)
        {
            cout << d << ",";
        }
        cout << endl;
    }
    {
        Solution s;
        int n = 2;
        vector<double> res = s.twoSum(n);
        for (double d : res)
        {
            cout << d << ",";
        }
        cout << endl;
    }
    {
        Solution s;
        int n = 3;
        vector<double> res = s.twoSum(n);
        for (double d : res)
        {
            cout << d << ",";
        }
        cout << endl;
    }
    {
        Solution s;
        int n = 4;
        vector<double> res = s.twoSum(n);
        for (double d : res)
        {
            cout << d << ",";
        }
        cout << endl;
    }
    // {
    //     Solution s;
    //     int n = 5;
    //     vector<double> res = s.twoSum(n);
    //     for (double d : res)
    //     {
    //         cout << d << ",";
    //     }
    //     cout << endl;
    // }
    // {
    //     Solution s;
    //     int n = 6;
    //     vector<double> res = s.twoSum(n);
    //     for (double d : res)
    //     {
    //         cout << d << ",";
    //     }
    //     cout << endl;
    // }
    // {
    //     Solution s;
    //     int n = 7;
    //     vector<double> res = s.twoSum(n);
    //     for (double d : res)
    //     {
    //         cout << d << ",";
    //     }
    //     cout << endl;
    // }
    // {
    //     Solution s;
    //     int n = 8;
    //     vector<double> res = s.twoSum(n);
    //     for (double d : res)
    //     {
    //         cout << d << ",";
    //     }
    //     cout << endl;
    // }
    // {
    //     Solution s;
    //     int n = 9;
    //     vector<double> res = s.twoSum(n);
    //     for (double d : res)
    //     {
    //         cout << d << ",";
    //     }
    //     cout << endl;
    // }
    // {
    //     Solution s;
    //     int n = 10;
    //     vector<double> res = s.twoSum(n);
    //     for (double d : res)
    //     {
    //         cout << d << ",";
    //     }
    //     cout << endl;
    // }
    // {
    //     Solution s;
    //     int n = 11;
    //     vector<double> res = s.twoSum(n);
    //     for (double d : res)
    //     {
    //         cout << d << ",";
    //     }
    //     cout << endl;
    // }
}