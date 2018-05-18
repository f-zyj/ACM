//
//  main.cpp
//  f-51Nod-1359-循环探求
//
//  Created by ZYJ on 2017/6/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int CUT = 1e9;
const int MAXN = 666;
const int MAX_POW_10 = 10;
const int BASE_B = MAX_POW_10;
const int MAGIC = 9;
const int MAX_ANS = 5e3;
const int MAX_ = 100;

int k, flag = -1;
char n[MAXN];
int C[MAXN];
int ans[MAX_ANS];
ll A[MAX_];
ll B[MAX_];
ll T[MAX_];
ll Nx1[MAX_];
ll Nx2[MAX_];
ll POW_10[MAX_POW_10] = {1};

void init()
{
    for (int i = 1; i < MAX_POW_10; i++)
    {
        POW_10[i] = POW_10[i - 1] * BASE_B;
    }
}

void read()
{
    scanf("%s%d", n, &k);
    int len = (int)strlen(n);
    int cnt = 0;
    for (int i = len - 1; i > -1; i -= MAGIC, cnt++)
    {
        int sz = max(-1, i - MAGIC);
        for (int j = i, t = 0; j > sz; j--, t++)
        {
            A[cnt] += POW_10[t] * (ll)(n[j] - '0');
        }
    }
}

void mul(ll res[], ll scr[])
{
    memset(T, 0, sizeof(T));
    
    for (int i = 0; i < k; i++)
    {
        ll c = 0;
        for (int j = 0; j + i < k; j++)
        {
            T[i + j] += Nx1[i] * scr[j] + c;
            c = T[i + j] / CUT;
            T[i + j] -= c * CUT;
        }
    }
    
    memcpy(res, T, sizeof(T));
}

void solve()
{
    int K = k;
    k = k / MAGIC + 1;
    memcpy(B, A, sizeof(A));
    memcpy(Nx2, A, sizeof(A));
    
    Nx1[0] = 1;
    for (int i = 0; i < K; i++)
    {
        memcpy(A, B, sizeof(B));
        
        int dx = i / MAGIC;
        int dd = i % MAGIC;
        ll tmp = (B[dx] / POW_10[dd]) % BASE_B; //  对应第 i 位的值
        do
        {
            mul(Nx1, Nx2);
            mul(A, B);
            ans[i]++;
        }
        while (tmp != ((A[dx] / POW_10[dd]) % BASE_B) && ans[i] < 12);
        
        if (ans[i] > 11)
        {
            return ;
        }
        
        memcpy(Nx2, Nx1, sizeof(Nx1));
        memset(Nx1, 0, sizeof(Nx1));
        Nx1[0] = 1;
    }
    
    C[0] = 1;
    int deep = 1;
    for (int i = 0; i < K; i++)
    {
        int j = 0, c = 0;
        for (; j < deep; j++)
        {
            C[j] *= ans[i];
            C[j] += c;
            c = C[j] / 10000;
            C[j] -= c * 10000;
        }
        if (c > 0)
        {
            C[deep++] = c;
        }
    }
    
    C[0]++;
    int i = 0, c = 0;
    for (; i < deep; i++)
    {
        C[i] += c;
        c = C[i] / 10000;
        C[i] -= c * 10000;
        if (c == 0)
        {
            break;
        }
    }
    if (c > 0)
    {
        C[deep++] = c;
    }
    deep--;
    flag = deep;
}

void print()
{
    if (flag != -1)
    {
        printf("%d", C[flag--]);
        while (flag > -1)
        {
            printf("%04d", C[flag--]);
        }
        printf("\n");
    }
    else
    {
        printf("1\n");
    }
}

int main ()
{
    init();
    
    read();
    
    solve();
    
    print();
    
    return 0;
}
