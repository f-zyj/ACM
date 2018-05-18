//
//  main.cpp
//  f-51Nod-1962-区间计数
//
//  Created by ZYJ on 2017/7/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

const int MAXN = 4e5;

int N, now;
pii p[MAXN], q[MAXN];
int A[MAXN], B[MAXN];
int ra[MAXN], rb[MAXN];
ll ans;

int ins(pii x, pii y)
{
    if (x.second > y.second)
    {
        swap(x, y);
    }
    if (x.second < y.first)
    {
        return 0;
    }
    return x.second - max(x.first, y.first) + 1;
}

int main()
{
    scan_d(N);
    for (int i = 1; i <= N; i++)
    {
        scan_d(A[i]);
    }
    for (int i = 1; i <= N; i++)
    {
        scan_d(B[i]);
    }
    
    for (int i = N; i >= 1; i--)
    {
        for (ra[i] = i + 1; ra[i] <= N && A[ra[i]] <= A[i]; ra[i] = ra[ra[i]]) ;
        for (rb[i] = i + 1; rb[i] <= N && B[rb[i]] <= B[i]; rb[i] = rb[rb[i]]) ;
    }
    
    for (int i = 1; i <= N; i = ra[i])
    {
        p[A[i]] = mp(i, ra[i] - 1);
    }
    for (int i = 1; i <= N; i = rb[i])
    {
        q[B[i]] = mp(i, rb[i] - 1);
        now += ins(p[B[i]], q[B[i]]);
    }
    
    for (int i = 1; i <= N; i++)
    {
        ans += now;
        now -= ins(p[A[i]], q[A[i]]);
        p[A[i]] = mp(0, 0);
        if (A[i] != B[i])
        {
            now -= ins(p[B[i]], q[B[i]]);
            q[B[i]] = mp(0, 0);
        }
        for (int j = i + 1; j < ra[i]; j = ra[j])
        {
            p[A[j]] = mp(j, ra[j] - 1);
            now += ins(p[A[j]], q[A[j]]);
        }
        for (int j = i + 1; j < rb[i]; j = rb[j])
        {
            q[B[j]] = mp(j, rb[j] - 1);
            now += ins(p[B[j]], q[B[j]]);
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
