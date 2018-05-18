//
//  main.cpp
//  f-ZOJ-The 14th Zhejiang Provincial Collegiate Programming Contest Sponsored by TuSimple-D-Let's Chat
//
//  Created by ZYJ on 2017/4/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 200;

struct Node
{
    int l;
    int r;
} AtoB[MAXN], BtoA[MAXN];

int pos[MAXN * 4], pos_[MAXN * 4], vis[MAXN * 4], vis_[MAXN * 4];

int bs(int l, int r, int k)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (k <= pos_[m])
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    
    return l;
}

int main()
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    int T;
    cin >> T;
    
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        memset(vis_, 0, sizeof(vis_));
        
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int cnt = 0;
        for (int i = 0; i < x; i++)
        {
            cin >> AtoB[i].l >> AtoB[i].r;
            pos[cnt++] = AtoB[i].l;
            pos[cnt++] = AtoB[i].r;
        }
        for (int i = 0; i < y; i++)
        {
            cin >> BtoA[i].l >> BtoA[i].r;
            pos[cnt++] = BtoA[i].l;
            pos[cnt++] = BtoA[i].r;
        }
        sort(pos, pos + cnt);
        
        int cnt_ = 0;
        for (int i = 1; i < cnt; i++)
        {
            if (pos[i] != pos[i - 1])
            {
                pos[++cnt_] = pos[i];
            }
        }
        
        cnt = 0;
        for (int i = 0; i <= cnt_; i++)
        {
            pos_[cnt++] = pos[i] * 2;
            pos_[cnt++] = pos[i] * 2 + 1;
        }
        for (int i = 0; i < x; i++)
        {
            int l = bs(0, cnt, AtoB[i].l * 2);
            int r = bs(0, cnt, AtoB[i].r * 2);
            for (int j = l; j <= r; j++)
            {
                vis[j] = 1;
            }
        }
        for (int i = 0; i < y; i++)
        {
            int l = bs(0, cnt, BtoA[i].l * 2);
            int r = bs(0, cnt, BtoA[i].r * 2);
            for (int j = l; j <= r; j++)
            {
                vis_[j] = 1;
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            vis[i] = min(vis[i], vis_[i]);
        }
        
        int ans = 0;
        int i = 0;
        while (i < cnt)
        {
            int j = i;
            while (vis[i])
            {
                i++;
            }
            if ((pos_[i - 1] - pos_[j]) / 2 + 1 >= m)
            {
                ans += (pos_[i - 1] - pos_[j]) / 2 + 1 - m + 1;
            }
            i++;
        }
        cout << ans << endl;
    }
    
    return 0;
}
