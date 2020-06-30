#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;

class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        // f(n,m)表示总共n个数时剩余的那一个数，f(n-1,m)就是总共n-1个数时剩余的一个数
        // 假设x = f(n-1,m)
        // 那么因为n个数是首先删除的肯定是第m个数，然后剩余n-1个数，就可以递归了
        // 最后剩余的数肯定是从第m个数开始的第x个数
        // 也就是说，x是f(n-1,m)的返回值，f(n,m)是从f(n-1,m)得到的序列中从x开始往后走m步
        // 所以是 f(n,m) = (x+m%n)%n = (f(n-1,m)+m)%n
        if (n == 1)
        {
            return 0;
        }
        int tmp = lastRemaining(n - 1, m);
        // cout << n << "," << m << ",saved:" << (tmp + m) % n << endl;
        return (tmp + m) % n;
    }
};
int main()
{
    Solution s;
    int res = s.lastRemaining(5, 3);
    cout << res << endl;
    assert(res == 3);
}