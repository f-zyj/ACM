//
//  main.cpp
//  f-51Nod-1050-循环数组最大子段和
//
//  Created by ZYJ on 16/8/1.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 5e4 + 10;

ll A[MAXN];
ll All[MAXN], Start[MAXN];

ll MaxSubStringOne(ll *A, int n)
{
    int i;
    Start[n - 1] = A[n - 1];
    All[n - 1] = A[n - 1];
    for(i = n - 2; i >= 0; i--)         //  根据题意，从后向前遍历，反之亦可。
    {
        Start[i] = max(A[i], (A[i] + Start[i + 1]));
        All[i] = max(Start[i], All[i + 1]);
    }
    return All[0];                      //  All[0] 中存放结果
}

ll MaxSubStringTwo(ll *A, int n, ll sum)
{
    int i;
    Start[n - 1] = A[n - 1];
    All[n - 1] = A[n - 1];
    for(i = n - 2; i >= 0; i--)         //  根据题意，从后向前遍历，反之亦可。
    {
        Start[i] = min(A[i], (A[i] + Start[i + 1]));
        All[i] = min(Start[i], All[i + 1]);
    }
    return sum - All[0];                //  All[0] 中存放结果
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", A + i);
        sum += A[i];
    }
    ll ans_1 = MaxSubStringOne(A, N);
    ll ans_2 = MaxSubStringTwo(A, N, sum);
    cout << (ans_1 > ans_2 ? ans_1 : ans_2) << '\n';
    return 0;
}
