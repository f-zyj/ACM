//
//  main.cpp
//  f-HDU-2017中国大学生程序设计竞赛-网络选拔赛-1004-A Secret
//
//  Created by ZYJ on 2017/8/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int nt[MAXN];
int val[MAXN];
char S1[MAXN], S2[MAXN];

void get_nt(char *p, int *nt, int *val)
{
    nt[0] = -1;
    nt[1] = 0;
    val[0] = 0;
    val[1] = 1;
    int len = (int)strlen(p);
    for (int i = 1; i < len; i++)
    {
        nt[i + 1] = 0;
        val[i + 1] = i + 1;
        for (int j = nt[i]; j >= 0; j = nt[j])
        {
            if (p[i] == p[j])
            {
                nt[i + 1] = j + 1;
                val[i + 1] += val[j + 1];
                val[i + 1] %= MOD;
                break;
            }
        }
    }
}

int KMP_Count(char *p, int *nt, char *t, int *val)
{
    int len = (int)strlen(t);
    int ans = 0;
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        int k = j;
        for (j = 0; k >= 0; k = nt[k])
        {
            if (t[i] == p[k])
            {
                j = k + 1;
                break;
            }
        }
        ans = (ans + val[j]) % MOD;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%s%s", S1, S2);
        int len_1 = (int)strlen(S1), len_2 = (int)strlen(S2);
        reverse(S1, S1 + len_1);
        reverse(S2, S2 + len_2);
        
        get_nt(S2, nt, val);
        
        printf("%d\n", KMP_Count(S2, nt, S1, val));
    }
    
    return 0;
}
