//
//  main.cpp
//  f-51Nod-1280-前缀后缀集合
//
//  Created by ZYJ on 16/8/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <map>

using namespace std;

const int MAXN = 5e4 + 10;
const int OK = 999;

int A[MAXN];    //  正序
int B[MAXN];    //  逆序

int main(int argc, const char * argv[])
{
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", A + i);
        B[N - 1 - i] = A[i];
    }
    
    long long ans = 0;
    int res = 0;
    int tag = 0;
    map<int, int> AM;
    map<int, int> BM;
    for (int i = 0; i < N; i++)
    {
        map<int, int>::iterator it = AM.find(A[i]);
        if (it != AM.end())
        {
            ans += res;
            continue;
        }
        AM[A[i]] = OK;
        bool flag = false;
        res = 0;
        for (int j = tag; j < N; j++)
        {
            map<int, int>::iterator it = AM.find(B[j]);
            if (it == AM.end())
            {
                break;
            }
            if (flag)
            {
                res++;
                continue;
            }
            BM[B[j]] = OK;
            if (BM.size() == AM.size())
            {
                res++;
                tag = j;
                flag = true;
            }
        }
        ans += res;
    }
    
    printf("%lld\n", ans);
    return 0;
}
