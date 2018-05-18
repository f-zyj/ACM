//
//  main.cpp
//  f-乐视2017实习-兵临城下
//
//  Created by ZYJ on 2018/3/23.
//  Copyright © 2018年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 6;

int n, ans;
string s[MAXN];
int vis[MAXN];

void dfs(int p)
{
    if (p == n)
    {
        ans++;
        return ;
    }
    for (int i = 0; i < s[p].length(); i++)
    {
        if (vis[s[p][i] - '0'] == 0)
        {
            vis[s[p][i] - '0'] = 1;
            dfs(p + 1);
            vis[s[p][i] - '0'] = 0;
        }
    }
}

int main(int argc, const char * argv[])
{
    while (cin >> n)
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        
        dfs(0);
        
        cout << ans << endl;
    }
    
    return 0;
}
