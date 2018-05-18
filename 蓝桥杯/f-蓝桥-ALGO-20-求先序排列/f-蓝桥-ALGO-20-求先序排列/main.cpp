//
//  main.cpp
//  f-蓝桥-ALGO-20-求先序排列
//
//  Created by ZYJ on 2017/6/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

typedef struct BTNode
{
    char data;
    struct BTNode *lc, *rc;
} *BTree;

BTree root;
string m, l;

void BuildBTree(BTree &t, int ms, int me, int ls, int le)
{
    t = new BTNode;
    t->data = l[le];
    t->lc = t->rc = NULL;
    
    int pos = ms;
    
    while (m[pos] != l[le])
    {
        pos++;
    }
    int len = pos - ms;
    if (pos > ms)
    {
        BuildBTree(t->lc, ms, pos - 1, ls, ls + len - 1);
    }
    if (pos < me)
    {
        BuildBTree(t->rc, pos + 1, me, ls + len, le - 1);
    }
}

void PrintBTree(BTree p)
{
    if (p != NULL)
    {
        cout << p->data;
        PrintBTree(p->lc);
        PrintBTree(p->rc);
    }
}

int main(int argc, char* argv[])
{
    cin >> m;
    cin >> l;

    BuildBTree(root, 0, int(m.size() - 1), 0, int(l.size() - 1));
    
    PrintBTree(root);
    putchar(10);
    
    return 0;
}

