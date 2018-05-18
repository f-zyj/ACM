//
//  main.cpp
//  f-51Nod-1086-背包问题 V2
//
//  Created by ZYJ on 16/8/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//
//using namespace std;
//
//const int MAXN = 110;
//const int MAXW = 5e4 + 10;
//const int base[] = {1, 2, 4, 8, 16, 32, 64, 128};
//const int bases[] = {1, 3, 7, 15, 31, 63, 127, 255};
//const int MAXP = 8; //  最多分为8份
//
//int Wi[MAXN * 8];
//int Pi[MAXN * 8];
//int dp[MAXW];
//
//int main(int argc, const char * argv[])
//{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    int N, W;
//    cin >> N >> W;
//    
//    int key = 1;
//    int wi, pi, ci;
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d %d %d", &wi, &pi, &ci);
//        for (int i = 0; i < MAXP; i++)
//        {
//            if (bases[i] > ci)
//            {
//                Wi[key] = wi * (ci - bases[i - 1]);
//                Pi[key++] = pi * (ci - bases[i - 1]);
//                break;
//            }
//            else
//            {
//                Wi[key] = wi * base[i];
//                Pi[key++] = pi * base[i];
//            }
//            if (bases[i] == ci)
//            {
//                break;
//            }
//        }
//    }
//    
//    for (int i = 1; i < key; i++)
//    {
//        for (int j = W; j >= Wi[i]; j--)
//        {
//            dp[j] = max(dp[j], dp[j - Wi[i]] + Pi[i]);
//        }
//    }
//    
//    std::cout << dp[W] << '\n';
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//const int MAXN = 110;
//const int MAXW = 5e4 + 10;
//
//int N, W;
//int Wi[MAXN], Pi[MAXN], Ci[MAXN];
//int deq[MAXW];
//long long deqv[MAXW];
//long long dp[MAXW];
//
//int main()
//{
//    scanf("%d %d", &N, &W);
//    
//    for (int i = 0; i < N; ++i)
//    {
//        scanf("%d %d %d", &Wi[i], &Pi[i], &Ci[i]);
//    }
//    for (int i = 0; i < N; ++i)
//    {
//        for (int k = 0; k < Wi[i]; ++k)
//        {
//            int s = 0, t = 0;
//            for (int j = 0; j * Wi[i] + k <= W; ++j)
//            {
//                long long val = dp[j * Wi[i] + k] - j * Pi[i];
//                while (s < t && deqv[t - 1] <= val)
//                {
//                    t--;
//                }
//                deq[t] = j;
//                deqv[t++] = val;
//                dp[j * Wi[i] + k] = deqv[s] + j * Pi[i];
//                if (deq[s] == j - Ci[i])
//                {
//                    s++;
//                }
//            }
//        }
//    }
//    printf("%lld\n", dp[W]);
//    
//    return 0;
//}

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 101;
const int SIZE = 50001;

int dp[SIZE];
int volume[MAXN], value[MAXN], c[MAXN];
int n, v;           //  总物品数，背包容量

//  01背包
void ZeroOnepark(int val, int vol)
{
    for (int j = v ; j >= vol; j--)
    {
        dp[j] = max(dp[j], dp[j - vol] + val);
    }
}

//  完全背包
void Completepark(int val, int vol)
{
    for (int j = vol; j <= v; j++)
    {
        dp[j] = max(dp[j], dp[j - vol] + val);
    }
}

//  多重背包
void Multiplepark(int val, int vol, int amount)
{
    if (vol * amount >= v)
    {
        Completepark(val, vol);
    }
    else
    {
        int k = 1;
        while (k < amount)
        {
            ZeroOnepark(k * val, k * vol);
            amount -= k;
            k <<= 1;
        }
        if (amount > 0)
        {
            ZeroOnepark(amount * val, amount * vol);
        }
    }
}

int main()
{
    while (cin >> n >> v)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> volume[i] >> value[i] >> c[i];      //   费用，价值，数量
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            Multiplepark(value[i], volume[i], c[i]);
        }
        cout << dp[v] << endl;
    }
    return 0;
}
