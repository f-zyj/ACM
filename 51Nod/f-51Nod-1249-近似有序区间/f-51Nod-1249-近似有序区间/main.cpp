//
//  main.cpp
//  f-51Nod-1249-近似有序区间
//
//  Created by ZYJ on 2017/9/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

#define ls rt << 1
#define rs rt << 1 | 1

using namespace std;

const int MAXN = 5e4 + 10;

int n;
int S[MAXN];
int vis[MAXN];
int sum[MAXN];
int tree[MAXN << 2];

void build(int rt, int l, int r)
{
    if (l == r)
    {
        tree[rt] = S[l];
        return ;
    }
    
    int m = (l + r) >> 1;
    build(ls, l, m);
    build(rs, m + 1, r);

    tree[rt] = max(tree[ls], tree[rs]);
}

int query(int rt, int l, int r, int x, int y, int mx)
{
    if (l == r)
    {
        if (S[l] >= mx)
        {
            return l;
        }
        
        return 0;
    }
    
    int m = (l + r) >> 1, k = 0;
    if (tree[rt] >= mx)
    {
        if (x <= m)
        {
            k = query(ls, l, m, x, y, mx);
        }
        if (k == 0 && y > m)
        {
            k = query(rs, m + 1, r, x, y, mx);
        }
    }
    
    return k;
}

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> S[i];
    }
    
    build(1, 1, n);
    
    for (int i = n; i >= 1; i--)
    {
        if (S[i] > S[i + 1])
        {
            sum[i] = 1;
            vis[i] = i;
        }
        else
        {
            vis[i] = vis[i + 1];
            sum[i] = sum[i + 1] + 1;
            int mx = S[vis[i]];
            int l = vis[i] + 1, r = l;
            
            while (S[r] >= S[i])
            {
                r = vis[r] + 1;
            }
            r -= 1;
            
            while (l <= r)
            {
                mx = query(1, 1, n, l, r, mx);
                if (mx != 0)
                {
                    sum[i]++;
                }
                else
                {
                    break;
                }
                
                l = mx + 1;
                vis[i] = mx;
                mx = S[mx];
            }
        }
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += sum[i];
    }
    cout << ans << '\n';
    
    return 0;
}
