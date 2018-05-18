//
//  main.cpp
//  f-51Nod-1489-蜥蜴和地下室
//
//  Created by ZYJ on 16/8/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//
//using namespace std;
//
//const int INF = 0x3f3f3f3f;
//const int MAXN = 11;
//
//int res = 0;    //  打爆首尾需要的次数
//int res_2 = INF;//  打爆中间的需要的最少次数
//int n, a, b;
//int H[MAXN];    //  生命值
//
////  暴力深搜
//void dfs(int N, int ans)
//{
//    //  当到达第n个人时，更新最少的爆破次数，并返回
//    if (N == n)
//    {
//        res_2 = res_2 > ans ? ans : res_2;
//        return ;
//    }
//    //  每次向后搜索都要保证第N-1个为负数
//    if (H[N - 1] < 0)
//    {
//        dfs(N + 1, ans);
//    }
//    int times = 0;
//    //  必须在第N位置爆times次才能保证第N-1个为负数
//    if (H[N - 1] >= 0)
//    {
//        times = H[N - 1] / b + 1;
//        H[N - 1] -= b * times;
//        H[N] -= a * times;
//        H[N + 1] -= b * times;
//        dfs(N + 1, ans + times);
//        H[N - 1] += b * times;
//        H[N] += a * times;
//        H[N + 1] += b * times;
//    }
//    //  只要爆times~times_次都能保证第N-1个为负数
//    int times_ = H[N] / a + 1;
//    if (H[N] >= 0 && times_ > times)
//    {
//        for (int i = times + 1; i <= times_; i++)
//        {
//            H[N - 1] -= b * i;
//            H[N] -= a * i;
//            H[N + 1] -= b * i;
//            dfs(N + 1, ans + i);
//            H[N - 1] += b * i;
//            H[N] += a * i;
//            H[N + 1] += b * i;
//        }
//    }
//    
//    return ;
//}
//
//int main(int argc, const char * argv[])
//{
////    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    cin >> n >> a >> b;
//    
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> H[i];
//    }
//    
//    //  打爆第1个
//    int times = H[1] / b + 1;
//    res += times;
//    H[1] -= b * times;
//    H[2] -= a * times;
//    H[3] -= b * times;
//    
//    //  打爆第n个
//    if (H[n] >= 0)
//    {
//        times = H[n] / b + 1;
//        res += times;
//        H[n] -= b * times;
//        H[n - 1] -= a * times;
//        H[n - 2] -= b * times;
//    }
//    
//    dfs(2, 0);
//    
//    //  保证res_2是有效次数
//    if (res_2 == INF)
//    {
//        res_2 = 0;
//    }
//    
//    std::cout << res + res_2 << '\n';
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 0x3f3f3f3f

#define A(p) (p - a > 0) ? p - a : 0    //  被攻击受伤
#define B(p) (p - b > 0) ? p - b : 0    //  被溅射受伤

using namespace std;

int dp[12][20][20][20]; //  dp[a][b][c][d]第a个弓箭手面临第a-1、a、a+1个弓箭手的生命值分别为b、c、d的状态
int da[12];

int main ()
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int n, a, b;
    
    while (scanf("%d%d%d", &n, &a, &b) == 3)
    {
        int g_1, g_n;   //  打爆第1和n个弓箭手的花费
        int i, j, k, t, sz;
        memset(dp, 0x3f, sizeof(dp));
        
        for (i = 0; i < n; i++)
        {
            scanf("%d", da + i);
        }
        for (i = 0; i < n; i++)
        {
            da[i]++;    //  0表示死亡状态
        }
        //  溅射第1个弓箭手至死
        g_1 = (da[0] % b == 0) ? da[0] / b : da[0] / b + 1;
        da[0] = 0;
        da[1] = (da[1] - g_1 * a > 0) ? da[1] - g_1 * a : 0;
        da[2] = (da[2] - g_1 * b > 0) ? da[2] - g_1 * b : 0;
        //  溅射第n个弓箭手至死
        g_n = (da[n - 1] % b == 0) ? da[n - 1] / b : da[n - 1] / b + 1;
        da[n - 1] = 0;
        da[n - 2] = (da[n - 2] - g_n * a > 0) ? da[n - 2] - g_n * a : 0;
        da[n - 3] = (da[n - 3] - g_n * b > 0) ? da[n - 3] - g_n * b : 0;
        
        dp[1][0][da[1]][da[2]] = 0; //  此状态初始化为0
        for (k = 1, sz = n - 1; k < sz; k++)
        {
            for (i = 16; i >= 0; i--)
            {
                for (j = 16; j >= 0; j--)
                {
                    for (t = 16; t >= 0; t--)
                    {
                        if (dp[k][i][j][t] != INF)  //  存在此状态
                        {
                            for (int u = i, v = j, w = t; !(u == 0 && v == 0 && w == 0);)
                            {
                                dp[k][B(u)][A(v)][B(w)] = min(dp[k][u][v][w] + 1, dp[k][B(u)][A(v)][B(w)]);
                                u = B(u);
                                v = A(v);
                                w = B(w);
                            }
                            if (i == 0)             //  当第k-1个人已经是死亡的状态
                            {
                                dp[k + 1][j][t][da[k + 2]] = min(dp[k + 1][j][t][da[k + 2]], dp[k][i][j][t]);
                            }
                        }
                    }
                }
            }
        }
        
        //  debug
//        for (i = 0; i <= 11; i++)
//        {
//            for (j = 0; j < 20; j++)
//            {
//                for (k = 0; k < 20; k++)
//                {
//                    for (t = 0; t < 20; t++)
//                    {
//                        if (dp[i][j][k][t] != INF)
//                        {
//                            cout << "dp" << '[' << i << "][" << j << "][" << k << "][" << t << "]= " << dp[i][j][k][t] << ' ' << endl;
//                        }
//                    }
//                }
//            }
//            cout << endl;
//        }
        
        //  中间花费次数+头花费次数+尾花费次数
        cout << dp[n - 1][0][0][0] + g_1 + g_n << endl;
    }
    return 0;
}
