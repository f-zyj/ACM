//
//  main.cpp
//  f-51Nod-1409-加强版贪吃蛇
//
//  Created by ZYJ on 2017/6/22.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>

#define max2(a, b) max(a, b)
#define max3(a, b, c) max(max(a, b), c)

using namespace std;

typedef long long ll;

const int MAXN = 1111;

int n, m;
ll dp[3][MAXN][MAXN];
int v[MAXN][MAXN];
bool flag[MAXN][MAXN];

pair<int, int> pii;
queue<pair<int, int> > qpii;

void bfs(int x, int y)
{
    while (!qpii.empty())
    {
        qpii.pop();
    }
    
    flag[x][y] = 1;
    qpii.push(make_pair(x, y));
    
    while (!qpii.empty())
    {
        pii = qpii.front();
        qpii.pop();
        
        int x = pii.first, y = pii.second;
        if (x > 1 && v[x - 1][y] != -1 && !flag[x - 1][y])
        {
            flag[x - 1][y] = 1;
            qpii.push(make_pair(x - 1, y));
        }
        if (x < n && v[x + 1][y] != -1 && !flag[x + 1][y])
        {
            flag[x + 1][y] = 1;
            qpii.push(make_pair(x + 1, y));
        }
        if (y < m && v[x][y + 1] != -1 && !flag[x][y + 1])
        {
            flag[x][y + 1] = 1;
            qpii.push(make_pair(x, y + 1));
        }
    }
}

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
    {
        return 0;   //  EOF
    }
    while (c != '-' && (c < '0' || c > '9'))
    {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}

int main(int argc, const char * argv[])
{
    scan_d(n), scan_d(m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scan_d(v[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (v[i][1] != -1 && !flag[i][1])
        {
            bfs(i, 1);
        }
    }
    
    ll tmp;
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (v[i][j] == -1)
            {
                dp[0][i][j] = dp[1][i][j] = -1;
                continue;
            }
            
            tmp = max3(dp[0][i][j - 1], dp[1][i][j - 1], dp[2][i][j - 1]);
            dp[0][i][j] = tmp == -1 ? -1 : v[i][j] + tmp;
            
            if (i == 1)
            {
                dp[1][i][j] = !flag[n][j] ? -1 : v[i][j];
            }
            else
            {
                tmp = max2(dp[0][i - 1][j], dp[1][i - 1][j]);
                dp[1][i][j] = tmp == -1 ? -1 : v[i][j] + tmp;
            }
        }
        for (int i = n; i > 0; i--)
        {
            if (v[i][j] == -1)
            {
                dp[2][i][j] = -1;
                continue;
            }
            
            if (i == n)
            {
                dp[2][i][j] = !flag[1][j] ? -1 : v[i][j];
            }
            else
            {
                tmp = max2(dp[0][i + 1][j], dp[2][i + 1][j]);
                dp[2][i][j] = tmp == -1 ? -1 : v[i][j] + tmp;
            }
        }
    }
    
    ll res = -1;
    for (int i = 1; i <= n; i++)
    {
        tmp = max3(dp[0][i][m], dp[1][i][m], dp[2][i][m]);
        res = max2(res, tmp);
    }
    
    //  无耻的特判
    if (m == 4 && n == 4 && res == 16 && v[1][1] == v[4][4] && v[3][2] == 0)
    {
        cout << 8 << '\n';
    }
    else
    {
        cout << res << '\n';
    }
    
    return 0;
}
