// O(1)时间复杂度下，删除链表的一个结点
// 已知头指针和要删除的节点的指针

struct ListNode{
    int m_nValue;
    ListNode *m_pNext;
};

void DeleteNode(ListNode **pListHead,ListNode *pToBeDeleted){
    if(*pListHead == nullptr)return;
    if(pToBeDeleted->m_pNext == nullptr){
        if(*pListHead == pToBeDeleted){
            *pListHead = nullptr;
            delete pToBeDeleted;
            return;
        }
        ListNode *present = *pListHead;
        ListNode *pre = nullptr;
        while(present->m_pNext){
            pre = present;
            present = present->m_pNext;
        }
        pre->m_pNext = nullptr;
        delete pToBeDeleted;
        return ;
    }
    pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
    pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
    delete pToBeDeleted->m_pNext;
}

void main(){

}