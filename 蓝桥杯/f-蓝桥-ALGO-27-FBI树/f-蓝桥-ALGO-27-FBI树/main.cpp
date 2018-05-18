//
//  main.cpp
//  f-蓝桥-ALGO-27-FBI树
//
//  Created by ZYJ on 2017/6/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

typedef struct BTNode
{
    char state;
    int l, r;
    BTNode *left, *right;
    BTNode(int l_, int r_)
    {
        l = l_;
        r = r_;
        left = right = NULL;
    }
} *BTree;

BTree root;
string s;

void BuildBTree(BTree &t, int l, int r)
{
    t = new BTNode(l, r);
    
    if (l == r)
    {
        if (s[l] == '0')
        {
            t->state = 'B';
        }
        else
        {
            t->state = 'I';
        }
        return ;
    }
    
    int m = (l + r) >> 1;
    BuildBTree(t->left, l, m);
    BuildBTree(t->right, m + 1, r);
    if (t->left->state == 'I' && t->right->state == 'I')
    {
        t->state = 'I';
    }
    else if (t->left->state == 'B' && t->right->state == 'B')
    {
        t->state = 'B';
    }
    else
    {
        t->state = 'F';
    }
}

void PrintfBTree(BTree p)
{
    if (p != NULL)
    {
        PrintfBTree(p->left);
        PrintfBTree(p->right);
        cout << p->state;
    }
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    cin >> s;
    BuildBTree(root, 0, (int)s.length() - 1);
    
    PrintfBTree(root);
    putchar(10);
    
    return 0;
}
