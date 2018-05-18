//
//  main.cpp
//  f-EOJ-大学生程序设计邀请赛（华东师范大学）-B-分词
//
//  Created by ZYJ on 2017/5/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 3e5 + 10;
const int MAX_WORD_LEN = 30;

int flag[MAXN];
char s[MAXN];
int Trie[MAXN][26], sz;
double dp[MAXN];
double val[MAXN];

void format(int x)
{
    if (!x)
    {
        return ;
    }
    
    format(flag[x]);
    
    if (flag[x])
    {
        printf(" ");
    }
    for (int i = flag[x] + 1; i <= x; i++)
    {
        printf("%c", s[i]);
    }
}

int main()
{
    int N, T;
    while (cin >> N)
    {
        sz = 0;
        val[0] = 0;
        memset(Trie[0], 0, sizeof(Trie[0]));
        
        for (int i = 0; i < N; i++)
        {
            scanf("%s", s);
            int k = 0;
            int len = (int)strlen(s);
            for (int j = 0; j < len; j++)
            {
                int x = s[j] - (s[j] >= 'a' ? 'a' : 'A');
                if (!Trie[k][x])
                {
                    Trie[k][x] = ++sz;
                    memset(Trie[sz], 0, sizeof(Trie[sz]));
                    val[sz] = 0;
                }
                k = Trie[k][x];
            }
            scanf("%lf", &val[k]);
            val[k] = log(val[k]) * len * len;
        }
        
        cin >> T;
        for (int i = 0; i < T; i++)
        {
            scanf("%s", s + 1);
            memset(dp, 0, sizeof(dp));
            int len = (int)strlen(s + 1);
            for (int j = 1; j <= len; j++)
            {
                int rt = 0;
                for (int k = 0; k < MAX_WORD_LEN; k++)
                {
                    if (j + k > len)
                    {
                        break;
                    }
                    int x = s[j + k] - (s[j + k] >= 'a' ? 'a' : 'A');
                    if (Trie[rt][x])
                    {
                        rt = Trie[rt][x];
                        if (dp[j + k] < dp[j - 1] + val[rt])
                        {
                            dp[j + k] = dp[j - 1] + val[rt];
                            flag[j + k] = j - 1;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            
            printf("%lf\n", dp[len]);
            format(len);
            puts("");
        }
    }
    
    return 0;
}
