// 链表中倒数第k个数
// 从倒数第1开始，比如{1，2，3，4，5}的倒数第二个数是4

// 
#include "../ListNode.h"
#include <stdio.h>

int findlastk(ListNode *head,int k){
    // 从倒数第1开始，所以k=0时应该是错误
    if(head == nullptr || k==0){
        return -1;
    }
    ListNode *first = head;
    ListNode *second = head;
    for(int i =0;i<k-1;i++){
        //为了k大于链表长度的情况
        if(second->pNext != nullptr){
            second = second->pNext;
        }else{
            return -1;
        }
    }
    while(second->pNext){
        first = first->pNext;
        second = second->pNext;
    }
    return first->value;
}
int main(){
    int k = 0;//5,6,10
    ListNode *head = nullptr;
    addToTail(&head,1);
    addToTail(&head,2);
    addToTail(&head,3);
    addToTail(&head,4);
    addToTail(&head,5);
    addToTail(&head,6);
    printListNode(head);
    int res = findlastk(head,k);
    printf("result:%d\n",res);
}