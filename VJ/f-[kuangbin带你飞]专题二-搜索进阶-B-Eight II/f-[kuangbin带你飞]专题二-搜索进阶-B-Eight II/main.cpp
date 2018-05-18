//
//  main.cpp
//  f-[kuangbin带你飞]专题二-搜索进阶-B-Eight II
//
//  Created by ZYJ on 2017/4/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 362882 + 10;   //  9! + 10

int cnt;
int sta_contor[10];
int target[10][10] =
{
    {0, 1, 2, 3, 4, 5, 6, 7, 8},
    {1, 0, 2, 3, 4, 5, 6, 7, 8},
    {1, 2, 0, 3, 4, 5, 6, 7, 8},
    {1, 2, 3, 0, 4, 5, 6, 7, 8},
    {1, 2, 3, 4, 0, 5, 6, 7, 8},
    {1, 2, 3, 4, 5, 0, 6, 7, 8},
    {1, 2, 3, 4, 5, 6, 0, 7, 8},
    {1, 2, 3, 4, 5, 6, 7, 0, 8},
    {1, 2, 3, 4, 5, 6, 7, 8, 0}
};

struct
{
    int pre;
    char dir;
    int steps;
} vis[10][MAXN];

int fac[10];

//  记录当前棋盘状态和x的位置
struct node
{
    int a[10];
    int x;
};

//  hash-康拓展开式
int hash_cantor(int a[])
{
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        int temp = 0;
        for (int j = i + 1; j < 9; j++)
        {
            if (a[j] < a[i])
            {
                temp++;
            }
        }
        ans += temp * fac[8 - i];
    }
    return ans;
}

char str[5] = "dlru";
int dir[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

void bfs(int op, node end)
{
    queue<node> Q;
    Q.push(end);
    while (!Q.empty())
    {
        node n = Q.front();
        Q.pop();
        int n_contor = hash_cantor(n.a);
        int pos = n.x;
        for (int i = 0; i < 4; i++)
        {
            int x = n.x / 3;
            int y = n.x % 3;
            int x_ = x + dir[i][0];
            int y_ = y + dir[i][1];
            if (x_ >= 0 && x_ < 3 && y_ >= 0 && y_ < 3)
            {
                int cnt = x_ * 3 + y_;
                swap(n.a[cnt], n.a[pos]);
                n.x = cnt;
                int v = hash_cantor(n.a);
                if (vis[op][v].pre == -1 && v != sta_contor[op])
                {
                    vis[op][v].dir = str[i];
                    vis[op][v].pre = n_contor;
                    vis[op][v].steps = vis[op][n_contor].steps + 1;
                    Q.push(n);
                }
                n.x = pos;
                swap(n.a[cnt], n.a[pos]);
            }
        }
    }
}

void init()
{
    fac[0] = fac[1] = 1;
    for (int i = 2; i < 10; i++)
    {
        fac[i] = fac[i - 1] * i;
    }
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            vis[i][j].pre = -1;
        }
    }
    
    node end;
    for (int i = 0; i < 9; i++)
    {
        swap(end.a, target[i]);
        end.x = i;
        sta_contor[i] = hash_cantor(end.a);
        bfs(i, end);
    }
}

int main()
{
    init();
    
    int T;
    cin >> T;
    
    for (int cs = 1; cs <= T; cs++)
    {
        node ed;
        char s[10];
        int tag[10];
        scanf("%s", s);
        for (int i = 0, j = 1; i < 9; i++)
        {
            if (s[i] == 'X')
            {
                cnt = i;
            }
            else
            {
                tag[s[i] - '0'] = j++;
            }
        }

        scanf("%s", s);
        for (int i = 0; i < 9; i++)
        {
            if (s[i] == 'X')
            {
                ed.a[i] = 0;
            }
            else
            {
                ed.a[i] = tag[s[i] - '0'];
            }
        }
        
        int end_contor = hash_cantor(ed.a);
        int res_contor = end_contor;
        
        string s_ = "";
        while (vis[cnt][res_contor].pre != -1)
        {
            s_ += vis[cnt][res_contor].dir;
            res_contor = vis[cnt][res_contor].pre;
        }
        printf("Case %d: %d\n", cs, vis[cnt][end_contor].steps);
        for (int i = (int)s_.length() - 1; i >= 0; i--)
        {
            printf("%c", s_[i]);
        }
        puts("");
    }
    
    return 0;
}
