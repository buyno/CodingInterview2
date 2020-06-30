//数组中数字出现的次数
// 一个整数数组中除了两个数字之外，其他数字都出现了两次，找出这两个数字。要求时间复杂度O(n),空间复杂度O(1)
// 出现三次相当于一次

// 1)两层循环O(n*n)
// 2)利用异或的特性，相同的值为0，不同为1

#include <stdio.h>
#include <assert.h>
// O(n*n)
int findTwoNumber_1(int *data, int length, int &num1, int &num2)
{
    if (data == nullptr || length <= 0)
    {
        return -1;
    }
    int foundone = 0;
    for (int i = 0; i < length; i++)
    {
        int times = 1;
        int j;
        for (j = 0; j < length; j++)
        {
            if (i != j && data[i] == data[j])
            {
                times++;
            }
        }
        if (times % 2 == 1)
        {
            if (foundone == 0)
            {
                num1 = data[i];
                foundone++;
            }
            else if (data[i] != num1)
            {
                num2 = data[i];
            }
        }
    }

    return 0;
}
// O(n)
int findTwoNumber_2(int *data, int length, int &num1, int &num2)
{
    if (data == nullptr || length <= 0)
    {
        return -1;
    }
    int all = 0;
    for (int i = 0; i < length; i++)
    {
        all = all ^ data[i];
    }
    int index = 0;
    //找到第一个为1的位的index，根据这一位对原数组进行分组，这样两个不同的数一定被分到不同的组，相同的数一定分到同一组
    while (((all & 1) == 0))
    {
        all = all >> 1;
        index++;
    }
    num1 = 0;
    num2 = 0;
    for (int i = 0; i < length; i++)
    {
        //判断数在第index为是否唯一来分组
        if (data[i] & (1 << index))
        {
            num1 = num1 ^ data[i];
        }
        else
        {
            num2 = num2 ^ data[i];
        }
    }
    return 0;
}
void test1()
{
    int length = 8;
    int *data = new int[length]{2, 4, 3, 6, 3, 2, 5, 5};

    int res1, res2;
    int res;
    res = findTwoNumber_1(data, length, res1, res2);
    assert(res == 0 && res1 == 4 && res2 == 6);
    data[1] = 2;
    res = findTwoNumber_1(data, length, res1, res2);
    assert(res == 0 && res1 == 2 && res2 == 6);

    assert(findTwoNumber_1(nullptr, 10, res1, res2) == -1);
    assert(findTwoNumber_1(data, -10, res1, res2) == -1);

    delete[] data;
    data = new int[length]{2, 0, 3, 6, 3, 2, 5, 5};
    res = findTwoNumber_1(data, length, res1, res2);
    assert(res == 0 && res1 == 0 && res2 == 6);
    delete[] data;
    data = new int[length]{2, -10, 3, 6, 3, 2, 5, 5};
    res = findTwoNumber_1(data, length, res1, res2);
    assert(res == 0 && res1 == -10 && res2 == 6);
    delete[] data;
    data = new int[length]{0, 0, 3, 6, 3, 0, 5, 5};
    res = findTwoNumber_1(data, length, res1, res2);
    assert(res == 0 && res1 == 0 && res2 == 6);
    delete[] data;
    data = new int[length]{2, 2, 3, 6, 3, 2, 5, 5};
    res = findTwoNumber_1(data, length, res1, res2);
    assert(res == 0 && res1 == 2 && res2 == 6);
    delete[] data;
    data = new int[length]{6, -10, 3, -10, 3, -10, 5, 5};
    res = findTwoNumber_1(data, length, res1, res2);
    assert(res == 0 && res1 == 6 && res2 == -10);
    delete[] data;
    {
        int res1 = 6, res2 = 0;
        data = new int[length]{2, 2, 6, 3, 3, 3, 5, 5};
        res = findTwoNumber_1(data, length, res1, res2);
        assert(res == 0 && res1 == 6 && res2 == 3);
        delete[] data;
    }

    //不会出现这种情况,一定是满足a+b+(c+...)*2
    // data[1] = 2;
    // assert(findTwoNumber_1(data, length, res1, res2) == -1);
    // delete[] data;
    // length = 7;
    // data = new int[length]{2, 3, 6, 3, 2, 5, 5};
    // assert(findTwoNumber_1(data, length, res1, res2) == -1);
    // delete[] data;
    // length = 9;
    // data = new int[length]{2, 3, 4, 6, 3, 2, 5, 7, 5};
    // assert(findTwoNumber_1(data, length, res1, res2) == -1);
    // delete[] data;
}
void test2()
{
    int length = 8;
    int *data = new int[length]{2, 4, 3, 6, 3, 2, 5, 5};

    int res1, res2;
    int res;
    res = findTwoNumber_2(data, length, res1, res2);

    assert(res == 0 && res1 == 6 && res2 == 4);
    data[1] = 2;
    res = findTwoNumber_2(data, length, res1, res2);

    assert(res == 0 && res1 == 6 && res2 == 2);

    assert(findTwoNumber_2(nullptr, 10, res1, res2) == -1);
    assert(findTwoNumber_2(data, -10, res1, res2) == -1);

    delete[] data;
    data = new int[length]{2, 0, 3, 6, 3, 2, 5, 5};
    res = findTwoNumber_2(data, length, res1, res2);
    assert(res == 0 && res1 == 6 && res2 == 0);
    delete[] data;
    data = new int[length]{2, -10, 3, 6, 3, 2, 5, 5};
    res = findTwoNumber_2(data, length, res1, res2);
    assert(res == 0 && res1 == -10 && res2 == 6);
    delete[] data;
    data = new int[length]{0, 0, 3, 6, 3, 0, 5, 5};
    res = findTwoNumber_2(data, length, res1, res2);
    assert(res == 0 && res1 == 6 && res2 == 0);
    delete[] data;
    data = new int[length]{2, 2, 3, 6, 3, 2, 5, 5};
    res = findTwoNumber_2(data, length, res1, res2);
    assert(res == 0 && res1 == 6 && res2 == 2);
    delete[] data;
    data = new int[length]{-10, -10, 3, 6, 3, -10, 5, 5};
    res = findTwoNumber_2(data, length, res1, res2);
    assert(res == 0 && res1 == -10 && res2 == 6);
    delete[] data;
}
int main()
{
    test1();

    test2();
}