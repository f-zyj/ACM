//
//  main.cpp
//  f-51Nod-1378-夹克老爷的愤怒
//
//  Created by ZYJ on 2017/6/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int N, K;
int ans;
int cnt = 0;
int dg[MAXN];           //  度
int dp[MAXN];
vector<int> vi[MAXN];

void dfs(int x, int pre)
{
    int max_ = -INF;
    int min_ = INF;
    for (int i = 0; i < vi[x].size(); i++)
    {
        if (vi[x][i] != pre)
        {
            dfs(vi[x][i], x);
            max_ = max(max_, dp[vi[x][i]]);
            min_ = min(min_, dp[vi[x][i]]);
        }
    }
    
    if (max_ == -INF)
    {
        max_ = min_ = 0;
    }
    
    if (max_ >= K)
    {
        ans++;
        dp[x] = -K;
    }
    else if (min_ < 0 && min_ + max_ < 0)
    {
        dp[x] = min_ + 1;
    }
    else
    {
        dp[x] = max_ + 1;
    }
}

int main()
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    cin >> N >> K;
    
    int x, y;
    for (int i = 1; i < N; i++)
    {
        scanf("%d%d", &x, &y);
        vi[x].push_back(y);
        vi[y].push_back(x);
        dg[x]++;
        dg[y]++;
    }
    
    dfs(0, -1);
    if (dp[0] > 0)
    {
        ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}
