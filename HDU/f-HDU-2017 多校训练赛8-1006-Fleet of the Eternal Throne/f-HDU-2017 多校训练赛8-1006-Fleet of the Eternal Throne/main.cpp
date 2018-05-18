//
//  main.cpp
//  f-HDU-2017 多校训练赛8-1006-Fleet of the Eternal Throne
//
//  Created by ZYJ on 2017/8/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100005;
const int MAGIC = 26;

struct AC
{
    AC *nxt[MAGIC];
    AC *fail;
    int length;
    int flag;
};

AC *root;
int n, m, ans;
int id[MAXN];
char allchar[MAXN * 10];

void clear(AC *node)
{
    for (int i = 0; i < MAGIC; i++)
    {
        if (node->nxt[i] != NULL)
        {
            clear(node->nxt[i]);
        }
    }
    free(node);
}

AC *create()
{
    AC *node = (AC *)(malloc(sizeof(AC)));
    memset(node->nxt, 0, sizeof(node->nxt));
    node->fail = NULL;
    node->flag = -1;
    node->length =0;
    return node;
}

void insert(AC *root, char *word)
{
    AC *node = root;
    char *p = word;
    while (*p)
    {
        int id = *p - 'a';
        if (node->nxt[id] == NULL)
        {
            node->nxt[id] = create();
        }
        node->nxt[id]->length = node->length + 1;
        node = node->nxt[id];
        p++;
    }
}

void init()
{
    if (root != NULL)
    {
        clear(root);
    }
    root = create();
}

void input()
{
    scanf("%d", &n);
    int del = 0;
    for (int i = 1; i <= n; i++)
    {
        id[i] = del;
        scanf("%s", allchar + del);
        insert(root, allchar + del);
        del += strlen(allchar + del) + 1;
    }
}

AC *que[MAXN * 10];

void build()
{
    int l = 0, r = 1;
    que[1]= root;
    root->fail = root;
    while (l < r)
    {
        l++;
        AC *q = que[l];
        for (int i = 0; i < MAGIC; i++)
        {
            if (q->nxt[i] != NULL)
            {
                if (q == root)
                {
                    q->nxt[i]->fail = root;
                }
                else
                {
                    q->nxt[i]->fail = q->fail;
                    while (q->nxt[i]->fail->nxt[i] == NULL && q->nxt[i]->fail != root)
                    {
                        q->nxt[i]->fail = q->nxt[i]->fail->fail;
                    }
                    if (q->nxt[i]->fail->nxt[i] != NULL)
                    {
                        q->nxt[i]->fail = q->nxt[i]->fail->nxt[i];
                    }
                }
                r++;
                que[r] = q->nxt[i];
            }
        }
    }
}

void search(char *word, int f)
{
    AC *node = root;
    char *p = word;
    while (*p)
    {
        int id = *p - 'a';
        while (node != root && node->nxt[id] == NULL)
        {
            node = node->fail;
        }
        if (node->nxt[id] != NULL)
        {
            node = node->nxt[id];
        }
        AC *temp = node;
        while (temp != root)
        {
            temp->flag = f;
            temp = temp->fail;
        }
        p++;
    }
}

void query(char *word, int f)
{
    AC *node = root;
    char *p = word;
    while (*p)
    {
        int id = *p - 'a';
        while (node != root && node->nxt[id] == NULL)
        {
            node = node->fail;
        }
        if (node->nxt[id] != NULL)
        {
            node = node->nxt[id];
        }
        AC *temp = node;
        while (temp != root)
        {
            if (temp->flag == f)
            {
                ans = max(ans, temp->length);
            }
            temp = temp->fail;
        }
        p++;
    }
}

void solve()
{
    scanf("%d", &m);
    
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        search(allchar + id[x], i);
        ans = 0;
        query(allchar + id[y], i);
        printf("%d\n", ans);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        init();
        
        input();
        
        build();
        
        solve();
    }
    
    return 0;
}
