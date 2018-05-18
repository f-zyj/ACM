//
//  main.cpp
//  f-51Nod-1279-扔盘子
//
//  Created by ZYJ on 16/8/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 5e4 + 10;
const int INF = 1e9 + 10;

int width[MAXN] = {INF};

int main(int argc, const char * argv[])
{
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", width + i);
        if (width[i] > width[i - 1])
        {
            width[i] = width[i - 1];
        }
    }
    
    int res = 0;
    int flag = N;
    int plate;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &plate);
        for (; flag > 0; flag--)
        {
            if (width[flag] >= plate)
            {
                flag--;
                res++;
                break;
            }
        }
    }
    
    std::cout << res << '\n';
    return 0;
}
