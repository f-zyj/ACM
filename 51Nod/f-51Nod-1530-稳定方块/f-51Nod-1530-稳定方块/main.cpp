//
//  main.cpp
//  f-51Nod-1530-稳定方块
//
//  Created by ZYJ on 2017/7/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int MAXM = 1e5 + 10;
const ll MOD = 1e9 + 9;

int m;
bool vis[MAXM];
int x[MAXM];
int y[MAXM];
ll ans[MAXM];
map<pair<int, int>, int> mpi;

bool judge(int a, int b)
{
    if (mpi[make_pair(a, b + 1)])
    {
        if (mpi[make_pair(a - 1, b)] == 0 && mpi[make_pair(a + 1, b)] == 0)
        {
            return 0;
        }
    }
    if (mpi[make_pair(a + 1, b + 1)])
    {
        if (mpi[make_pair(a + 1, b)] == 0 && mpi[make_pair(a + 2, b)] == 0)
        {
            return 0;
        }
    }
    if (mpi[make_pair(a - 1, b + 1)])
    {
        if (mpi[make_pair(a - 2, b)] == 0 && mpi[make_pair(a - 1, b)] == 0)
        {
            return 0;
        }
    }
    return 1;
}

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
    scan_d(m);
    for (int i = 1; i <= m; i++)
    {
        scan_d(x[i]), scan_d(y[i]);
        mpi[make_pair(x[i], y[i])] = i;
    }
    
    priority_queue<int> mx;                             //  大顶堆
    priority_queue<int, vector<int>, greater<int> > mn; //  小顶堆
    
    for (int i = 1; i <= m; i++)
    {
        if (judge(x[i], y[i]))
        {
            mx.push(mpi[make_pair(x[i], y[i])]);
            mn.push(mpi[make_pair(x[i], y[i])]);
        }
    }
    
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        if (i & 1)
        {
            ans[i] = mx.top();
            mx.pop();
        }
        else
        {
            ans[i] = mn.top();
            mn.pop();
        }
        
        if (vis[ans[i]])
        {
            i--;
            continue;
        }
        if (!judge(x[ans[i]], y[ans[i]]))
        {
            i--;
            continue;
        }
        
        vis[ans[i]] = 1;
        a = x[ans[i]];
        b = y[ans[i]];
        mpi.erase(make_pair(a, b));
        
        if (mpi[make_pair(a - 1, b - 1)])
        {
            if (judge(a - 1, b - 1))
            {
                mx.push(mpi[make_pair(a - 1, b - 1)]);
                mn.push(mpi[make_pair(a - 1, b - 1)]);
            }
        }
        if (mpi[make_pair(a, b - 1)])
        {
            if (judge(a, b - 1))
            {
                mx.push(mpi[make_pair(a, b - 1)]);
                mn.push(mpi[make_pair(a, b - 1)]);
            }
        }
        if (mpi[make_pair(a + 1, b - 1)])
        {
            if (judge(a + 1, b - 1))
            {
                mx.push(mpi[make_pair(a + 1, b - 1)]);
                mn.push(mpi[make_pair(a + 1, b - 1)]);
            }
        }
    }
    
    ll tmp = 1;
    ll res = 0;
    for (int i = m; i >= 1; i--)
    {
        res += (ans[i] - 1) * tmp;
        res %= MOD;
        tmp *= m;
        tmp %= MOD;
    }
    
    cout << res << endl;
    
    return 0;
}
