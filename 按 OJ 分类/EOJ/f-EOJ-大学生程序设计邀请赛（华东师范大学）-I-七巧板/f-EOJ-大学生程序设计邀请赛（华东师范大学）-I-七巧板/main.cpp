//
//  main.cpp
//  f-EOJ-大学生程序设计邀请赛（华东师范大学）-I-七巧板
//
//  Created by ZYJ on 2017/5/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 7;
const int MAXA = 23;
const double ESP = 1e-7;

double res = 0;

struct Lpoint
{
    double x, y;
};  //  点

/*
 *  要求按照逆时针方向输入多边形顶点
 *  可以是凸多边形或凹多边形
 */
double area_of_polygon(int vcount, Lpoint plg[])
{
    int i;
    double s;
    if (vcount < 3)
    {
        return 0;
    }
    s = plg[0].y * (plg[vcount - 1].x - plg[1].x);
    for (i = 1; i < vcount; i++)
    {
        s += plg[i].y * (plg[(i - 1)].x - plg[(i + 1) % vcount].x);
    }
    return s / 2;
}

Lpoint plg[MAXN];
double area[MAXA];

int main(int argc, const char * argv[])
{
    int vcount;
    int cnt_3 = 0;
    int cnt_4 = 0;
    int cnt_area = 0;
    for (int i = 0; i < MAXN; i++)
    {
        cin >> vcount;
        if (vcount == 3)
        {
            cnt_3++;
        }
        else
        {
            cnt_4++;
        }
        for (int j = 0; j < vcount; j++)
        {
            cin >> plg[j].x >> plg[j].y;
        }
        for (int j = 0; j < vcount; j++)
        {
            area[cnt_area++] = pow(plg[j].x - plg[(j + 1) % vcount].x, 2)
                             + pow(plg[j].y - plg[(j + 1) % vcount].y, 2);
        }
        res += area_of_polygon(vcount, plg);
    }
    
    if (cnt_3 != 5 || cnt_4 != 2)
    {
        cout << "NO\n";
        return 0;
    }
    
    sort(area, area + cnt_area);
    
    if (fabs(area[9] - area[0]) > ESP || fabs(area[10] - area[9]) < ESP)
    {
        cout << "NO\n";
        return 0;
    }
    if (fabs(area[15] - area[10]) > ESP || fabs(area[16] - area[15]) < ESP)
    {
        cout << "NO\n";
        return 0;
    }
    if (fabs(area[20] - area[16]) > ESP || fabs(area[21] - area[20] < ESP))
    {
        cout << "NO\n";
        return 0;
    }
    if (fabs(area[22] - area[21]) > ESP)
    {
        cout << "NO\n";
        return 0;
    }
    
    puts(fabs(area[MAXA - 1] - res) < ESP ? "YES" : "NO");

    return 0;
}
