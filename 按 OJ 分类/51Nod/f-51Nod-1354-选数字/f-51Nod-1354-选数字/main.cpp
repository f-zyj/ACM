//
//  main.cpp
//  f-51Nod-1354-选数字
//
//  Created by ZYJ on 2016/10/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXN = 1010;
//const int MOD = 1e9 + 7;
//
//int a[MAXN];
//
//map<int, int> temp;
//map<int, int> temp_;
//
//int main()
//{
//    int T;
//    scanf("%d", &T);
//    
//    while (T--)
//    {
//        int i;
//        int n, k;
//        temp.clear();
//        scanf("%d%d", &n, &k);
//        map<int, int>::iterator it;
//       
//        for (i = 0; i < n; i++)
//        {
//            scanf("%d", &a[i]);
//
//            if (k % a[i] == 0)
//            {
//                temp_ = temp;
//                for (it = temp_.begin(); it != temp_.end(); it++)
//                {
//                    int tmp = a[i] * it->first;
//                    if (k % tmp == 0)
//                    {
//                        temp[tmp] = (temp[tmp] + it->second) % MOD;
//                    }
//                }
//                temp[a[i]] = (temp[a[i]] + 1) % MOD;
//            }
//        }
//        
//        printf("%d\n", temp[k]);
//    }
//    
//    return 0;
//}

#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1010;
const int MAXM = 100001;

int a[MAXN];
int b[MAXN];
int dp[MAXM];
map<int, int> temp;

int main(void)
{
    int T;
    scanf("%d", &T);
    
    int n, K;
    while (T--)
    {
        int i;
        temp.clear();
        scanf("%d%d", &n, &K);
        memset(dp, 0, sizeof(dp));
        
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        
        //  求K约数
        int cnt = 0;
        for (i = 1; i * i < K; i++)
        {
            if (K % i)
            {
                continue;
            }
            b[cnt++] = i;
            b[cnt++] = K / i;
        }
        if (i * i == K)
        {
            b[cnt++] = i;
        }
        sort(b, b + cnt);
        
        for (i = 0; i < cnt; i++)
        {
            temp[b[i]] = i;
        }
        for (i = 0; i < n; i++)
        {
            if (K % a[i])
            {
                continue;
            }
            int tmp = temp[a[i]];
            for (int j = temp[K]; j >= 0; j--)
            {
                if (dp[j] && K % (b[j] * a[i]) == 0)
                {
                    int tmp_ = temp[b[j] * a[i]];
                    dp[tmp_] = (dp[j] + dp[tmp_]) % MOD;
                }
            }
            dp[tmp] = (dp[tmp] + 1) % MOD;
        }
        printf("%d\n", dp[cnt - 1]);
    }
    
    return 0;
}
