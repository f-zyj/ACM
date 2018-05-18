//
//  main.cpp
//  f-SHU-“盛大游戏杯”第15届上海大学程序设计联赛夏季赛暨上海高校金马五校赛-B-神无月排位赛
//
//  Created by ZYJ on 2017/7/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int N;

int main(int argc, const char * argv[])
{
    int level, score;
    while (cin >> N)
    {
        level = 3;
        score = 0;
        
        int x, y;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &x);
            if (x)
            {
                score += 10;
            }
            else
            {
                score -= 5;
            }
            if (score < 0)
            {
                score = 0;
            }
            if (score >= 100)
            {
                if (i + 2 >= N)
                {
                    continue;
                }
                scanf("%d%d", &x, &y);
                if (x == y)
                {
                    if (x)
                    {
                        level--;
                        score = 0;
                    }
                    else
                    {
                        score = 60;
                    }
                    i += 2;
                    continue;
                }
                if (i + 3 >= N)
                {
                    continue;
                }
                scanf("%d", &x);
                if (x)
                {
                    level--;
                    score = 0;
                }
                else
                {
                    score = 60;
                }
                i += 3;
            }
        }
        
        if (level < 0)
        {
            puts("S");
        }
        else
        {
            putchar('A' + level);
            putchar(10);
        }
    }
    
    return 0;
}
