//
//  main.cpp
//  f-51Nod-1345-画点集
//
//  Created by ZYJ on 2017/5/17.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 55;
const int MAX_MAP = 77;
const int INF = 0x3f3f3f3f;

pair<int, int> node[MAXN];
int map[MAX_MAP * 2][MAX_MAP * 2];

//  判断两点之间是否有点
bool check(pair<int, int> &s, pair<int, int> &e, bool tag)
{
    if (s.second == e.second)
    {
        int st = min(s.first, e.first) + 1;
        int ed = max(s.first, e.first);
        if (!tag)
        {
            ed -= 1;
        }
        if (st > ed)
        {
            return false;
        }
        for (int i = st; i <= ed; i++)
        {
            if (!map[i][s.second])
            {
                return false;
            }
        }
    }
    else
    {
        int st = min(s.second, e.second) + 1;
        int ed = max(s.second, e.second);
        if (!tag)
        {
            ed -= 1;
        }
        if (st > ed)
        {
            return false;
        }
        for (int i = st; i <= ed; i++)
        {
            if (!map[s.first][i])
            {
                return false;
            }
        }
    }
    return true;
}

int solve(int n)
{
    int res = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < n;j++)
        {
            if (i == j)
            {
                continue;
            }
            int flag = 0;
            if (node[i].first == node[j].first)
            {
                int tmp = abs(node[i].second - node[j].second) - 2;
                if (tmp >= 0)   //  当两点横坐标大于等于2时
                {
                    if (!check(node[i], node[j], false))
                    {
                        res = min(res, tmp);
                    }
                }
            }
            else if (node[i].second == node[j].second)
            {
                int tmp = abs(node[i].first - node[j].first) - 2;
                if (tmp >= 0)   //  当两点纵坐标大于等于2时
                {
                    if (!check(node[i], node[j], false))
                    {
                        res = min(res, tmp);
                    }
                }
            }
            else
            {
                //  flag(B) 00/01/10/11 j 在 i 右上/右下/左上/左下
                if (node[j].first > node[i].first)
                {
                    flag |= 1;
                }
                if (node[j].second < node[i].second)
                {
                    flag |= 2;
                }
                for (int k = 0; k < n; k++) //  枚举三点关系
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    int flag_ = 0;
                    //  flag_(B) 00/01/10/11 k 在 i 右上/右下/左上/左下
                    if (node[k].first > node[i].first)
                    {
                        flag_ |= 1;
                    }
                    else if (node[k].first == node[i].first)
                    {
                        continue;
                    }
                    if (node[k].second < node[i].second)
                    {
                        flag_ |= 2;
                    }
                    else if (node[k].second == node[i].second)
                    {
                        continue;
                    }
                    //  j 和 k 在同一象限或者分别在一（二）和三（四）象限
                    if (flag == flag_ || (flag ^ flag_) == 3)
                    {
                        continue;
                    }
                    //  j 和 k 在 i 的一侧
                    if ((flag & 1) == (flag_ & 1))  //  down or up
                    {
                        int tmp = -1;
                        tmp = abs(node[i].first - node[j].first) - 2;
                        tmp = max(abs(node[i].first - node[k].first) - 2, tmp);
                        tmp = max(abs(node[k].second - node[j].second) - 2, tmp);
                        pair<int, int> s = abs(node[i].first - node[j].first) > abs(node[i].first - node[k].first) ? node[j] : node[k];
                        s.first = node[i].first;
                        if (!check(node[i], s, true))
                        {
                            res = min(tmp, res);
                        }
                    }
                    else                            //  left or right
                    {
                        int tmp = -1;
                        tmp = abs(node[i].second - node[j].second) - 2;
                        tmp = max(abs(node[i].second - node[k].second) - 2, tmp);
                        tmp = max(abs(node[k].first - node[j].first) - 2, tmp);
                        pair<int, int> s = abs(node[i].second - node[j].second) > abs(node[i].second - node[k].second) ? node[j] : node[k];
                        s.second = node[i].second;
                        if (!check(node[i], s, true))
                        {
                            res = min(tmp, res);
                        }
                    }
                }
            }
        }
    }
    if (res == INF)
    {
        res = -1;
    }
    return res;
}

int main()
{
    //freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int T;
    scanf("%d", &T);
    
    int n;
    for (int i = 0; i < T;i++)
    {
        memset(map, 0, sizeof(map));
        
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d%d", &node[j].first, &node[j].second);
            node[j].first += MAX_MAP;
            node[j].second += MAX_MAP;
            map[node[j].first][node[j].second] = 1;
        }
        
        printf("%d\n", solve(n));
    }
    
    return 0;
}
