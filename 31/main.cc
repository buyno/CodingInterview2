// 栈的压入弹出序列
// 判断栈的弹出序列是否可能来自压入序列
#include <stack>
#include <stdio.h>
#include <assert.h>

using namespace std;

int isQuery(int *inquery,int *outquery,int length){
    if(!inquery || !outquery || length<1){
        return 0;
    }
    stack<int> nums;

    int mark_outquery = 0;
    int mark_inquery = 0;
    for(;mark_outquery < length;mark_outquery++){
        // 看栈顶元素是否与出栈序列第一个是否相同，
        //     如果相同，直接出栈，找下一个出栈序列；
        //     如果不同，就依次找入栈序列中是否有相等元素，如果不等，就将其入栈，再找入栈序列的笑一个，
        //                                             如果相等,表示找到了，就直接出栈入栈，再找入栈序列的下一个；
        // 如果找到入栈序列的末尾也没找到，并且栈顶元素也不相同，就表示序列不符合
        // 如果找到出栈序列的末尾，并且栈不为空，那么表示序列符合
        if(!nums.empty() && outquery[mark_outquery] == nums.top()){
            nums.pop();
            continue;
        // }else if(mark_inquery >= length){

        }else{

            while(mark_inquery < length && inquery[mark_inquery] != outquery[mark_outquery]){
                nums.push(inquery[mark_inquery]);
                mark_inquery++;
            }
            //如果找到末尾都还没找到，那就是不符合
            if(mark_inquery >= length){
                break;
            }else{
                nums.push(inquery[mark_inquery]);
                nums.pop();
                mark_inquery++;
            }

        }
    }
    // mark_outquery == length 表示已经遍历完并且全部已入栈；nums.empty()表示符合且全部已出栈
    if(mark_outquery == length && nums.empty()){
        return 1;
    }else{
        return 0;
    }
}
void test1(){
    int inquery[] = {1,2,3,4,5};
    int outquery[] = {6,5,3,2,1};

    if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
        printf("length not equal\n");
        return;
    }

    int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
    assert(res == 0);
}
void test2(){
    int inquery[] = {1,2,3,4,5};
    int outquery[] = {4,5,3,2,1};

    if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
        printf("length not equal\n");
        return ;
    }

    int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
    assert(res == 1);
}
void test3(){
    int inquery[] = {1,2,3,4,5};
    int outquery[] = {4,5,3,2};

    if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
        printf("length not equal\n");
        return ;
    }

    int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
    assert(res == 0);
}
void test4(){
    int inquery[] = {1,2,3,4,5};
    int outquery[] = {4,5,3,1,2};

    if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
        printf("length not equal\n");
        return ;
    }

    int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
    assert(res == 0);
}
void test5(){
    int inquery[] = {1};
    int outquery[] = {1};

    if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
        printf("length not equal\n");
        return ;
    }

    int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
    assert(res == 1);
}
void test6(){
    int inquery[] = {1};
    int outquery[] = {2};

    if(sizeof(inquery)/sizeof(inquery[0]) != sizeof(outquery)/sizeof(outquery[0])){
        printf("length not equal\n");
        return ;
    }

    int res = isQuery(inquery,outquery,sizeof(outquery)/sizeof(outquery[0]));
    assert(res == 0);
}
void test7(){
    int res = isQuery(nullptr,nullptr,2);
    assert(res == 0);
    
    int inquery[] = {1,2,3,4,5};
    int outquery[] = {4,5,3,1,2};
    res = isQuery(inquery,outquery,0);
    assert(res == 0);
}
int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();


}