// 复杂链表的复制

#include <map>
#include <assert.h>
using namespace std;

struct ComplexListNode{
    int m_nValue;
    ComplexListNode *m_pNext;
    ComplexListNode *m_pSibling;
    ComplexListNode():m_nValue(0){}
    ComplexListNode(int n):m_nValue(n){}
};
// 时间复杂度O(n^2)
ComplexListNode *copyComplexListNode1(ComplexListNode *root){
    auto it = root;
    ComplexListNode *newRoot = nullptr;
    auto newIt = newRoot;
    while(it){
        if(newRoot == nullptr){
            newRoot = new ComplexListNode(it->m_nValue);
            newIt = newRoot;
            it = it->m_pNext;
        }else{
            newIt->m_pNext = new ComplexListNode(it->m_nValue);
            newIt = newIt->m_pNext;
            it = it->m_pNext;
        }
        
    }
    it = root;
    newIt = newRoot;
    while(it){
        if(it->m_pSibling){
            auto oldforsibling = root;
            auto newforsibling = newRoot;
            while(oldforsibling){
                if(it->m_pSibling == oldforsibling){
                    newIt->m_pSibling = newforsibling;
                    break;
                }
                oldforsibling = oldforsibling->m_pNext;
                newforsibling = newforsibling->m_pNext;

            }
        }
        it = it->m_pNext;
        newIt = newIt->m_pNext;
    }
    return newRoot;
}
// 时间复杂度O(n)
ComplexListNode *copyComplexListNode2(ComplexListNode *root){

    auto it = root;
    ComplexListNode *newRoot = nullptr;
    auto newIt = newRoot;
    map<ComplexListNode *,ComplexListNode *> nodeToNode;
    while(it){
        if(newRoot == nullptr){
            newRoot = new ComplexListNode(it->m_nValue);
            nodeToNode[it] = newRoot;
            newIt = newRoot;
            it = it->m_pNext;
        }else{
            newIt->m_pNext = new ComplexListNode(it->m_nValue);
            nodeToNode[it] = newIt->m_pNext;
            newIt = newIt->m_pNext;
            it = it->m_pNext;
        }
        
    }
    it = root;
    newIt = newRoot;
    while(it){
        if(it->m_pSibling){
            newIt->m_pSibling = nodeToNode[it->m_pSibling];
        }
        it = it->m_pNext;
        newIt = newIt->m_pNext;
    }
    return newRoot;
}

