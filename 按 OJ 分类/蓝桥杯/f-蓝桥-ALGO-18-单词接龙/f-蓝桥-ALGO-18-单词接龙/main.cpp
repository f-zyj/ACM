//
//  main.cpp
//  f-蓝桥-ALGO-18-单词接龙
//
//  Created by ZYJ on 2017/6/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int MAXN = 22;

int n, len = 0;
string s[MAXN];
int vis[MAXN];

int charge(int left, int right)
{
    int len = 0;
    int llen = (int)s[left].length();
    int rlen = (int)s[right].length();
    for (int i = llen - 1; i > 0; i--)
    {
        int flag = 1, j = 0;
        for (; i + j < llen && j < rlen; j++)
        {
            if (s[left][i + j] != s[right][j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            len = j;
            break;
        }
    }
    if (len == s[right].length())
    {
        return 0;
    }
    return len;
}

void dfs(int k, int l)
{
    len = max(len, l);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] != 2)
        {
            int tmp = charge(k, i);
            if (tmp)
            {
                vis[i]++;
                dfs(i, l + (int)s[i].length() - tmp);
                vis[i]--;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    
    char a;
    cin >> a;
    for (int i = 0; i < n; i++)
    {
        if (s[i][0] == a)
        {
            vis[i]++;
            dfs(i, (int)s[i].length());
            vis[i]--;
        }
    }
    
    cout << len << '\n';
    
    return 0;
}
