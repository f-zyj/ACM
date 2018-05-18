//
//  main.cpp
//  f-计蒜客-2017 ACM-ICPC 亚洲区（乌鲁木齐赛区）网络赛-A-Banana
//
//  Created by ZYJ on 2017/9/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 50;

int n, m;
vector<int> mon[MAXN + 3];
vector<int> ans[MAXN + 3];
vector<int> place[MAXN + 3];

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%d", &n, &m);
        
        for (int i = 1; i <= MAXN; i++)
        {
            mon[i].clear();
            place[i].clear();
            ans[i].clear();
        }
        
        int u, v;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            mon[u].push_back(v);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            place[u].push_back(v);
        }
        for (int i = 1; i <= MAXN; i++)
        {
            for (int j = 0; j < mon[i].size(); j++)
            {
                int v = mon[i][j];
                for (int k = 0; k < place[v].size(); k++)
                {
                    ans[i].push_back(place[v][k]);
                }
            }
            sort(ans[i].begin(), ans[i].end());
        }
        
        for (int i = 1; i <= MAXN; i++)
        {
            if (ans[i].size() == 0)
            {
                continue;
            }
            
            printf("%d %d\n", i, ans[i][0]);
            for (int j = 1; j < ans[i].size(); j++)
            {
                if (ans[i][j] != ans[i][j - 1])
                {
                    printf("%d %d\n", i, ans[i][j]);
                }
            }
        }
        
        putchar(10);
    }
    
    return 0;
}
