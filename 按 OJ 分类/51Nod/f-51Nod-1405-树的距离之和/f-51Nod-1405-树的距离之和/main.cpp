//
//  main.cpp
//  f-51Nod-1405-树的距离之和
//
//  Created by ZYJ on 16/9/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <vector>
//#include <cstdio>
//
//using namespace std;
//
//typedef long long ll;
//
//const int MAXN = 1e5 + 5;
//
//int n;
//ll res[MAXN];
//int des[MAXN];
//
//vector<int> node[MAXN];
//
//void dfs(int lastPos, int pos, int power)
//{
//    for (int i = 0; i < node[pos].size(); i++)
//    {
//        if (node[pos][i] != lastPos)
//        {
//            res[1] += (node[node[pos][i]].size() - 1) * power;
//            dfs(pos, node[pos][i], power + 1);
//            des[pos] += des[node[pos][i]];
//        }
//    }
//    return ;
//}
//
//void dfs_(int lastPos, int pos)
//{
//    for (int i = 0; i < node[pos].size(); i++)
//    {
//        if (node[pos][i] != lastPos)
//        {
//            res[node[pos][i]] = res[pos] - des[node[pos][i]] + n - des[node[pos][i]];
//            dfs_(pos, node[pos][i]);
//        }
//    }
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
////    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    cin >> n;
//    
//    int x, y;
//    for (int i = 1; i < n; i++)
//    {
//        scanf("%d %d", &x, &y);
//        node[x].push_back(y);
//        node[y].push_back(x);
//    }
//    res[1] = node[1].size();
//    for (int i = 1; i <= n; i++)
//    {
//        des[i] = 1;
//    }
//    dfs(0, 1, 2);
//    dfs_(0, 1);
//    
//    for (int i = 1; i <= n; i++)
//    {
//        printf("%lld\n", res[i]);
//    }
//    
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>

#define MAXN 100009

using namespace std;

typedef struct
{
    int a;
    int next;
} point;

point p[2 * MAXN];

typedef struct
{
    long long n;
    long long w;
} r;

r R;

int dis[MAXN];
long long dp[2 * MAXN][2];

void DFS(int a, int last)
{
    int i;
    long long ans = 0, count = 0;
    for (i = dis[a]; i != 0; i = p[i].next)
    {
        if (p[i].a != last)
        {
            if (dp[i][0] != -1)
            {
                ans += dp[i][0] + dp[i][1];
                count += dp[i][1];
            }
            else
            {
                DFS(p[i].a, a);
                dp[i][0] = R.w;
                dp[i][1] = R.n;
                ans += R.w + R.n;
                count += R.n;
            }
        }
    }
    R.n = count + 1;
    R.w = ans;
    return ;
}

int main ()
{
    int N, k = 1, a, b;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        scanf("%d%d", &a, &b);
        p[k].a = a;
        p[k].next = dis[b];
        dis[b] = k++;
        p[k].a = b;
        p[k].next = dis[a];
        dis[a] = k++;
    }
    for (int i = 1, sz = N + 1; i < sz; i++)
    {
        DFS(i, 0);
        printf("%lld\n", R.w);
    }
    
    return 0;
}
