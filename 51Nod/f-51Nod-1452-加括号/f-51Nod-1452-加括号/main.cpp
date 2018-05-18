//
//  main.cpp
//  f-51Nod-1452-加括号
//
//  Created by ZYJ on 2017/6/26.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

typedef long long ll;

const int MAXN = 5555;
const int MAXM = 22;

ll ans = 0;
ll mul[MAXM];
ll sta[MAXM];   //  连乘部分的开头
ll end[MAXM];   //  连乘部分的结尾
ll sum[MAXM];
char str[MAXN];

int main()
{
    scanf("%s", str);
    int len = (int)strlen(str);
    
    //  将连乘部分和连加部分拆分开来
    int cnt = 0;
    sta[0] = mul[0] = 1;
    for (int i = 1; i <= len; )
    {
        while (str[i] == '*')
        {
            mul[cnt] *= str[i - 1] - '0';
            i += 2;
        }
        mul[cnt] *= str[i - 1] - '0';   //  和乘法亲和
        end[cnt] = str[i - 1] - '0';
        mul[++cnt] = 1;
        
        i += 2;
        while (str[i] == '+')
        {
            sum[cnt] += str[i - 1] - '0';
            i += 2;
        }
        sta[cnt] = str[i - 1] - '0';
    }
    
    //  不加括号的结果
    for (int i = 0; i < cnt; i++)
    {
        ans += sum[i] + mul[i];
    }
    //  暴力枚举加括号的地方
    for (int i = 1; i < cnt; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ll tmp = 0;
            ll m = end[j] + sta[i];
            for (int k = 0; k < j; k++)
            {
                tmp += sum[k] + mul[k];
            }
            tmp += sum[j];
            
            for (int k = j + 1; k < i; k++)
            {
                m += sum[k] + mul[k];
            }
            m += sum[i];
            
            tmp += mul[i] / sta[i] * mul[j] / end[j] * m;
            for (int k = i + 1; k < cnt; k++)
            {
                tmp += sum[k] + mul[k];
            }
            ans = max(ans, tmp);
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