void test1(){
    ComplexListNode *root = new ComplexListNode(10);//a
    ComplexListNode * b = root->m_pNext = new ComplexListNode(11);//b
    ComplexListNode * c = root->m_pNext->m_pNext = new ComplexListNode(12);//c
    ComplexListNode * d = root->m_pNext->m_pNext->m_pNext = new ComplexListNode(13);//d
    ComplexListNode * e = root->m_pNext->m_pNext->m_pNext->m_pNext = new ComplexListNode(14);//e

    root->m_pSibling = c;
    b->m_pSibling = e;
    d->m_pSibling = b;

    ComplexListNode *res1 = copyComplexListNode1(root);
    ComplexListNode *res2 = copyComplexListNode2(root);

    assert(res1->m_nValue == 10);
    assert(res1->m_pNext->m_nValue == 11);
    assert(res1->m_pNext->m_pNext->m_nValue == 12);
    assert(res1->m_pNext->m_pNext->m_pNext->m_nValue == 13);
    assert(res1->m_pNext->m_pNext->m_pNext->m_pNext->m_nValue == 14);
    assert(res1->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext == nullptr);
    assert(res1->m_pSibling == res1->m_pNext->m_pNext);
    assert(res1->m_pNext->m_pSibling == res1->m_pNext->m_pNext->m_pNext->m_pNext);
    assert(res1->m_pNext->m_pNext->m_pNext->m_pSibling == res1->m_pNext);

    assert(res2->m_nValue == 10);
    assert(res2->m_pNext->m_nValue == 11);
    assert(res2->m_pNext->m_pNext->m_nValue == 12);
    assert(res2->m_pNext->m_pNext->m_pNext->m_nValue == 13);
    assert(res2->m_pNext->m_pNext->m_pNext->m_pNext->m_nValue == 14);
    assert(res2->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext == nullptr);
    assert(res2->m_pSibling == res2->m_pNext->m_pNext);
    assert(res2->m_pNext->m_pSibling == res2->m_pNext->m_pNext->m_pNext->m_pNext);
    assert(res2->m_pNext->m_pNext->m_pNext->m_pSibling == res2->m_pNext);
}
//指向自己
void test2(){
    ComplexListNode *root = new ComplexListNode(10);//a
    ComplexListNode * b = root->m_pNext = new ComplexListNode(11);//b
    ComplexListNode * c = root->m_pNext->m_pNext = new ComplexListNode(12);//c
    ComplexListNode * d = root->m_pNext->m_pNext->m_pNext = new ComplexListNode(13);//d
    ComplexListNode * e = root->m_pNext->m_pNext->m_pNext->m_pNext = new ComplexListNode(14);//e

    b->m_pSibling = b;

    ComplexListNode *res1 = copyComplexListNode1(root);
    ComplexListNode *res2 = copyComplexListNode2(root);

    assert(res1->m_nValue == 10);
    assert(res1->m_pNext->m_nValue == 11);
    assert(res1->m_pNext->m_pNext->m_nValue == 12);
    assert(res1->m_pNext->m_pNext->m_pNext->m_nValue == 13);
    assert(res1->m_pNext->m_pNext->m_pNext->m_pNext->m_nValue == 14);
    assert(res1->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext == nullptr);
    assert(res1->m_pNext->m_pSibling == res1->m_pNext);

    assert(res2->m_nValue == 10);
    assert(res2->m_pNext->m_nValue == 11);
    assert(res2->m_pNext->m_pNext->m_nValue == 12);
    assert(res2->m_pNext->m_pNext->m_pNext->m_nValue == 13);
    assert(res2->m_pNext->m_pNext->m_pNext->m_pNext->m_nValue == 14);
    assert(res2->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext == nullptr);
    assert(res2->m_pNext->m_pSibling == res2->m_pNext);
}
//循环指向
void test3(){
    ComplexListNode *root = new ComplexListNode(10);//a
    ComplexListNode * b = root->m_pNext = new ComplexListNode(11);//b
    ComplexListNode * c = root->m_pNext->m_pNext = new ComplexListNode(12);//c
    ComplexListNode * d = root->m_pNext->m_pNext->m_pNext = new ComplexListNode(13);//d
    ComplexListNode * e = root->m_pNext->m_pNext->m_pNext->m_pNext = new ComplexListNode(14);//e

    b->m_pSibling = d;
    d->m_pSibling = b;

    ComplexListNode *res1 = copyComplexListNode1(root);
    ComplexListNode *res2 = copyComplexListNode2(root);

    assert(res1->m_nValue == 10);
    assert(res1->m_pNext->m_nValue == 11);
    assert(res1->m_pNext->m_pNext->m_nValue == 12);
    assert(res1->m_pNext->m_pNext->m_pNext->m_nValue == 13);
    assert(res1->m_pNext->m_pNext->m_pNext->m_pNext->m_nValue == 14);
    assert(res1->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext == nullptr);
    assert(res1->m_pNext->m_pSibling == res1->m_pNext->m_pNext->m_pNext);
    assert(res1->m_pNext->m_pNext->m_pNext->m_pSibling = res1->m_pNext);

    assert(res2->m_nValue == 10);
    assert(res2->m_pNext->m_nValue == 11);
    assert(res2->m_pNext->m_pNext->m_nValue == 12);
    assert(res2->m_pNext->m_pNext->m_pNext->m_nValue == 13);
    assert(res2->m_pNext->m_pNext->m_pNext->m_pNext->m_nValue == 14);
    assert(res2->m_pNext->m_pNext->m_pNext->m_pNext->m_pNext == nullptr);
    assert(res2->m_pNext->m_pSibling == res2->m_pNext->m_pNext->m_pNext);
    assert(res2->m_pNext->m_pNext->m_pNext->m_pSibling = res2->m_pNext); 
}
void test4(){
    ComplexListNode *root = new ComplexListNode(10);//a

    root->m_pSibling = root;

    ComplexListNode *res1 = copyComplexListNode1(root);
    ComplexListNode *res2 = copyComplexListNode2(root);

    assert(res1->m_nValue == 10);
    assert(res1->m_pSibling == res1);

    assert(res2->m_nValue == 10);
    assert(res2->m_pSibling == res2);
}
void test5(){
    ComplexListNode *res1;
    ComplexListNode *res2;
    res1 = copyComplexListNode1(nullptr);
    assert(res1 == nullptr);
    res2 = copyComplexListNode2(nullptr);
    assert(res2 == nullptr);
}
int main(){
    test1();
    test2();
    test3();
    test5();

}