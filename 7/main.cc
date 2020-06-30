//利用中序遍历序列和前序遍历序列构造二叉树
#include "../Tree.h"
#include <stdio.h>
#include <assert.h>

int findIndexInPreorder(int preorder[],int length,int value){
    for(int i = 0;i<length;i++){
        if(preorder[i] == value){
            return i;
        }
    }
    return -1;
}
void buildTree(int preorder[],int inorder[],int length,int inorderstart,int inorderend,int leftOrRight,TreeNode **head){
    int rootIndex = length;
    int rootIndexInInroder;
    for(int i = inorderstart;i<=inorderend;i++){
        int index = findIndexInPreorder(preorder,length,inorder[i]);
        if(index < rootIndex){
            rootIndex = index;
            rootIndexInInroder = i;
        }
    }
    if(leftOrRight == 0){
        (*head)->left = new TreeNode();
        (*head)->left->value = preorder[rootIndex];
        if(rootIndexInInroder > inorderstart)
            buildTree(preorder,inorder,length,inorderstart,rootIndexInInroder-1,0,&((*head)->left));
        if(rootIndexInInroder < inorderend)
            buildTree(preorder,inorder,length,rootIndexInInroder+1,inorderend,1,&((*head)->left));
    }else{
        (*head)->right = new TreeNode();
        (*head)->right->value = preorder[rootIndex];
        if(rootIndexInInroder > inorderstart){
            buildTree(preorder,inorder,length,inorderstart,rootIndexInInroder-1,0,&((*head)->right));
        }
        if(rootIndexInInroder < inorderend){
            buildTree(preorder,inorder,length,rootIndexInInroder+1,inorderend,1,&((*head)->right));
        }
    }
}

void construct(int preorder[],int length,int inorder[],TreeNode **head){
    if(!(*head) || (!preorder) || (!inorder)){
        return;
    } 
    int rootValue = preorder[0];
    int p1 = 0;
    for(int i = 0;i<length;i++){
        if(inorder[i] == rootValue){
            p1 = i;
            break;
        }
    }
    *head = new TreeNode();
    (*head)->value = rootValue;

    if(p1 > 0)
        buildTree(preorder,inorder,length,0,p1-1,0,head);
    if(p1 < length-1)    
        buildTree(preorder,inorder,length,p1+1,length-1,1,head);
    return ;
}
void test1(){
    int preorder[] = {1,2,4,7,3,5,6,8};
    int inorder[] = {4,7,2,1,5,3,8,6};
    TreeNode *head;
    construct(preorder,sizeof(preorder)/sizeof(preorder[0]),inorder,&head);

    assert(head->value == 1);
    assert(head->left->value == 2);
    assert(head->left->left->value == 4);
    assert(head->left->left->right->value == 7);
    assert(head->right->value == 3);
    assert(head->right->left->value == 5);
    assert(head->right->right->value == 6);
    assert(head->right->right->left->value == 8);
    assert(head->left->right == nullptr);
    assert(head->left->left->left == nullptr);
    assert((head->left->left->right->left==nullptr) && (head->left->left->right->right==nullptr));
    assert(head->right->left->left == nullptr);
    assert(head->right->left->right == nullptr);
    assert(head->right->right->right == nullptr);
}
void test2(){
    int *preorder = nullptr;
    int *inorder = nullptr;
    TreeNode *head = nullptr;
    construct(preorder,sizeof(preorder)/sizeof(preorder[0]),inorder,&head);
    assert(head == nullptr);
}
void test3(){
    int preorder[] = {1,2,3,4,5};
    int inorder[] = {1,2,3,4,5};
    TreeNode *head;
    construct(preorder,sizeof(preorder)/sizeof(preorder[0]),inorder,&head);
    assert(head->value == 1);
    assert(head->right->value == 2);
    assert(head->right->right->value == 3);
    assert(head->right->right->right->value == 4);
    assert(head->right->right->right->right->value == 5);
    assert(head->left == nullptr);
}
void test4(){
    int preorder[] = {1,2,3,4,5};
    int inorder[] = {5,4,3,2,1};
    TreeNode *head;
    construct(preorder,sizeof(preorder)/sizeof(preorder[0]),inorder,&head);
    assert(head->value == 1);
    assert(head->left->value == 2);
    assert(head->left->left->value == 3);
    assert(head->left->left->left->value == 4);
    assert(head->left->left->left->left->value == 5);
    assert(head->right == nullptr);
}
void test5(){
    int preorder[] = {1};
    int inorder[] = {1};
    TreeNode *head;
    construct(preorder,sizeof(preorder)/sizeof(preorder[0]),inorder,&head);

    assert(head->value == 1);
    assert(head->left == nullptr);
    assert(head->right == nullptr);
}
void test6(){
    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};
    TreeNode *head;
    construct(preorder,sizeof(preorder)/sizeof(preorder[0]),inorder,&head);
    assert(head->value == 1);
    assert(head->left->value == 2);
    assert(head->right->value == 3);
    assert(head->left->left->value == 4);
    assert(head->left->right->value == 5);
    assert(head->right->left->value == 6);
    assert(head->right->right->value == 7);
}


int main(){
    // test1();
    // test2();
    test3();
    test4();
    test5();
    test6();
}
