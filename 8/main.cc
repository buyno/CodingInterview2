//二叉树的中序遍历时，某个节点的下一个节点

#include "../utils/Tree.h"
#include "stdio.h"
#include <assert.h>
TreeNode *getLeftestChildNode(TreeNode *node)
{
    TreeNode *res = node;
    while (res->left)
    {
        res = res->left;
    }
    return res;
}

TreeNode *getNext(TreeNode *node)
{
    if (!node)
        return nullptr;
    // 如果有右子树，那么下一个是右子树中最左边的节点
    // 如果没有右子树，并且是左子节点，下一个就是他的父节点
    // 如果没有右子树，并且不是左子节点，那就向父节点查找，直到找到某个父节点是其父节点的左子节点时，这个父节就是下一个
    // 如果都没有找到，就没有后续节点
    if (node->right)
    {
        TreeNode *temp = getLeftestChildNode(node->right);
        return temp;
    }
    else if (node->parent && node->parent->left == node)
    {
        return node->parent;
    }
    else
    {
        TreeNode *p = node->parent;
        while (p)
        {
            if (p->parent && p->parent->left == p)
            {
                return p->parent;
            }
            p = p->parent;
        }
        return nullptr;
    }
    return nullptr;
    // return head->left->right->left;
}
// 普通二叉树
void test1()
{
    TreeNode *head = new TreeNode();
    TreeNode *a = head;
    TreeNode *b = new TreeNode();
    TreeNode *c = new TreeNode();
    TreeNode *d = new TreeNode();
    TreeNode *e = new TreeNode();
    TreeNode *f = new TreeNode();
    TreeNode *g = new TreeNode();
    TreeNode *h = new TreeNode();
    TreeNode *i = new TreeNode();
    head->left = b;
    head->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    e->left = h;
    e->right = i;
    b->parent = c->parent = a;
    d->parent = e->parent = b;
    f->parent = g->parent = c;
    h->parent = i->parent = e;

    TreeNode *res = getNext(b);
    assert(res == h);
    res = getNext(a);
    assert(res == f);
    res = getNext(b);
    assert(res == h);
    res = getNext(c);
    assert(res == g);
    res = getNext(d);
    assert(res == b);
    res = getNext(e);
    assert(res == i);
    res = getNext(f);
    assert(res == c);
    res = getNext(g);
    assert(res == nullptr);
    res = getNext(h);
    assert(res == e);
    res = getNext(i);
    assert(res == a);
}
// 满二叉树
void test2()
{
    TreeNode *head = new TreeNode();
    TreeNode *a = head;
    TreeNode *b = new TreeNode();
    TreeNode *c = new TreeNode();
    TreeNode *d = new TreeNode();
    TreeNode *e = new TreeNode();
    TreeNode *f = new TreeNode();
    TreeNode *g = new TreeNode();
    head->left = b;
    head->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    b->parent = c->parent = a;
    d->parent = e->parent = b;
    f->parent = g->parent = c;

    TreeNode *res = getNext(a);
    assert(res == f);
    res = getNext(b);
    assert(res == e);
    res = getNext(c);
    assert(res == g);
    res = getNext(d);
    assert(res == b);
    res = getNext(e);
    assert(res == a);
    res = getNext(f);
    assert(res == c);
    res = getNext(g);
    assert(res == nullptr);
}
//完全二叉树
void test3()
{
    TreeNode *head = new TreeNode();
    TreeNode *a = head;
    TreeNode *b = new TreeNode();
    TreeNode *c = new TreeNode();
    TreeNode *d = new TreeNode();
    TreeNode *e = new TreeNode();
    TreeNode *f = new TreeNode();
    head->left = b;
    head->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    b->parent = c->parent = a;
    d->parent = e->parent = b;
    f->parent = c;

    TreeNode *res = getNext(a);
    assert(res == f);
    res = getNext(b);
    assert(res == e);
    res = getNext(c);
    assert(res == nullptr);
    res = getNext(d);
    assert(res == b);
    res = getNext(e);
    assert(res == a);
    res = getNext(f);
    assert(res == c);
}
// 没有右子树的二叉树
void test4()
{
    TreeNode *head = new TreeNode();
    TreeNode *a = head;
    TreeNode *b = new TreeNode();
    TreeNode *c = new TreeNode();
    TreeNode *d = new TreeNode();
    head->left = b;
    b->left = c;
    c->left = d;

    b->parent = a;
    c->parent = b;
    d->parent = c;

    TreeNode *res = getNext(a);
    assert(res == nullptr);
    res = getNext(b);
    assert(res == a);
    res = getNext(c);
    assert(res == b);
    res = getNext(d);
    assert(res == c);
}
// 没有左子树的二叉树
void test5()
{
    TreeNode *head = new TreeNode();
    TreeNode *a = head;
    TreeNode *b = new TreeNode();
    TreeNode *c = new TreeNode();
    TreeNode *d = new TreeNode();
    head->right = b;
    b->right = c;
    c->right = d;

    b->parent = a;
    c->parent = b;
    d->parent = c;

    TreeNode *res = getNext(a);
    assert(res == b);
    res = getNext(b);
    assert(res == c);
    res = getNext(c);
    assert(res == d);
    res = getNext(d);
    assert(res == nullptr);
}
// 只有一个节点
void test6()
{
    TreeNode *head = new TreeNode();
    TreeNode *res = getNext(head);

    assert(res == nullptr);
}
// 指针为空
void test7()
{
    TreeNode *head = nullptr;
    TreeNode *res = getNext(head);

    assert(res == nullptr);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}
