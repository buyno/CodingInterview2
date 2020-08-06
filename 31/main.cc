// 给出栈的压入弹出序列
// 判断栈的弹出序列是否可能来自压入序列

// 限制条件：
// 0 <= pushed.length == popped.length <= 1000
// 0 <= pushed[i], popped[i] < 1000
// pushed 是 popped 的排列。

#include <stack>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> temp;
        int popindex = 0;
        int pushindex = 0;
        while (pushindex < pushed.size() && popindex < popped.size() || !temp.empty())
        {
            //找到第一个，之前的先入栈
            while (pushindex < pushed.size() && pushed[pushindex] != popped[popindex])
            {
                temp.push(pushed[pushindex++]);
            }
            if (pushindex == pushed.size())
            {
                return false;
            }
            pushindex++;
            popindex++;
            while (!temp.empty() && temp.top() == popped[popindex])
            {
                popindex++;
                temp.pop();
            }
        }
        if (pushindex < pushed.size() || popindex < popped.size())
        {
            return false;
        }
        return true;
        //找到了之后，先入栈出栈，再判断栈顶的值是不是下一个出栈的值，如果是就直接出栈，如果不是就继续入栈，直到入栈的值等于出栈序列的下一个。然后循环
    }
};

int main()
{
    {
        vector<int> pushed = {1, 2, 3, 4, 5};
        vector<int> popped = {4, 5, 3, 2, 1};
        Solution s;
        auto res = s.validateStackSequences(pushed, popped);
        cout << res << endl;
        assert(res == 1);
    }
    {
        vector<int> pushed = {1, 2, 3, 4, 5};
        vector<int> popped = {5, 4, 3, 2, 1};
        Solution s;
        auto res = s.validateStackSequences(pushed, popped);
        cout << res << endl;
        assert(res == 1);
    }
}
// void test1(){
//     int inquery[] = {1,2,3,4,5};
//     int outquery[] = {6,5,3,2,1};

//     if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
//         printf("length not equal\n");
//         return;
//     }

//     int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
//     assert(res == 0);
// }
// void test2(){
//     int inquery[] = {1,2,3,4,5};
//     int outquery[] = {4,5,3,2,1};

//     if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
//         printf("length not equal\n");
//         return ;
//     }

//     int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
//     assert(res == 1);
// }
// void test3(){
//     int inquery[] = {1,2,3,4,5};
//     int outquery[] = {4,5,3,2};

//     if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
//         printf("length not equal\n");
//         return ;
//     }

//     int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
//     assert(res == 0);
// }
// void test4(){
//     int inquery[] = {1,2,3,4,5};
//     int outquery[] = {4,5,3,1,2};

//     if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
//         printf("length not equal\n");
//         return ;
//     }

//     int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
//     assert(res == 0);
// }
// void test5(){
//     int inquery[] = {1};
//     int outquery[] = {1};

//     if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
//         printf("length not equal\n");
//         return ;
//     }

//     int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
//     assert(res == 1);
// }
// void test6(){
//     int inquery[] = {1};
//     int outquery[] = {2};

//     if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
//         printf("length not equal\n");
//         return ;
//     }

//     int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
//     assert(res == 0);
// }
// void test7(){
//     int res = isQuery(nullptr,nullptr,2);
//     assert(res == 0);

//     int inquery[] = {1,2,3,4,5};
//     int outquery[] = {4,5,3,1,2};
//     res = isQuery(inquery,outquery,0);
//     assert(res == 0);
// }
// int main(){
//     test1();
//     test2();
//     test3();
//     test4();
//     test5();
//     test6();
//     test7();

// }