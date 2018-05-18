//
//  main.cpp
//  f-HDU-1166-敌兵布阵
//
//  Created by ZYJ on 2017/1/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int MAXN = 50000;

string str;

int sum;                    //  记录总兵数
int num[MAXN + 1] = {0};    //  记录各个兵营的兵数

typedef struct node
{
    int left;
    int right;
    int data;
    node *lchild;
    node *rchild;
    node()
    {
        left = right = data = 0;
    }
} Tree;

Tree *CreateTree(int a, int b)
{
    Tree *r;
    r = (Tree *)malloc(sizeof(Tree));
    
    r->left = a;
    r->right = b;
    if (a == b)
    {
        r->data = num[a];
        r->lchild = r->rchild = NULL;
    }
    else
    {
        int mid = (a + b) >> 1;
        r->lchild = CreateTree(a, mid);
        r->rchild = CreateTree(mid + 1, b);
        r->data = r->lchild->data + r->rchild->data;
    }

    return r;
}

void update(Tree *r, int a, int b)
{
    if (r->left == a && r->right == a)
    {
        r->data += b;
        return;
    }
    int mid = (r->left + r->right) >> 1;
    if (a <= mid)
    {
        update(r->lchild, a, b);
    }
    else
    {
        update(r->rchild, a, b);
    }
    r->data += b;
}

void find(Tree* r, int a, int b)
{
    if (r->left == a && r->right == b)
    {
        sum += r->data;
        return ;
    }
    int mid = (r->left + r->right)>>1;
    if (b <= mid)
    {
        find(r->lchild, a, b);
    }
    else if (a > mid)
    {
        find(r->rchild, a, b);
    }
    else
    {
        find(r->lchild, a, mid);
        find(r->rchild, mid + 1, b);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    
    int n, x, y;
    int key = 0;
    
    while (T--)
    {
        printf("Case %d:\n", ++key);
        
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
        }
        
        Tree *T;
        T = CreateTree(1, n);
        while (cin >> str)
        {
            if (str == "Query")
            {
                sum = 0;
                scanf("%d%d", &x, &y);
                find(T, x, y);
                printf("%d\n", sum);
            }
            else if (str == "Add")
            {
                scanf("%d%d", &x, &y);
                update(T, x, y);
            }
            else if (str == "Sub")
            {
                scanf("%d%d", &x, &y);
                update(T, x, -y);
            }
            else
            {
                break;
            }
        }
    }
    
    return 0;
}
