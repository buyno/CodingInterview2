// 求1+2+...+n,不能使用乘除，for,while,if,else,switch,case,A?B:C

// 1）构造函数，n个对象，静态成员
// 2）虚函数,!!n来分流，
// 3）函数指针，!!n用于分路
#include <stdio.h>

class Test
{
public:
    Test()
    {
        n++;
        sum += n;
    }
    //为了多个测试
    static void Reset()
    {
        sum = 0;
        n = 0;
    }
    static int n;
    static int sum;
};
// 初始化是必须的
int Test::sum = 0;
int Test::n = 0;

//=================================================================
class Test2;
Test2 *array[2];

class Test2
{
public:
    virtual int func(int n)
    {
        return 0;
    }
};
class Test3 : public Test2
{
public:
    int func(int n)
    {
        return array[!!n]->func(n - 1) + n;
    }
};
//====================================================
//作为递归的终止条件
int func2(int n)
{
    return 0;
}
// 递归的主体
int getResult(int n)
{
    // !!n选择执行不同的函数
    int (*myfunc[2])(int) = {func2, getResult};
    return myfunc[!!n](n - 1) + n;
}
int main()
{
    // Test::Reset();
    // int n = 10;
    // Test *te = new Test[n];
    // int res = Test::sum;
    // printf("%d\n", res);
    // delete[] te;
    //=====================================
    // int n = 10;
    // Test2 t1;
    // Test3 t2;
    // array[0] = &t1;
    // array[1] = &t2;
    // Test3 *tt = new Test3();
    // int res = tt->func(n);
    // printf("%d\n", res);
    // delete[] tt;
    //=====================================
    int n = 10;
    int res = getResult(n);
    printf("%d\n", res);
}