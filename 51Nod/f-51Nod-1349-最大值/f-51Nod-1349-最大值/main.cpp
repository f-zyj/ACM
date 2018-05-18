//
//  main.cpp
//  f-51Nod-1349-最大值
//
//  Created by ZYJ on 2017/5/19.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, Q;

struct node
{
    int val;
    int pos;
    int left;
    int right;
    
    node() : left(1), right(1) {}
} a[MAXN];

ll b[MAXN];
ll c[MAXN];

stack<pair<int, int>> sn;

void get_max()
{
    while (!sn.empty())
    {
        sn.pop();
    }
    
    sn.push(make_pair(a[0].val, 0));
    for (int i = 1; i < n; i++)
    {
        while (!sn.empty() && a[i].val >= sn.top().first)
        {
            int pos = sn.top().second;
            sn.pop();
            
            a[i].left += a[pos].left;
            if (!sn.empty())
            {
                a[sn.top().second].right += a[pos].right;
            }
        }
        sn.push(make_pair(a[i].val, i));
    }
    while (!sn.empty())
    {
        int pos = sn.top().second;
        sn.pop();
        if (!sn.empty())
        {
            a[sn.top().second].right += a[pos].right;
        }
    }
}

void get_b()
{
    memset(b, 0, sizeof(b));
    
    for (int i = 0; i < n; i++)
    {
        b[a[i].val] += (ll)a[i].left * a[i].right;
    }
}

void get_c()
{
    c[0] = b[0];
    for (int i = 1; i < MAXN; i++)
    {
        c[i] = c[i - 1] + b[i];
    }
}

int main(int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].val);
        a[i].pos = i;
    }
    
    get_max();
    
    get_b();
    get_c();
    
    cin >> Q;
    
    int k;
    while (Q--)
    {
        scanf("%d", &k);
        printf("%lld\n", c[MAXN - 1] - c[k - 1]);
    }
    
    return 0;
}
