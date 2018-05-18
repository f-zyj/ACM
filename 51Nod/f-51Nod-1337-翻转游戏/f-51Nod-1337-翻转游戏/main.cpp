//
//  main.cpp
//  f-51Nod-1337-翻转游戏
//
//  Created by ZYJ on 16/9/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 55;

char LevS[MAXN][MAXN];

void init()
{
    for (int i = 0; i < MAXN; i++)
    {
        LevS[0][i] = '-';
    }
    return ;
}

int main(int argc, const char * argv[])
{
    init();
    
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    int T;
    cin >> T;
    
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        int count = N;
        for (int i = 1; i <= N; i++)
        {
            scanf("%s", LevS[i]);
        }
        
        for (int i = 1; i <= N; i++)
        {
            bool open = false;
            bool close = false;
            for (int j = 0; j < M; j++)
            {
                if (LevS[i - 1][j] == '-' && LevS[i][j] == '+')
                {
                    open = true;
                }
                else if (LevS[i - 1][j] == '+' && LevS[i][j] == '-')
                {
                    close = true;
                }
            }
            if (open)
            {
                count++;
            }
            if (close)
            {
                count++;
            }
            for (int j = 0; j < M; j++)
            {
                int pos = i;
                while (LevS[pos][j] == '?' && pos < N)
                {
                    pos++;
                }
                if (pos == i)
                {
                    continue;
                }
                if (LevS[pos][j] == LevS[i - 1][j] || LevS[pos][j] == '?')
                {
                    for (int k = i; k <= pos; k++)
                    {
                        LevS[k][j] = LevS[i - 1][j];
                    }
                }
                if (LevS[pos][j] == '+' && LevS[i - 1][j] == '-' && open)
                {
                    for (int k = i; k < pos; k++)
                    {
                        LevS[k][j] = '+';
                    }
                }
                else if (LevS[pos][j] == '+' && LevS[i - 1][j] == '-' && !open)
                {
                    LevS[i][j] = '-';
                }
                if (LevS[pos][j] == '-' && LevS[i - 1][j] == '+' && close)
                {
                    for (int k = i; k < pos; k++)
                    {
                        LevS[k][j] = '-';
                    }
                }
                else if (LevS[pos][j] == '-' && LevS[i - 1][j] == '+' && !close)
                {
                    LevS[i][j] = '+';
                }
            }
        }
        cout << count << '\n';
    }
    
    return 0;
}
