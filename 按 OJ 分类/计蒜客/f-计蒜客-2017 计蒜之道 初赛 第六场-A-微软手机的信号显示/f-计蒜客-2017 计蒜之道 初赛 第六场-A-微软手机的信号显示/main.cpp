//
//  main.cpp
//  f-计蒜客-2017 计蒜之道 初赛 第六场-A-微软手机的信号显示
//
//  Created by ZYJ on 2017/6/4.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

char map[8][8] = {"+-----+",
                  "|    G|",
                  "|     |",
                  "|     |",
                  "|     |",
                  "|     |",
                  "+-----+"};

int main(int argc, const char * argv[])
{
    int d;
    cin >> d;
    if (d >= 90)
    {
        map[1][4] = '4';
    }
    else if (d >= 60)
    {
        map[1][4] = '3';
    }
    else
    {
        map[1][5] = 'E';
    }
    
    printf("%s\n", map[0]);
    int cnt = 1;
    while (d >= 20)
    {
        for (int i = 1; i <= cnt; i++)
        {
            map[cnt][i] = '-';
        }
        printf("%s\n", map[cnt++]);
        d -= 20;
    }
    for (int i = cnt; i < 7; i++)
    {
        printf("%s\n", map[i]);
    }
    
    return 0;
}
