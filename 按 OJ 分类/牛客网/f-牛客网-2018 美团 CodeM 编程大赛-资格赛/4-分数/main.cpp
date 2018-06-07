//
//  main.cpp
//  f-牛客网-2018 美团 CodeM 编程大赛-资格赛
//
//  Created by ZYJ on 2018/6/7.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 555;

struct person
{
    double score;
    int pos;
    
    bool operator < (const person &rsh) const
    {
        return score > rsh.score;
    }
} p[MAXN];

int n, m, k, C;
int w[MAXN];
int ans[MAXN];
int sco[MAXN][MAXN];

int main()
{
    memset(ans, -1, sizeof(ans));
    
    cin >> n >> m >> k >> C;
    
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
        sum += w[i];
    }
    
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> sco[i][j];
            if (sco[i][j] == -1)
            {
                x = i;
                y = j;
            }
        }
    }
    
    for (int c = 0; c <= C; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            p[i].pos = i;
            p[i].score = 0;
        }
        
        sco[x][y] = c;
        for (int j = 1; j <= m; j++)
        {
            int max_ = -1;
            for (int i = 1; i <= n; i++)
            {
                max_ = max(max_, sco[i][j]);
            }
            for (int i = 1; i <= n; i++)
            {
                if (max_ > 0)
                {
                    p[i].score += 1.0 * sco[i][j] / max_ * (1.0 * w[j] / sum);
                }
            }
        }
        
        sort(p + 1, p + n + 1);
        
        for (int i = 1; i <= n; i++)
        {
            if (i <= k)
            {
                if (ans[p[i].pos] == -1)
                {
                    ans[p[i].pos] = 1;
                }
                else if (ans[p[i].pos] == 1)
                {
                    ans[p[i].pos] = 1;
                }
                else
                {
                    ans[p[i].pos] = 3;
                }
            }
            else
            {
                if (ans[p[i].pos] == -1)
                {
                    ans[p[i].pos] = 2;
                }
                else if (ans[p[i].pos] == 1)
                {
                    ans[p[i].pos] = 3;
                }
            }
        }
        
        //  随机选取的情况
        if (k < n && p[k].score == p[k + 1].score)
        {
            for (int i = 1; i <= n; i++)
            {
                if (p[i].score == p[k].score)
                {
                    ans[p[i].pos] = 3;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << "\n";
    }
    
    return 0;
}
