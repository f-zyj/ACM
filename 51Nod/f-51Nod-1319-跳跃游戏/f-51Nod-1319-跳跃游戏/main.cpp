//
//  main.cpp
//  f-51Nod-1319-跳跃游戏
//
//  Created by ZYJ on 16/9/5.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 55;

int A[MAXN];
int MAXA[MAXN];
long long sum[MAXN];

int main(int argc, const char * argv[])
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int T;
    cin >> T;
    
    while (T--)
    {
        int x, N;
        cin >> x >> N;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", A + i);
            if (i == 0)
            {
                sum[i] = A[i];
                MAXA[i] = A[i];
                continue;
            }
            sum[i] = sum[i - 1] + A[i];
            MAXA[i] = MAXA[i - 1] > A[i] ? MAXA[i - 1] : A[i];
        }
        int len = abs(x);
        int div = len / sum[N - 1];
        len -= div * sum[N - 1];
        if (len == 0)
        {
            cout << div * N << '\n';
            continue;
        }
        for (int i = 0; i < N; i++)
        {
            if (sum[i] >= len)
            {
                int steps = div * N + i + 1;

                if (div > 1)
                {
                    cout << steps << '\n';
                }
                else
                {
                    int MAXA_ = div > 0 ? MAXA[N - 1] : MAXA[i];
                    long long C = div * sum[N - 1] + sum[i] + abs(x);
                    if (C >= 2 * MAXA_)
                    {
                        cout << steps << '\n';
                    }
                    else
                    {
                        for (int j = 1; j <= 2 * N; j++)
                        {
                            MAXA_ = MAXA_ > MAXA[(i + j) % N] ? MAXA_ : MAXA[(i + j) % N];
                            C += A[(i + j) % N];
                            if (C >= 2 * MAXA_)
                            {
                                cout << steps + j << '\n';
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    
    return 0;
}
