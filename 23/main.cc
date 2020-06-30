// 链表中环的入口节点

#include "../ListNode.h"
#include <stdio.h>
#include <assert.h>
// 找到某一个环内节点，为了后续计算环包含的节点数
ListNode *findMeetingNode(ListNode *head){
    if(head==nullptr)return nullptr;
    ListNode *pfirst = head;
    ListNode *psecond = head;
    while(psecond->pNext != nullptr){
        pfirst = pfirst->pNext;
        psecond = psecond->pNext;
        if(psecond->pNext!=nullptr){
            psecond = psecond->pNext;
        }else{
            return nullptr;
        }
        if(pfirst == psecond){
            return pfirst;
        }

    }
    return nullptr;
}
// 找到环的入口节点
ListNode *findEnterNode(ListNode *head){
    ListNode *res = findMeetingNode(head);
    if(res != nullptr){
        int circlecount = 1;
        ListNode *start = res;
        while(start->pNext != res){
            circlecount++;
            start = start->pNext;
        }
        ListNode *pfirst = head;
        ListNode *psecond = head;
        for(int i = 0;i<circlecount;i++){
            pfirst = pfirst->pNext;
        }
        while(pfirst != psecond){
            pfirst = pfirst->pNext;
            psecond = psecond->pNext;
        }
        return pfirst;
    }else{
        // printf("no circle\n");
        return nullptr;
    }
}
//       ↓--------↑
// 1->2->3->4->5->6
void Test1(){
    ListNode *head = nullptr;
    addToTail(&head,1);
    addToTail(&head,2);
    addToTail(&head,3);
    addToTail(&head,4);
    addToTail(&head,5);
    addToTail(&head,6);
    ListNode *tail = head;
    ListNode *pthird = nullptr;
    while(tail->pNext){
        if(tail->value == 3)pthird = tail;
        tail = tail->pNext;
    }
    tail->pNext = pthird;

    ListNode *res = findEnterNode(head);
    assert(res->value == 3);
}
// ↓--↑
// 1->2
void Test2(){
    ListNode *head = nullptr;
    addToTail(&head,1);
    addToTail(&head,2);
    head->pNext->pNext = head;
    
    ListNode *res = findEnterNode(head);
    assert(res->value == 1);
}
// ↓--↑
// 1
void Test3(){
    ListNode *head = nullptr;
    addToTail(&head,1);
    head->pNext = head;
    
    ListNode *res = findEnterNode(head);
    assert(res->value == 1);
}
// 
// 1->2->nullptr
void Test4(){
    ListNode *head = nullptr;
    addToTail(&head,1);
    addToTail(&head,2);
    
    ListNode *res = findEnterNode(head);
    assert(res == nullptr);
}
// 
// 1->nullptr
void Test5(){
    ListNode *head = nullptr;
    addToTail(&head,1);
    
    ListNode *res = findEnterNode(head);
    assert(res == nullptr);
}
// ↓--------------↑
// 1->2->3->4->5->6
void Test6(){
    ListNode *head = nullptr;
    addToTail(&head,1);
    addToTail(&head,2);
    addToTail(&head,3);
    addToTail(&head,4);
    addToTail(&head,5);
    addToTail(&head,6);
    ListNode *tail = head;
    // ListNode *pthird = nullptr;
    while(tail->pNext){
        // if(tail->value == 3)pthird = tail;
        tail = tail->pNext;
    }
    tail->pNext = head;

    ListNode *res = findEnterNode(head);
    assert(res->value == 1);
}
//                ↓↑
// 1->2->3->4->5->6
void Test7(){
    ListNode *head = nullptr;
    addToTail(&head,1);
    addToTail(&head,2);
    addToTail(&head,3);
    addToTail(&head,4);
    addToTail(&head,5);
    addToTail(&head,6);
    ListNode *tail = head;
    // ListNode *pthird = nullptr;
    while(tail->pNext){
        // if(tail->value == 3)pthird = tail;
        tail = tail->pNext;
    }
    tail->pNext = tail;

    ListNode *res = findEnterNode(head);
    assert(res->value == 6);
}
//       
// 1->2->3->4->5->6->nullptr
void Test8(){
    ListNode *head = nullptr;
    addToTail(&head,1);
    addToTail(&head,2);
    addToTail(&head,3);
    addToTail(&head,4);
    addToTail(&head,5);
    addToTail(&head,6);


    ListNode *res = findEnterNode(head);
    assert(res == nullptr);
}
int main(){
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
}