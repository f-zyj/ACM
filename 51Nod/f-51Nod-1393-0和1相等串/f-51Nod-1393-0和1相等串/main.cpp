//
//  main.cpp
//  f-51Nod-1393-0和1相等串
//
//  Created by ZYJ on 16/8/12.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;

char S[MAXN];
int SUM[MAXN] = {0};    //  0化作-1
int dif[MAXN * 2];

int main(int argc, const char * argv[])
{
    memset(dif, 0x3f, sizeof(dif));
    dif[MAXN] = 0;

    scanf("%s", S + 1);
    int len = (int)strlen(S + 1);
    
    int ans = 0;
    for (int i = 1; i <= len; i++)
    {
        if (S[i] == '0')
        {
            SUM[i] = SUM[i - 1] - 1;
        }
        else
        {
            SUM[i] = SUM[i - 1] + 1;
        }
        if (dif[SUM[i] + MAXN] == INF)
        {
            dif[SUM[i] + MAXN] = i;
        }
        else
        {
            ans = max(ans, i - dif[SUM[i] + MAXN]);
        }
    }
    
    cout << ans << '\n';
    return 0;
}
