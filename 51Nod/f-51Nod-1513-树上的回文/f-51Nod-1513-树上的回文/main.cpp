//
//  main.cpp
//  f-51Nod-1513-树上的回文
//
//  Created by ZYJ on 2017/7/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5e5 + 10;
const int MAX_LETTER = 27;

int n, m;
int cnt, max_h;
char s[MAXN];
int high[MAXN];
int POW[MAX_LETTER];
vector<int> E[MAXN];
vector<int> A[MAXN];
vector<int> B[MAXN];
pair<int, int> order[MAXN]; //  dfs 序

void dfs(int x, int h)
{
    max_h = max(h, max_h);
    high[x] = h;
    
    order[x].first = ++cnt;
    A[h].push_back(POW[s[x - 1] - 'a']);
    B[h].push_back(cnt);
    
    for (int i = 0; i < E[x].size(); i++)
    {
        dfs(E[x][i], h + 1);
    }
    
    order[x].second = cnt;
}

int solve(int x, int h)
{
    if (h <= high[x] || !B[h].size())
    {
        return 1;
    }
    
    int l = (int)(lower_bound(B[h].begin(), B[h].end(), order[x].first) - B[h].begin());
    int r = (int)(upper_bound(B[h].begin(), B[h].end(), order[x].second) - B[h].begin() - 1);
    
    if (l > r)
    {
        return 1;
    }
    
    int ans = A[h][r] ^ (l ? A[h][l - 1] : 0);
    if (ans == (ans & (-ans)))
    {
        return 1;
    }
    return 0;
}

void init()
{
    cnt = max_h = 0;
    POW[0] = 1;
    for (int i = 1; i < MAX_LETTER; i++)
    {
        POW[i] = POW[i - 1] << 1;
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
    init();
    
    scan_d(n), scan_d(m);
    
    int x;
    for (int i = 2; i <= n; i++)
    {
        
        scan_d(x);
        E[x].push_back(i);
    }
    
    scanf("%s", s);
    
    dfs(1, 0);
    
    max_h++;
    for (int i = 0; i < max_h; i++)
    {
        for (int j = 1; j < A[i].size(); j++)
        {
            A[i][j] ^= A[i][j - 1];
        }
    }
    
    int v, h;
    while (m--)
    {
        scan_d(v), scan_d(h);
        if (solve(v, h - 1))
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    
    return 0;
}
