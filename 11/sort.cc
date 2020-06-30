// 排序

#include <stdio.h>

//冒泡排序
void bubble_sort(int *nums,int length){
    for(int i=0;i<length-1;i++){
        for(int j = 0;j<length-1-i;j++){
            if(nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }

}
//插入排序
void insert_sort(int nums[],int length){
    
    for(int i = 0;i<length-1;i++){
        int minindex = i;
        for(int j = i+1;j<length;j++){
            if(nums[j] < nums[minindex]){
                minindex = j;
            }
        }
        if(minindex != i){
            int temp = nums[minindex];
            nums[minindex] = nums[i];
            nums[i] = temp;
        }
    }
}
// 归并排序
void merge(int nums[],int start,int end){
    int mid = (start + end)/2;
    int *a = new int[mid - start + 1]();
    int *b = new int[end - mid]();
    for(int i = start;i <= mid;i++){
        a[i-start] = nums[i];
    }
    for(int i = mid+1;i<= end;i++){
        b[i-mid-1] = nums[i];
    }
    int i = start,j = 0,k = 0;
    while((j<=mid-start)&& (k < end - mid)){
        if(a[j] <= b[k]){
            nums[i++] = a[j++];
        }else{
            nums[i++] = b[k++];
        }
    }
    if(j <= mid-start){
        for(int l = j;l<=mid-start;l++){
            nums[i++] = a[l];
        }
    }else{
        for(int l = k;l < end-mid;l++){
            nums[i++] = b[l];
        }
    }

    delete []b;
    delete []a;
}
void merge_sort(int nums[],int start,int end){
    if(end - start > 1){
        int mid = (start+end)/2;
        merge_sort(nums,start,mid);
        merge_sort(nums,mid+1,end);
        merge(nums,start,end);
    }else if(end == start + 1){
        if(nums[start] > nums[end]){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
        }
    }
}
void merge_sort(int nums[],int length){
    merge_sort(nums,0,length-1);
}

int main(){
    int nums[] = {1,15,12,2,43,65,87,3,45,49,4,61,92,5,39,6,7,99,8,90,9};
    // int nums[] = {1,15,12,2,43,65,8};
    // bubble_sort(nums,sizeof(nums)/sizeof(nums[0]));
    // insert_sort(nums,sizeof(nums)/sizeof(nums[0]));
    merge_sort(nums,sizeof(nums)/sizeof(nums[0]));
    for(int x : nums){
        printf("%d ",x);
    }
    printf("\n");
}