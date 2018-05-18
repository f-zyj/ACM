//
//  main.c
//  f-51Nod-算法马拉松13-C-比大小
//
//  Created by ZYJ on 16/4/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

typedef long long ll;

ll a, b, N;
ll A_0, A_N, A;

ll setA(ll N)
{
    A = A_0 % 4;
    for (int i = 1; i <= N; i++)
    {
        A = (A * a + b) % 4;
    }
    return A;
}

int main(int argc, const char * argv[])
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld %lld %lld %lld", &A_0, &a, &b, &N);
        int flag = 1;
        ll lim = 4, A = A_0;
        flag = ((b <= lim) && (A <= lim));
        
        for (int i = 1; i <= N && flag; i++, A = A * a + b)
        {
            flag = (A < (lim - b) * 1.0 / a);
        }
        if (flag)
        {
            puts(A == 0 || A == 1 ? "=" : A == 2 ? "<" : ">");
            continue;
        }
        
        A = setA(N > 3 ? N % 4 + 4 : N);
        
        puts(A == 1 ? "=" : A == 3 ? ">" : "<");

    }
    return 0;
}
