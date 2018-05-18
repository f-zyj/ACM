//
//  main.cpp
//  f-星期问题
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>


/*
 *  已知1752年9月3日是Sunday，并且日期控制在1700年2月28日后
 */
char name[][15] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main()
{
    int d, m, y, a;
    printf("Day: ");
    scanf("%d", &d);
    printf("Month: ");
    scanf("%d", &m);
    printf("Year: ");
    scanf("%d", &y);
    //  1月2月当作前一年的13,14月
    if (m == 1 || m == 2)
    {
        m += 12;
        y--;
    }
    //  判断是否在1752年9月3日之前,实际上合并在一起倒更加省事
    if ((y < 1752) || (y == 1752 && m < 9) || (y == 1752 && m == 9 && d < 3))
    {
        //  因为日期控制在1700年2月28日后，所以不用考虑整百年是否是闰年
        a = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 + 5) % 7;
    }
    else
    {
        //  这里需要考虑整百年是否是闰年的情况
        a = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;  //  实际上这个可以当做公式背下来
    }
    printf("it's a %s\n", name[a]);
    return 0;
}