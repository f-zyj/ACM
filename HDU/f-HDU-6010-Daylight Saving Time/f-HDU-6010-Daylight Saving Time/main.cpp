//
//  main.cpp
//  f-HDU-6010-Daylight Saving Time
//
//  Created by ZYJ on 2017/11/15.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>

using namespace std;

const int MAXN = 101;

int StoD[MAXN];
int DtoS[MAXN];

struct time
{
    int y, m, d, h, _m, s;
    
    bool operator < (const time &b) const
    {
        if (y != b.y)
        {
            return y < b.y;
        }
        else if (m != b.m)
        {
            return m < b.m;
        }
        else if (d != b.d)
        {
            return d < b.d;
        }
        else if (h != b.h)
        {
            return h < b.h;
        }
        else if (_m != b._m)
        {
            return _m < b._m;
        }
        else
        {
            return s < b.s;
        }
    }
} da;

void init()
{
    StoD[7] = 11;
    DtoS[7] = 4;
    for (int i = 8; i < MAXN; i++)
    {
        if (i % 4 || i % 100 == 0)
        {
            StoD[i] = StoD[i - 1] - 1;
            if (StoD[i] <= 7)
            {
                StoD[i] += 7;
            }
            DtoS[i] = DtoS[i - 1] - 1;
            if (DtoS[i] < 1)
            {
                DtoS[i] += 7;
            }
        }
        else
        {
            StoD[i] = StoD[i - 1] - 2;
            if (StoD[i] <= 7)
            {
                StoD[i] += 7;
            }
            DtoS[i] = DtoS[i - 1] - 2;
            if (DtoS[i] < 1)
            {
                DtoS[i] += 7;
            }
        }
    }
}

int main()
{
    init();
    
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++)
    {
        scanf("%d-%d-%d %d:%d:%d", &da.y, &da.m, &da.d, &da.h, &da._m, &da.s);
        
        time PN = {da.y, 3, StoD[da.y - 2000], 2, 0, 0};
        time NP = {da.y, 3, StoD[da.y - 2000], 3, 0, 0};
        time PB = {da.y, 11, DtoS[da.y - 2000], 1, 0, 0};
        time BP = {da.y, 11, DtoS[da.y - 2000], 2, 0, 0};
        
        printf("Case #%d: ", i);
        if (da < PN)
        {
            printf("PST\n");
        }
        else if (da < NP)
        {
            printf("Neither\n");
        }
        else if (da < PB)
        {
            printf("PDT\n");
        }
        else if (da < BP)
        {
            printf("Both\n");
        }
        else
        {
            printf("PST\n");
        }
    }
    
    return 0;
}
