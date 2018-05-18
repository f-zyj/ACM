//
//  main.cpp
//  f-HDU-5572-An Easy Physics Problem
//
//  Created by ZYJ on 2017/11/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1e-8;

int cmp(double x)
{
    if (fabs(x) < EPS)
    {
        return 0;
    }
    else
    {
        return x > 0 ? 1 : -1;
    }
}

typedef struct node
{
    double x, y;
    
    void read()
    {
        scanf("%lf%lf", &x, &y);
    }
} point, speed;

point PA, PB;
speed SA;

struct circle
{
    point o;
    int r;
    
    void read()
    {
        scanf("%lf%lf%d", &o.x, &o.y, &r);
    }
} C;

node operator + (node a, node b)
{
    return {a.x + b.x, a.y + b.y};
}

node operator - (node a, node b)
{
    return {a.x - b.x, a.y - b.y};
}

node operator * (double p, node a)
{
    return {a.x * p, a.y * p};
}

double dot(node a, node b)
{
    return a.x * b.x + a.y * b.y;
}

double dis(node a)
{
    return sqrt(dot(a, a));
}

double cross(node a, node b)
{
    return a.x * b.y - b.x * a.y;
}

node GetLine(node P, node A, node B)
{
    node V = B - A;
    node ans = A + (dot(V, P - A) / dot(V, V)) * V;
    return ans;
}

double d;
node AngleA, AngleB, head;

void GetAnglePoint(point PA, speed SA, circle C)
{
    node A = PA, B = PA + SA;
    if (dis(C.o - B) > dis(C.o - A))
    {
        A = PA + SA;
        B = PA;
    }
    head = GetLine(C.o, A, B);
    
    d = dis(head - C.o);
    if (cmp(d - C.r) < 0)
    {
        double l = sqrt((double)C.r * C.r - d * d);
        AngleA = head + l / dis(B - A) * (B - A);
        AngleB = head - l / dis(B - A) * (B - A);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        printf("Case #%d: ", ce);
        
        C.read();
        PA.read();
        SA.read();
        PB.read();
        
        GetAnglePoint(PA, SA, C);
        if (cmp(d - C.r) >= 0)
        {
            if (cmp(cross(PB - PA, SA)) == 0 && cmp(dot(PB - PA, SA)) > 0)
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
            continue;
        }
        
        node N;
        if (cmp(dis(AngleA - PA) - dis(AngleB - PA)) < 0)
        {
            N = AngleA;
        }
        else
        {
            N = AngleB;
        }
        
        int flag = 0;
        if (cmp(cross(PA - PB, N - PB)) == 0 && cmp(dot(PA - PB, N - PB)) <= 0)
        {
            flag = 1;
        }
        
        node tmp = GetLine(PA, C.o, N);
        point PA2 = PA + 2 * (tmp - PA);
        speed SA2 = N - PA2;
        if (cmp(cross(PB - N, SA2)) == 0 && cmp(dot(PB - N, SA2)) <= 0)
        {
            flag = 1;
        }
        
        if (flag)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    
    return 0;
}
