//
//  main.cpp
//  f-51Nod-1380-夹克老爷的逢三抽一
//
//  Created by ZYJ on 2017/8/30.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n;
ll m[MAXN];
int l[MAXN], r[MAXN];
set<pair<ll, int> > spli;

void del(int x)
{
    spli.erase(make_pair(m[x], x));
    r[l[x]] = r[x];
    l[r[x]] = l[x];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &m[i]);
        spli.insert(make_pair(m[i], i));
        l[(i + 1) % n] = i;
        r[i] = (i + 1) % n;
    }
    
    int cnt = n / 3;
    ll ans = 0;
    for (int i = 0, j; i < cnt; i++)
    {
        j = spli.rbegin()->second;
        ll a = m[l[j]], b = m[j], c = m[r[j]];
        
        ans += b;
        del(l[j]);
        del(r[j]);
        spli.erase(make_pair(m[j], j));
        m[j] = a + c - b;
        spli.insert(make_pair(m[j], j));
    }
    
    cout << ans << endl;
    
    return 0;
}
