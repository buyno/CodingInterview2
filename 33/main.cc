// 二叉搜索树的后序遍历序列

// root根节点是后序遍历序列的最后一位，并且左子树的值都比root的值小，右子树的值都比root的值大

#include <stdio.h>

int isPostOrderSequence(int *nums,int start,int end){
    if(start >= end){
        return 1;
    }
    int endvalue = nums[end];
    int it = start;
    while(nums[it] < endvalue){
        it++;
    }
    for(int i = it;i < end;i++){
        if(nums[i] < endvalue){
            return 0;
        }
    }
    return isPostOrderSequence(nums,start,it-1) && isPostOrderSequence(nums,it,end-1);
}
int isPostOrderSequence(int *nums,int length){
    if(nums == nullptr){
        return 0;
    }
    return isPostOrderSequence(nums,0,length-1);
}
int main(){
    // int nums[] = {5,7,6,9,11,10,8};
    // int nums[] = {7,4,6,5};
    // int nums[] = {1};
    // int nums[] = {1,2};
    // int nums[] = {9,11,10,8};
    // int nums[] = {11,10,8};
    // int nums[] = {5,6,8};
    int *nums = nullptr;
    int length = sizeof(nums)/sizeof(nums[0]);
    int res = isPostOrderSequence(nums,length);
    printf("%d\n",res);
}