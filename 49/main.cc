//丑数
// 因数只包含2，3，5的数称为丑数，求从小到大第1500个丑数。
// 6，8是丑数，14不是。1是第一个丑数
//
// 1,2,3,4,5,6,8,9,10,12,15,16,18,20
// 方法一：除2/3/5，看最后剩下的是否为1
// 方法二：循环，下一个数一定是前面的已知丑数分别*2,*3,*5的最小值
// https://leetcode-cn.com/problems/chou-shu-lcof/solution/chou-shu-ii-qing-xi-de-tui-dao-si-lu-by-mrsate/

#include <assert.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int p2 = 0, p3 = 0, p5 = 0;
        vector<int> data(n);
        data[0] = 1;
        int index = 1;
        while (index < n)
        {
            data[index] = min(data[p2] * 2, min(data[p3] * 3, data[p5] * 5));
            if (data[index] == data[p2] * 2)
                p2++;
            if (data[index] == data[p3] * 3)
                p3++;
            if (data[index] == data[p5] * 5)
                p5++;
            index++;
        }
        return data[n - 1];
    }
};
int main()
{
    {
        Solution s;
        int res = s.nthUglyNumber(1);
        cout << res << endl;
        assert(res == 1);
    }
    {
        Solution s;
        int res = s.nthUglyNumber(10);
        cout << res << endl;
        assert(res == 12);
    }
    {
        Solution s;
        int res = s.nthUglyNumber(100);
        cout << res << endl;
        assert(res == 1536);
    }
}