//
//  main.cpp
//  f-HDU-2017中国大学生程序设计竞赛-网络选拔赛-1007-Palindrome Function
//
//  Created by ZYJ on 2017/8/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 111;
const int MAXM = 50;
const ll INF = 100000000000ll;

int L, R, l, r, cnt;
ll ans;
int A[MAXN];
int B[MAXN];
ll dp_1[MAXM][MAXN];
ll dp_2[MAXM][MAXN];

void init()
{
    for (int i = 2; i < MAXM; i++)
    {
        ll mx = i;
        for (int j = 1; ; j++)
        {
            if (j == 1)
            {
                dp_1[i][j] = i;
                dp_2[i][j] = i;
                continue;
            }
            
            int tmp = (j + 1) >> 1;
            ll a = i - 1, b = i;
            for (int k = 1; k < tmp; k++)
            {
                a *= i;
                b *= i;
            }
            dp_1[i][j] = a;
            dp_2[i][j] = b;
            mx *= i;
            if (mx > INF)
            {
                break;
            }
        }
    }
}

bool check()
{
    for (int i = cnt - 1; i >= 0; i--)
    {
        if (A[i] > B[i])
        {
            return true;
        }
        
        if (A[i] < B[i])
        {
            return false;
        }
    }
    
    return true;
}

int cal(int key)
{
    if (cnt == 1)
    {
        return A[0] + 1;
    }
    
    int ret = 0;
    for (int i = 1; i < cnt; i++)
    {
        ret += dp_1[key][i];
    }
    
    int tmp = cnt >> 1;
    for (int i = cnt - 1; i >= tmp; i--)
    {
        int tep = cnt - (cnt - i) * 2;
        int j = (i == cnt - 1) ? 1 : 0;
        for (; j < A[i]; j++)
        {
            if (tep > 0)
            {
                ret += dp_2[key][tep];
            }
            else
            {
                ret++;
            }
        }
    }
    
    for (int i = cnt - 1; i >= tmp; i--)
    {
        B[i] = A[i];
        B[cnt - i - 1] = A[i];
    }
    
    if (check())
    {
        ret++;
    }
    
    return ret;
}

void solve()
{
    ans = 0;
    for (int i = l; i <= r; i++)
    {
        int tmp = R;
        cnt = 0;
        while (tmp)
        {
            A[cnt++] = tmp % i;
            tmp /= i;
        }
        if (cnt == 0)
        {
            A[cnt++] = 0;
        }
        
        ll cnt_2 = cal(i);
        tmp = L - 1;
        cnt = 0;
        while (tmp)
        {
            A[cnt++] = tmp % i;
            tmp /= i;
        }
        if (cnt == 0)
        {
            A[cnt++] = 0;
        }
        cnt_2 -= cal(i);
        ans += cnt_2 * i;
        ans += (R - L + 1 - cnt_2);
    }
}

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

int main()
{
    init();

    int T;
    scan_d(T);
    
    int ce = 1;
    while (T--)
    {
        scan_d(L), scan_d(R), scan_d(l), scan_d(r);
        
        solve();
        
        printf("Case #%d: %lld\n", ce++, ans);
    }
    
    return 0;
}
