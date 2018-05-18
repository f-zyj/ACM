//
//  main.cpp
//  f-51Nod-1621-花钱买车牌
//
//  Created by ZYJ on 2017/10/26.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 1e4 + 10;
const int MAX_DIG = 10;
const int INF = 0x3f3f3f3f;

int n, k;
int cnt[MAX_DIG];
int num[MAXN];
int A[MAXN], B[MAXN];

void get_AB(int tmp[], int tot)
{
    memcpy(tmp, num, sizeof(num));
    
    int K = k - cnt[tot];
    for (int i = 1; i < MAX_DIG && K; i++)
    {
        int l = tot - i, r = tot + i;
        for (int j = 0; j < n && K; j++)
        {
            if (tmp[j] == r)
            {
                tmp[j] = tot;
                K--;
            }
        }
        for (int j = n - 1; j >= 0 && K; j--)
        {
            if (tmp[j] == l)
            {
                tmp[j] = tot;
                K--;
            }
        }
    }
}

bool cmp_AB()
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] > B[i])
        {
            return 1;
        }
        else if (A[i] < B[i])
        {
            return 0;
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[])
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%1d", num + i);
        cnt[num[i]]++;
    }
    
    for (int i = 0; i < MAX_DIG; i++)
    {
        if (cnt[i] >= k)
        {
            printf("0\n");
            for (int j = 0; j < n; j++)
            {
                printf("%d", num[j]);
            }
            putchar(10);
            
            return 0;
        }
    }
    
    int min_cost = INF;
    for (int i = 0; i < MAX_DIG; i++)
    {
        int tmp = 0, K = k - cnt[i];
        for (int j = 1; j < MAX_DIG; j++)
        {
            int l = i - j, r = i + j;
            if (l >= 0)
            {
                if (K > cnt[l])
                {
                    tmp += j * cnt[l];
                    K -= cnt[l];
                }
                else
                {
                    tmp += j * K;
                    K = 0;
                }
            }
            if (!K)
            {
                break;
            }
            
            if (r < MAX_DIG)
            {
                if (K > cnt[r])
                {
                    tmp += j * cnt[r];
                    K -= cnt[r];
                }
                else
                {
                    tmp += j * K;
                    K = 0;
                }
            }
            if (!K)
            {
                break;
            }
        }
        
        if (tmp < min_cost)
        {
            min_cost = tmp;
            
            get_AB(A, i);
        }
        else if (tmp == min_cost)
        {
            get_AB(B, i);
            
            if (cmp_AB())
            {
                swap(A, B);
            }
        }
    }
    
    printf("%d\n", min_cost);
    for (int i = 0; i < n; i++)
    {
        printf("%d", A[i]);
    }
    putchar(10);
    
    return 0;
}
