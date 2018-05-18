//
//  main.cpp
//  f-HDU-2017 多校训练赛6-1007-GCDispower
//
//  Created by ZYJ on 2017/8/21.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 110005;

struct array        //  树状数组
{
    ll A[MAXN];
    int n;
    
    void clear()
    {
        fill(A, A + n + 5, 0);
    }
    
    array()
    {
        memset(A, 0, sizeof A);
        n = 0;
    }
    
    int lowbit(int x)
    {
        return x & (-x);
    }
    
    void add(int x, ll key)
    {
        while (x <= n)
        {
            A[x] += key;
            x += lowbit(x);
        }
    }
    
    ll sum(int x)   //  查询前x个元素
    {
        ll tmp = 0;
        while (x > 0)
        {
            tmp += A[x];
            x -= lowbit(x);
        }
        return tmp;
    }
    
    ll get(int L, int R)
    {
        return sum(R) - sum(L - 1);
    }
} A;

struct node
{
    int L, R, id;
    
    node(int L, int R, int id) : L(L), R(R), id(id) {}
    
    node()
    {
        *this = node(0, 0, 0);
    }
    
    bool operator < (const node &A) const
    {
        return R < A.R;
    }
} Q[MAXN];              //  离线问题

int miu[MAXN];          //  莫比乌斯函数
vector<int> V[MAXN];    //  用于存储因式分解。

void get_miu()
{
    int n = MAXN;
    for (int i = 1; i < n; i++)
    {
        int tar = (i == 1) ? 1 : 0;
        int tmp = tar - miu[i];
        miu[i] = tmp;
        for (int j = i + i; j < n; j += i)
        {
            miu[j] += tmp;
        }
    }
}

void init()
{
    get_miu();
    for (int i = 1; i < MAXN; i++)
    {
        for (int j = i; j < MAXN; j += i)
        {
            V[j].push_back(i);
        }
    }
}

int N, M, L, R;
int F[MAXN];
int X[MAXN];
int P[MAXN];
int D[MAXN];
ll ans[MAXN];

void solve()
{
    int cnt = 0;
    for (int i = 1; i < N; i++)
    {
        int size = N / P[i] + 1;
        fill(F, F + size + 1, 0);
        int deep = 0;
        for (int j = P[i]; j < N; j += P[i])
        {
            if (X[j] > i)
            {
                continue;
            }
            
            D[deep++] = X[j];
        }
        
        sort(D, D + deep);
        deep--;
        while ((--deep) > -1)
        {
            int x = D[deep];
            int t = P[x] / P[i];
            ll res = 0;
            for (int d = 0; d < V[t].size(); d++)
            {
                res += (ll)miu[V[t][d]] * F[V[t][d]];
            }
            A.add(x, res * P[i]);
            for (int d = 0; d < V[t].size(); d++)
            {
                F[V[t][d]]++;
            }
        }
        while (Q[cnt].R == i && cnt < M)
        {
            ans[Q[cnt].id] = A.get(Q[cnt].L, Q[cnt].R);
            cnt++;
        }
    }
}

int main ()
{
    init();
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        A.clear();
        scanf("%d%d", &N, &M);
        
        A.n = N;
        N++;
        for (int i = 1; i < N; i++)
        {
            scanf("%d", P + i);
        }
        for (int i = 1; i < N; i++)
        {
            X[P[i]] = i;
        }
        
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d", &L, &R);
            Q[i] = node(L, R, i);
        }
        sort(Q, Q + M);
        
        solve();
        
        for (int i = 0; i < M; i++)
        {
            printf("%lld\n", ans[i]);
        }
    }
    
    return 0;
}


