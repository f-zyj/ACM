//
//  main.cpp
//  f-51Nod-1832-先序遍历与后序遍历
//
//  Created by ZYJ on 2017/9/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_LEN = 666;

struct BigInt
{
    const static int MOD = 10000;
    const static int DLEN = 4;
    
    int len;
    int a[MAX_LEN];
    
    BigInt()
    {
        memset(a, 0, sizeof(a));
        len = 1;
    }
    
    BigInt(int v)
    {
        memset(a, 0, sizeof(a));
        len = 0;
        do
        {
            a[len++] = v%MOD;
            v /= MOD;
        }
        while (v);
    }
    
    BigInt operator * (const BigInt &b) const
    {
        BigInt res;
        for (int i = 0; i < len; i++)
        {
            int up = 0;
            for (int j = 0; j < b.len; j++)
            {
                int temp = a[i] * b.a[j] + res.a[i + j] + up;
                res.a[i + j] = temp % MOD;
                up = temp / MOD;
            }
            if (up != 0)
            {
                res.a[i + b.len] = up;
            }
        }
        res.len = len + b.len;
        while (res.a[res.len - 1] == 0 && res.len > 1)
        {
            res.len--;
        }
        
        return res;
    }
    
    void output()
    {
        printf("%d", a[len - 1]);
        for (int i = len - 2; i >= 0; i--)
        {
            printf("%04d", a[i]);
        }
        printf("\n");
    }
};

const int MAXN = 10010;

int n;
int ct = 0;
int a[MAXN];
int b[MAXN];

int get_id(int l, int r, int num)
{
    for (int i = l; i < r; ++i)
    {
        if (b[i] == num)
        {
            return i;
        }
    }
    
    return -1;
}

int calc(int num)
{
    if (num == 1)
    {
        return 1;
    }
    if (num == 2 || num == 0)
    {
        return 0;
    }
    
    return 0;
}

void dfs(int a_l, int a_r, int b_l, int b_r)
{
    int len = a_r - a_l;
    if (len == 1)
    {
        return ;
    }
    
    a_l++;
    b_r--;
    int x = 0, cnt = a_r - a_l, id, ar, br;
    while (cnt != 0)
    {
        id = get_id(b_l, b_r, a[a_l]);
        ar = a_l + (id - b_l + 1);
        br = id + 1;
        x++;
        
        dfs(a_l, ar, b_l, br);
        
        cnt -= (id - b_l + 1);
        a_l = ar;
        b_l = id + 1;
    }
    ct += calc(x);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", b + i);
    }
    
    dfs(0, n, 0, n);
    
    BigInt res(1);
    for (int i = 0; i < ct; i++)
    {
        res = res * BigInt(2);
    }
    res.output();
    
    return 0;
}
