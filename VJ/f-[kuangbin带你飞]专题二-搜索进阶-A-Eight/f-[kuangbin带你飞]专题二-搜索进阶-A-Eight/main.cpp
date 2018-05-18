//
//  main.cpp
//  f-[kuangbin带你飞]专题二-搜索进阶-A-Eight
//
//  Created by ZYJ on 2017/4/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 362882 + 10;   //  9! + 10

int sta_contor;
int end_contor;
int target[10] = {1, 2, 3, 4, 5, 6, 7, 8, 0};

struct
{
    int next;
    char dir;
} vis[MAXN];

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

char str[5] = "durl";
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(node end)
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
                if (vis[v].next == -1 && v != end_contor)
                {
                    vis[v].dir = str[i];
                    vis[v].next = n_contor;
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
    
    for (int i = 0; i < MAXN; i++)
    {
        vis[i].next = -1;
    }
    
    node end;
    swap(end.a, target);
    end.x = 8;
    end_contor = hash_cantor(end.a);
    
    bfs(end);
}

void printRes(int n)
{
    while (vis[n].next != -1)
    {
        printf("%c", vis[n].dir);
        n = vis[n].next;
    }
}

int main()
{
    init();
    
    char s[3];
    while (~scanf("%s", s))
    {
        node star;
        if (s[0] == 'x')
        {
            star.a[0] = 0;
            star.x = 0;
        }
        else
        {
            star.a[0] = s[0] - '0';
        }
        for (int i = 1; i < 9; i++)
        {
            scanf("%s", s);
            if (s[0] == 'x')
            {
                star.x = i;
                star.a[i] = 0;
            }
            else
            {
                star.a[i] = s[0] - '0';
            }
        }
        
        sta_contor = hash_cantor(star.a);

        if (sta_contor == end_contor)
        {
            printf("\n");
        }
        else if (vis[sta_contor].next != -1)
        {
            printRes(sta_contor);
            printf("\n");
        }
        else
        {
            printf("unsolvable\n");
        }
    }
    
    return 0;
}
