//
//  main.cpp
//  f-HDU-6000-Wash
//
//  Created by ZYJ on 2017/11/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int L, n, m;
ll cost[MAXN];

struct node
{
    ll cost, base;
    
    bool operator < (const node &rhs) const
    {
        return cost > rhs.cost;
    }
};

ll x;
priority_queue<node> pqn1, pqn2;

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        while (!pqn1.empty())
        {
            pqn1.pop();
        }
        while (!pqn2.empty())
        {
            pqn2.pop();
        }
        
        scanf("%d%d%d", &L, &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            pqn1.push({x, x});
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%lld", &x);
            pqn2.push({x, x});
        }
        
        node t;
        for (int i = 0; i < L; ++i)
        {
            t = pqn1.top();
            pqn1.pop();
            cost[i] = t.cost;
            t.cost += t.base;
            pqn1.push(t);
        }
        
        ll ans = 0;
        for (int i = L - 1; i >= 0; i--)
        {
            t = pqn2.top();
            pqn2.pop();
            ans = max(ans, t.cost + cost[i]);
            t.cost += t.base;
            pqn2.push(t);
        }
        
        printf("Case #%d: %lld\n", ce, ans);
    }
    
    return 0;
}
