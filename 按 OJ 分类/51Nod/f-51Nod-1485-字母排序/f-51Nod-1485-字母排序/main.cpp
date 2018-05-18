//
//  main.cpp
//  f-51Nod-1485-字母排序
//
//  Created by ZYJ on 2017/7/23.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXK = 26;

int n, q;
bool vis[MAXN];
char s[MAXN];
char ans[MAXN];
int cnt[MAXN][MAXK];    //  cnt[i][j] 以 i 开头的后边紧跟着的有序序列每种字母的个数
set<int> si;

void split(int p)
{
    int l, len;
    auto it = si.lower_bound(p);
    if (*it == p)
    {
        return ;
    }
    len = *it;
    l = *(--it);
    len -= l;
    
    vis[p] = vis[l];
    
    if (!vis[l])
    {
        for (int i = 0; i < MAXK; i++)
        {
            if (len - cnt[l][i] > p - l)
            {
                cnt[p][i] += cnt[l][i];
                len -= cnt[l][i];
                cnt[l][i] = 0;
            }
            else
            {
                int num = len - (p - l);
                cnt[p][i] += num;
                cnt[l][i] -= num;
                break;
            }
        }
    }
    else
    {
        for (int i = MAXK - 1; i >= 0; i--)
        {
            if (len - cnt[l][i] > p - l)
            {
                cnt[p][i] += cnt[l][i];
                len -= cnt[l][i];
                cnt[l][i] = 0;
            }
            else
            {
                int num = len - (p - l);
                cnt[p][i] += num;
                cnt[l][i] -= num;
                break;
            }
        }
    }
    
    si.insert(p);
}

void merge(int l, int r, int k)
{
    vis[l] = k;
    vector<int> v;
    auto end = si.find(r);
    auto sta = si.find(l);
    
    for (sta++; sta != end; sta++)
    {
        for (int i = 0; i < MAXK; i++)
        {
            cnt[l][i] += cnt[*sta][i];
            cnt[*sta][i] = 0;
        }
        v.push_back(*sta);
    }
    
    for (int x : v)
    {
        si.erase(x);
    }
}

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int main()
{
    scan_d(n), scan_d(q);
    scanf("%s", s + 1);
    
    for (int i = 1; i <= n; i++)
    {
        cnt[i][s[i] - 'a']++;
        si.insert(i);
        vis[i] = 1;
    }
    si.insert(n + 1);
    
    int l, r, k;
    while (q--)
    {
        scan_d(l), scan_d(r), scan_d(k);
        split(l), split(r + 1);
        merge(l, r + 1, k);
    }
    
    int pos = 1;
    for (int x : si)
    {
        if (vis[x])
        {
            for (int i = 0; i < MAXK; i++)
            {
                for (int j = 0; j < cnt[x][i]; j++)
                {
                    ans[pos++] = 'a' + i;
                }
            }
        }
        else
        {
            for (int i = MAXK - 1; i >= 0; i--)
            {
                for (int j = 0; j < cnt[x][i]; j++)
                {
                    ans[pos++] = 'a' + i;
                }
            }
        }
    }
    
    puts(ans + 1);
    
    return 0;
}
