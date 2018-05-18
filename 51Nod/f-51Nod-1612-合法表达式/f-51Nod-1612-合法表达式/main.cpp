//
//  main.cpp
//  f-51Nod-1612-合法表达式
//
//  Created by ZYJ on 2017/9/22.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 3e5 + 10;
const int MOD = 1e6 + 3;

int n, m;
int f[MAXN];
char s[MAXN];

int main()
{
    scanf("%s", s);
    n = (int)strlen(s);
    m = 2 * n;
    f[m] = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] < '0')
        {
            if (s[i] == '+' || s[i] == '-' || (i && s[i - 1] >= '0'))
            {
                m--;
            }
            else    //  考虑到不合法的串，比如 5//4
            {
                puts("0");
                return 0;
            }
        }
        else if (s[i + 1] < '0')
        {
            for (int j = m + n; j > m; j--)
            {
                f[j - 1] = (f[j - 1] + f[j]) % MOD;
            }
        }
    }
    
    printf("%d\n", f[m]);
    
    return 0;
}
