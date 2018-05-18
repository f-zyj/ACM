//
//  main.cpp
//  f-51Nod-1254-最大子段和 V2
//
//  Created by ZYJ on 2017/9/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 5e4 + 10;

int n;
ll A[MAXN];
ll mx_l[MAXN];
ll mx_r[MAXN];
ll dp_l[2][MAXN];
ll dp_r[2][MAXN];

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0; //EOF
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

int main()
{
    scan_d(n);
    
    ll g = 0;
    for (int i = 0; i < n; i++)
    {
        scan_d(A[i]);
        g += A[i];
    }
    
    mx_l[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        mx_l[i] = max(mx_l[i - 1], A[i]);
    }
    mx_r[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        mx_r[i] = max(mx_r[i + 1], A[i]);
    }
    for (ll i = 1, sum = A[0], t = 0; i < n; i++)
    {
        if (sum < 0)
        {
            sum = 0;
            t = i;
        }
        dp_l[0][i] = t;
        dp_l[1][i] = sum;
        sum += A[i];
    }
    
    ll sum = A[n - 1];
    dp_r[0][n - 1] = n - 1;
    dp_r[1][n - 1] = 0;
    for (int i = n - 2, t = n - 1; i >= 0; i--)
    {
        if (sum < 0)
        {
            sum = 0;
            t = i;
        }
        dp_r[0][i] = t;
        dp_r[1][i] = sum;
        sum += A[i];
    }
    
    ll tmp, tep, cnt;
    g = max(0ll, g);
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            if (dp_l[0][i] > 0 && dp_r[0][i] < n - 1)
            {
                tmp = dp_l[1][i] + dp_r[1][i] + max(mx_l[dp_l[0][i] - 1], mx_r[dp_r[0][i] + 1]);
                tmp = max(tmp, dp_l[1][i] + dp_r[1][i]);
            }
            else if (dp_l[0][i] > 0)
            {
                tmp = dp_l[1][i] + dp_r[1][i] + mx_l[dp_l[0][i] - 1];
                tmp = max(tmp, dp_l[1][i] + dp_r[1][i]);
            }
            else if (dp_r[0][i] < n - 1)
            {
                tmp = dp_l[1][i] + dp_r[1][i] + mx_r[dp_r[0][i] + 1];
                tmp = max(tmp, dp_l[1][i] + dp_r[1][i]);
            }
            else
            {
                tmp = dp_l[1][i] + dp_r[1][i];
            }
            tep = dp_l[1][i] + dp_r[1][i];
            cnt = 1;
            while (A[dp_l[0][i] + cnt] < 0 && dp_l[0][i] + cnt < i)
            {
                tep += -A[dp_l[0][i] + cnt];
                cnt++;
            }
            tmp = max(tmp, tep);
            tep = dp_l[1][i] + dp_r[1][i];
            cnt = 1;
            while (A[dp_r[0][i] - cnt] < 0 && dp_r[0][i] - cnt > i)
            {
                tep += -A[dp_r[0][i] - cnt];
                cnt++;
            }
            tmp = max(tmp, tep);
            g = max(tmp, g);
        }
    }
    
    printf("%lld\n", g);
    
    return 0;
}
