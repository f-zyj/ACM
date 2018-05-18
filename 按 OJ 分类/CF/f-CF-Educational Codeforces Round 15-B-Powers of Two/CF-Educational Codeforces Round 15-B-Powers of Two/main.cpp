//
//  main.cpp
//  CF-Educational Codeforces Round 15-B-Powers of Two
//
//  Created by ZYJ on 16/7/30.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 5;

int a_1[MAXN];
int a_2[MAXN];
long long pow[35];

inline void cinDiy(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int main(int argc, const char * argv[])
{
    int n;
    
    while (cin >> n)
    {
        int ans = 0;
        int A;
        int key_1 = 0, key_2 = 0;
        for (int i = 0; i < n; i++)
        {
            cinDiy(A);
            if (A % 2)
            {
                a_1[key_1] = A;
                int num;
                for (int j = 0; j < key_1; j++)
                {
                    num = A + a_1[j];
                    if ((num & (num - 1)) == 0) //  快速判断是否是2的幂,不用考虑0的情况
                    {
                        ans++;
                    }
                }
                key_1++;
            }
            else
            {
                a_2[key_2] = A;
                int num;
                for (int j = 0; j < key_2; j++)
                {
                    num = A + a_2[j];
                    if ((num & (num - 1)) == 0) //  快速判断是否是2的幂,不用考虑0的情况
                    {
                        ans++;
                    }
                }
                key_2++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
