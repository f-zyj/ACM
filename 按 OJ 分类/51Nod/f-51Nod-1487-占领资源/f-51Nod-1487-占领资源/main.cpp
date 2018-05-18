//
//  main.cpp
//  f-51Nod-1487-占领资源
//
//  Created by ZYJ on 2016/9/27.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//  暴力枚举TLE
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//const int MAXN = 333;
//const int MAXK = 12;
//const int MAXP = 111;
//
//int val[MAXN][MAXN];
//int vis[MAXN][MAXN];
//
//int dx[MAXK];
//int dy[MAXK];
//
//int main(int argc, const char * argv[])
//{
////    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    int T;
//    cin >> T;
//    
//    int N, M, K;
//    int ans;
//    while (T--)
//    {
//        ans = 0;
//        memset(val, 0, sizeof(val));
//        
//        cin >> N >> M >> K;
//        N += MAXP;
//        M += MAXP;
//        for (int i = 1 + MAXP; i <= N; i++)
//        {
//            for (int j = 1 + MAXP; j <= M; j++)
//            {
//                scanf("%1d", val[i] + j);
//            }
//        }
//        for (int i = 1; i <= K; i++)
//        {
//            scanf("%d %d", dx + i, dy + i);
//        }
//        int resA, resB;
//        for (int i = 1 + MAXP; i <= N; i++)
//        {
//            for (int j = 1 + MAXP; j <= M; j++)
//            {
//                memset(vis, 0, sizeof(vis));
//                resA = 0;
//                for (int k = 1; k <= K; k++)
//                {
//                    resA += val[i + dx[k]][j + dy[k]];
//                    vis[i + dx[k]][j + dy[k]] = 1;
//                }
//                for (int ii = 1 + MAXP; ii <= N; ii++)
//                {
//                    for (int jj = 1 + MAXP; jj <= M; jj++)
//                    {
//                        if (ii < i && jj < j)
//                        {
//                            break;
//                        }
//                        resB = 0;
//                        for (int kk = 1; kk <= K; kk++)
//                        {
//                            if (!vis[ii + dx[kk]][jj + dy[kk]])
//                            {
//                                resB += val[ii + dx[kk]][jj + dy[kk]];
//                            }
//                        }
//                        if (resA + resB > ans)
//                        {
//                            ans = resA + resB;
//                        }
//                    }
//                }
//            }
//        }
//        cout << ans << '\n';
//    }
//    
//    return 0;
//}


#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXX = 1e2 + 5;
const int MAXS = 1e4 + 5;
const int MAXK = 15;

int n, m, k;
char W[MAXX][MAXX];
int A[MAXS];
int MAX[MAXS][MAXK];
int vis[MAXX][MAXX];
int dx[MAXK], dy[MAXK], dq[MAXS];

void RMQ_init(int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        MAX[i][0] = A[i];
    }
    for (int j = 1; (1 << j) <= n + 1; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n + 1; i++)
        {
            MAX[i][j] = max(MAX[i][j - 1], MAX[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int RMQ_max(int L, int R)
{
    int k = 0;
    while ((1 << (k + 1)) <= R - L + 1)
    {
        k++;
    }
    return max(MAX[L][k], MAX[R - (1 << k) + 1][k]);
}

bool max_(int &a, int b)
{
    if (b > a)
    {
        a = b;
        return true;
    }
    return false;
}

inline int ID(int x, int y)
{
    return (x - 1) * m + y;
}

int solve()
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int Max = 0, id = ID(i, j), dsz = 0;
            for (int q = 1; q <= k; q++)
            {
                int nx = i + dx[q], ny = j + dy[q];
                if (nx < 1 || nx > n || ny < 1 || ny > m)
                {
                    continue;
                }
                vis[nx][ny] = id;
                
                for (int w = 1; w <= k; w++)
                {
                    int nnx = nx - dx[w], nny = ny - dy[w]; //  存在冲突的位置
                    if (nnx < 1 || nnx > n || nny < 1 || nny > m)
                    {
                        continue;
                    }
                    dq[++dsz] = ID(nnx, nny);
                }
            }
            
            //  为了RMQ而加的哨兵
            dq[++dsz] = 0;
            dq[++dsz] = m * n + 1;
            //  冲突位置排序去重
            sort(dq + 1, dq + 1 + dsz);
            dsz = (int)(unique(dq + 1, dq + 1 + dsz) - dq - 1);
            
            //  查找不冲突位置
            for (int q = 1; q <= dsz - 1; q++)
            {
                if (dq[q] + 1 <= dq[q + 1] - 1)
                {
                    max_(Max, RMQ_max(dq[q] + 1, dq[q + 1] - 1));
                }
            }
            //  查找冲突位置
            for (int q = 2; q <= dsz - 1; q++)
            {
                int x = (dq[q] - 1) / m + 1, y = (dq[q] - 1) % m + 1, sum = A[ID(x, y)];
                for (int w = 1; w <= k; w++)
                {
                    int nx = x + dx[w], ny = y + dy[w];
                    if (nx < 1 || nx > n || ny < 1 || ny > m)
                    {
                        continue;
                    }
                    if (vis[nx][ny] == id)
                    {
                        sum -= W[nx][ny] - '0';
                    }
                }
                max_(Max, sum);
            }
            max_(ret, Max + A[id]);
        }
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                vis[i][j] = A[ID(i, j)] = 0;
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", W[i] + 1);
        }
        for (int i = 1; i <= k; i++)
        {
            scanf("%d%d", &dx[i], &dy[i]);
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int id = ID(i, j);
                for (int q = 1; q <= k; q++)
                {
                    int nx = i + dx[q], ny = j + dy[q];
                    if (nx < 1 || nx > n || ny < 1 || ny > m)
                    {
                        continue;
                    }
                    A[id] += W[nx][ny] - '0';
                }
            }
        }
        RMQ_init(n * m);
        
        printf("%d\n", solve());
    }
    
    return 0;
}
