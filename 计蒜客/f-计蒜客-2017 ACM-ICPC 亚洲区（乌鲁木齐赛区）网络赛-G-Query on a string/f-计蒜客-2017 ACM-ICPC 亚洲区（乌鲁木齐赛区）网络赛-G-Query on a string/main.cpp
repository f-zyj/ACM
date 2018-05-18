//
//  main.cpp
//  f-计蒜客-2017 ACM-ICPC 亚洲区（乌鲁木齐赛区）网络赛-G-Query on a string
//
//  Created by ZYJ on 2017/9/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>

#define lowb(x) (x & (-x))

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXM = 15;

char s[MAXN];
char t[MAXM];
int sum[MAXN];

void add(int x, int c, int n)
{
    while (x <= n)
    {
        sum[x] += c;
        x += lowb(x);
    }
}

int query(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += sum[x];
        x -= lowb(x);
    }
    
    return ans;
}

int n;

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        memset(sum, 0, sizeof(sum));
        
        scanf("%d%s%s", &n, s, t);
        
        int s_len = (int)strlen(s);
        int t_len = (int)strlen(t);
        
        for (int i = t_len - 1 ; i < s_len ; i++)
        {
            bool flag = true;
            for (int j = i - t_len + 1, index = 0; j <= i; j++, index++)
            {
                if (s[j] != t[index])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                add(i + 1, 1, s_len);
            }
        }
        
        char c[2];
        int a, b;
        for (int q = 0; q < n; q++)
        {
            scanf("%s", c);
            
            if (c[0] == 'Q')
            {
                scanf("%d%d", &a, &b);
                
                if (a + t_len - 1 > b)
                {
                    puts("0");
                }
                else
                {
                    printf("%d\n", query(b) - query(a + t_len - 2));
                }
            }
            else
            {
                scanf("%d%s", &a, c);
                
                s[a - 1] = c[0];
                for (int i = a - 1; i < a + t_len - 1; i++)
                {
                    int x = query(i + 1) - query(i);
                    if (x)
                    {
                        add(i + 1, -1, s_len);
                    }
                    bool flag = true;
                    for (int j = i - t_len + 1, index = 0; j <= i; j++, index++)
                    {
                        if (s[j] != t[index])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        add(i + 1, 1, s_len);
                    }
                }
            }
        }
        putchar(10);
    }
    
    return 0;
}
