//
//  main.cpp
//  f-蓝桥-ALGO-38-接水问题
//
//  Created by ZYJ on 2017/6/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1e4 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int w[MAXN];

priority_queue<int, vector<int>, greater<int> > pqi;

int main()
{
    cin >> n >> m;
    
    int res = INF;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", w + i);
        res = min(res, w[i]);
    }
    
    if (n <= m)
    {
        cout << res << '\n';
        return 0;
    }
    
    for (int i = 0; i < m; i++)
    {
        pqi.push(w[i]);
    }
    
    for (int i = m; i < n; i++)
    {
        int t = w[i] + pqi.top();
        pqi.pop();
        pqi.push(t);
    }
    
    res = 0;
    while (!pqi.empty())
    {
        res = max(res, pqi.top());
        pqi.pop();
    }
    
    cout << res << '\n';
    
    return 0;
}
