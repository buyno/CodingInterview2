// 数字序列中某一位的数字,从0开始记位
// 序列：012345678910111213141516171819202122232425...
#include <assert.h>
#include <stdio.h>
#include <cmath>

int getNum(int k)
{
    if (k < 10)
    {
        return k;
    }
    int need = k - 10; //记录还需要的位数
    // 10,90*2,900*3,9000*4
    int mark = 10; // 循环终止的条件
    int i = 1;     // 记录当前数字的位数，实际为i+1位，比如2位数/3位数
    while (mark < k)
    {
        int count = 9 * pow(10, i) * (i + 1); //两位数有90*2位，三位数有900*3位
        // 如果需要的位已经被满足，终止循环
        if (need < count)
        {
            break;
        }
        need = need - count;
        mark += count;
        i++;
    }
    //循环结束的时候，need表示在当前(i+1)位数的序列中需要进need位
    //i+1位数的第need个
    int res = pow(10, i) + need / (i + 1);
    int index = i + 1 - need % (i + 1) - 1; //低位到高位的第index个
    for (int i = 0; i < index; i++)
    {
        res = res / 10;
    }
    return res % 10;
}
int main()
{
    int k;

    k = 0;
    assert(getNum(k) == 0);
    k = 1;
    assert(getNum(k) == 1);
    k = 9;
    assert(getNum(k) == 9);
    k = 10; //1
    assert(getNum(k) == 1);
    k = 11; //0
    assert(getNum(k) == 0);
    k = 12; //1
    assert(getNum(k) == 1);
    k = 13; //1
    assert(getNum(k) == 1);
    k = 19;
    assert(getNum(k) == 4);
    k = 189;
    assert(getNum(k) == 9);
    k = 190;
    assert(getNum(k) == 1);
    k = 1000;
    assert(getNum(k) == 3);
    k = 1001;
    assert(getNum(k) == 7);
    k = 1002;
    assert(getNum(k) == 0);
}