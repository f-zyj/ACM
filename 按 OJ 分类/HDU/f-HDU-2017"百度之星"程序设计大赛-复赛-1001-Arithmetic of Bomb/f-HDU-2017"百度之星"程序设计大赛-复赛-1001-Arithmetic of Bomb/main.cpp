//
//  main.cpp
//  f-HDU-2017"百度之星"程序设计大赛-复赛-1001-Arithmetic of Bomb
//
//  Created by ZYJ on 2017/8/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1111;
const int MOD = 1e9 + 7;

char s[MAXN];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        scanf("%s", s);
        
        int len = (int)strlen(s);
        long long ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                int k = i + 1;
                while (s[k] != ')')
                {
                    k++;
                }
                k++;
                while (s[k] != ')')
                {
                    k++;
                }
                int cnt = s[k - 1] - '0';
                while (cnt--)
                {
                    for (int j = i + 1; j < k - 4; j++)
                    {
                        ans = (ans * 10 + s[j] - '0') % MOD;
                    }
                }
                i = k;
            }
            else
            {
                ans = (ans * 10 + s[i] - '0') % MOD;
            }
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
