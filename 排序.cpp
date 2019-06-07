#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct qwq
{
    int p1,p2;
}o,q;//不会用pair所以。。。

qwq QWQ(int x,int y)
{
    o.p1=x;
    o.p2=y;
    return o;
}//相当于make pair

struct asdf
{
    int l,r,c,key;
}tree[100001];//定义一棵树，左儿子、右儿子、权值、平衡种子
int n,g;//n个节点，树的根为g

qwq chaifen(int p,int x)
{
    if (p==0) return QWQ(0,0);//空树拆分成0 0
    if (tree[p].c>tree[x].c)
    {
        q=chaifen(tree[p].l,x);
        tree[p].l=q.p2;
        return QWQ(q.p1,p);
    }
    q=chaifen(tree[p].r,x);
    tree[p].r=q.p1;
    return QWQ(p,q.p2);
}//把一颗treap拆分成两颗treap
//一颗treap中所有元素都比待插入元素大，另一颗所有元素都比待插入元素小

int hebing(int pf,int pl)
{
    if (pf==0) return pl;
    if (pl==0) return pf;//一颗treap和空树合并仍是它本身
    if (tree[pf].key>tree[pl].key)//按照key合并深度关系
    {
        tree[pl].l=hebing(pf,tree[pl].l);
        return pl;
    }
    tree[pf].r=hebing(tree[pf].r,pl);
    return pf;
}//合并，使两颗treap合并成一颗，仍符合小根堆和二叉排序树的性质

void charu(int x)
{
    q=chaifen(g,x);
    g=hebing(hebing(q.p1,x),q.p2);
}

void dfs(int p)
{
    if (p==0) return;
    dfs(tree[p].l);
    printf("%d ",tree[p].c);
    dfs(tree[p].r);
}//因二叉排序树性质，中序遍历输出

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&tree[i].c);
        tree[i].key=rand()%2147483647;
        charu(i);//不断插入
    }
    dfs(g);
}