//
//  main.cpp
//  f-二分图多重匹配
//
//  Created by ZYJ on 16/7/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

const int MAXN = 1010;
const int MAXM = 510;
int uN, vN;
int g[MAXN][MAXM];
int linker[MAXM][MAXN];
bool used[MAXM];
int num[MAXM];  //  右边最大的匹配数

bool dfs(int u)
{
    for (int v = 0; v < vN; v++)
    {
        if (g[u][v] && !used[v])
        {
            used[v] = true;
            if (linker[v][0] < num[v])
            {
                linker[v][++linker[v][0]] = u;
                return true;
            }
            for (int i = 1; i <= num[0]; i++)
            {
                if (dfs(linker[v][i]))
                {
                    linker[v][i] = u;
                    return true;
                }
            }
        }
    }
    return false;
}

int hungary()
{
    int res = 0;
    for (int i = 0; i < vN; i++)
    {
        linker[i][0] = 0;
    }
    for (int u = 0; u < uN; u++)
    {
        memset(used, false, sizeof(used));
        if (dfs(u))
        {
            res++;
        }
    }
    return res;
}



int main(int argc, const char * argv[])
{
    
    std::cout << "Hello, World!\n";
    return 0;
}
