//0-n-1，n个数字围城一圈，从0开始，每m个数就去掉一个，问最后剩下的数字是？
// 比如n=5，m = 3，那么删掉的序列是2，0，4，1，返回3

// 1）int数组保存结果
// 2）list链表
// 3）数学方法
#include <stdio.h>
#include <assert.h>
// // 每个数要m次，O(mn)
// int lastNumber(int n, int m)
// {
//     if (n <= 0 || m <= 0)
//     {
//         return -1;
//     }
//     int data[n];
//     for (int i = 0; i < n; i++)
//         data[i] = 0;
//     int outcount = 0;
//     int mcount = 0;
//     int index = 0;
//     while (outcount < n - 1)
//     {
//         if (data[index] == 0)
//         {
//             if (++mcount == m)
//             {

//                 outcount++;
//                 mcount = 0;
//                 data[index] = 1;
//             }
//         }
//         index++;
//         index = index % n;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (data[i] == 0)
//         {
//             printf("%d\n", i);
//             return i;
//         }
//     }
//     return -1;
// }
// int main()
// {
//     int n = 5;
//     int m = 3;
//     int res;
//     res = lastNumber(n, m);
//     assert(res == 3);
//     assert(lastNumber(5, 2) == 2);
//     assert(lastNumber(5, 3) == 3);
//     assert(lastNumber(5, 5) == 1);
//     assert(lastNumber(5, 6) == 3);
//     assert(lastNumber(6, 6) == 3);
//     assert(lastNumber(6, 7) == 4);
//     assert(lastNumber(0, 2) == -1);
//     assert(lastNumber(4000, 997) == 1027);
// }
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        list<int> data;
        }
};
int main()
{
    Solution s;
    int res = s.lastRemaining(5, 3);
    cout << res << endl;
    res = s.lastRemaining(10, 17);
    cout << res << endl;
    {
        Solution s;
        int res = s.lastRemaining(1, 1);
        cout << res << endl;
    }
    {
        Solution s;
        int res = s.lastRemaining(1, 3);
        cout << res << endl;
    }
    {
        Solution s;
        int res = s.lastRemaining(3, 1);
        cout << res << endl;
    }
}