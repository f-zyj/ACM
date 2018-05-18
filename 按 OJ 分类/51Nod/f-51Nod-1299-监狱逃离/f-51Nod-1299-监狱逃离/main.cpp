//
//  main.cpp
//  f-51Nod-1299-监狱逃离
//
//  Created by ZYJ on 2017/6/14.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
int ans;
int cnt = 0;
int dg[MAXN];           //  度
int flag[MAXN];
int prisoner[MAXN];     //  犯人
vector<int> vi[MAXN];

void dfs(int x, int pre)
{
    int state[3];       //  三种状态
    memset(state, 0, sizeof(state));
    for (int i = 0; i < vi[x].size(); i++)
    {
        if (vi[x][i] != pre)
        {
            dfs(vi[x][i], x);
            state[flag[vi[x][i]]]++;
        }
    }
    
    if (prisoner[x])    //  x 点有逃犯
    {
        ans += state[1];//  加上所有能到达的叶子（出口）的儿子结点数
        flag[x] = 2;    //  x 变为不能通向叶子（出口）的儿子结点
    }
    else if (state[1] && state[2])  //  有叶子（出口）可以通到 x 并且有其他犯人可以到达 x
    {
        ans++;          //  x 处放置警察
        flag[x] = 0;    //  不能到达 x
    }
    else if (state[1])  //  x 是否可以通往叶子（出口）
    {
        flag[x] = 1;    //  x 变为可以通往出口
    }
    else if (state[2])  //  是有犯人可以到达 x
    {
        flag[x] = 2;    //  x 变为有犯人到达
    }
    else if (state[0])  //  不能到达叶子（出口）
    {
        flag[x] = 0;    //  x 不能通往叶子（出口）
    }
}

//  初始化所有结点都可以通往出口
void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        flag[i] = 1;
    }
}

int main()
{
    init();
    
    cin >> n >> m;
    n++;
    
    int x, y;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        vi[x].push_back(y);
        vi[y].push_back(x);
        dg[x]++;
        dg[y]++;
    }
    
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        if (dg[x] == 1)
        {
            printf("-1\n");
            return 0;
        }
        prisoner[x] = 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (dg[i] == 1)
        {
            dfs(i, 0);
            if (flag[i] == 2)   //  有犯人能到达根节点
            {
                ans++;
            }
            break;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
