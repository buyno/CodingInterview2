// 旋转数组中查找最小的元素
// 旋转：1,2,3,4,5,6 -> 5,6,1,2,3,4
// 1)顺序查找
// 2）类二分查找:比较第0个值与mid值，如果mid更大，说明min在后半部分；如果mid更小，说明min在前半部分
                // 特殊：nullptr，只有一个值，全部递增没有旋转
                //      start/mid/end的值相等时，不能判断min在前面还是后面，转为顺序查找
#include <stdio.h>
#include <assert.h>

int findMin(int nums[],int length){
    if(!nums || (length==0))return -1;
    if(length==1)return nums[0];

    int p1 = 0;
    int p2 = length-1;
    if(nums[p1] < nums[p2]){
        return nums[p1];
    }
    while(p2 - p1 > 1){
        // if(p2-p1==1){
        //     return nums[p2];
        // }
        int mid = (p1 + p2)/2;
        if(nums[p1] == nums[p2] && nums[p1] == nums[mid]){
            int min = nums[p1];
            for(int i =p1+1;i<=p2;i++){
                if(nums[i] < min){
                    min = nums[i];
                }
            }
            return min;
        }
        if(nums[mid] >= nums[p1]){
            p1 = mid;
        }else{
            p2 = mid;
        }   
    }
    if(p2-p1 == 1){
        return nums[p2];
    }
    // printf("%d,%d\n",p1,p2);
    // return nums[p2];
}
void test1(){
    int nums[] = {1,0,1,1,1};
    int res = findMin(nums,sizeof(nums)/sizeof(nums[0]));
    assert(res == 0);

    int *nums2 = nullptr;
    res = findMin(nums,0);
    assert(res == -1);
}
void test2(){
    int nums[] = {1,2,3,4,5};
    int res = findMin(nums,sizeof(nums)/sizeof(nums[0]));
    assert(res == 1);
}
void test3(){
    int nums[] = {3,4,5,1,2};
    int res = findMin(nums,sizeof(nums)/sizeof(nums[0]));
    assert(res == 1);

    int array2[] = {3, 4, 5, 1, 1, 2};
    int res2 = findMin(array2,sizeof(array2)/sizeof(array2[0]));
    assert(res2 == 1);

    int array3[] = {3, 4, 5, 1, 2, 2};
    int res3 = findMin(array3,sizeof(array3)/sizeof(array3[0]));
    assert(res3 == 1);

    int array4[] = {2};
    int res4 = findMin(array4,sizeof(array4)/sizeof(array4[0]));
    assert(res4 == 2); 

    int array5[] = {1,2};
    int res5 = findMin(array5,sizeof(array5)/sizeof(array5[0]));
    assert(res5 == 1);

    int array6[] = {2,1};
    int res6 = findMin(array6,sizeof(array6)/sizeof(array6[0]));
    assert(res6 == 1);
}
int main(){
    test1();
    test2();
    test3();
}