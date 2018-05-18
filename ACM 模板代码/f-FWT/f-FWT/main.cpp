//
//  main.cpp
//  f-FWT
//
//  Created by ZYJ on 2017/7/6.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

/*
 *  FWT(快速沃尔什变化)-Xor
 *  MOD:1e9 + 7, INV_2:2关于MOD的逆元
 *  N:2的整次幂(不够就向上取整)
 */
typedef long long ll;

const int MOD = 1e9 + 7;
const int INV_2 = 5e8 + 4;

inline void FWT(int c[], int N, int tf_utf)    //  tf_utf 1:tf; 0:utf
{
    for (int i = 1; i < N; i <<= 1)
    {
        int tmp = i << 1;
        for (int j = 0; j < N; j += tmp)
        {
            for (int k = 0; k < i; k++)
            {
                int x = c[j + k], y = c[j + k + i];
                if (tf_utf)
                {
                    c[j + k] = x + y;
                    if (c[j + k] >= MOD)
                    {
                        c[j + k] -= MOD;
                    }
                    c[j + k + i] = x - y;
                    if (c[j + k + i] < 0)
                    {
                        c[j + k + i] += MOD;
                    }
                }
                else
                {
                    c[j + k] = (ll)(x + y) * INV_2 % MOD;
                    c[j + k + i] = (ll)(x - y + MOD) * INV_2 % MOD;
                }
            }
        }
    }
}
