//
//  main.cpp
//  f-计蒜客-2017 ACM-ICPC 亚洲区（乌鲁木齐赛区）网络赛-B-Out-out-control cars
//
//  Created by ZYJ on 2017/9/9.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-8;

const int MAXN = 555;

//  计算机几何库
struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    Point operator + (Point a) { return Point(x + a.x, y + a.y); }
    Point operator - (Point a) { return Point(x - a.x, y - a.y); }
    Point operator * (double p) { return Point(x * p, y * p); }
    Point operator / (double p) { return Point(x / p, y / p); }
} p1[MAXN], p2[MAXN], c1[MAXN], c2[MAXN];

int dcmp(double x)
{
    if (fabs(x) < eps)
    {
        return 0;
    }
    else
    {
        return x < 0 ? -1 : 1;
    }
}

bool operator == (const Point &a, const Point &b)
{
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

bool operator < (const Point &a, const Point &b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

double Dot(Point A, Point B)
{
    return A.x * B.x + A.y * B.y;
}

double Cross(Point A, Point B)
{
    return A.x * B.y - A.y * B.x;
}

int isPointOnSegment(Point p, Point a1, Point a2)
{
    return dcmp(Cross(a1 - p, a2 - p) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0);
}

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1);
    double c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

int ConvexHull(Point *p, int n, Point *ch)
{
    sort(p, p + n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
        {
            m--;
        }
        ch[m++] = p[i];
    }
    
    int k = m;
    for (int i = n - 2; i >= 0; i--)
    {
        while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
        {
            m--;
        }
        ch[m++] = p[i];
    }
    
    if (n > 1)
    {
        m--;
    }
    return m;
}

int isPointInPolygon(Point p, Point *po, int n)
{
    int wn = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPointOnSegment(p, po[i], po[(i + 1) % n]))
        {
            return -1;
        }
        int k = dcmp(Cross(po[(i + 1) % n] - po[i], p - po[i]));
        int d1 = dcmp(po[i].y - p.y);
        int d2 = dcmp(po[(i + 1) % n].y - p.y);
        if (k > 0 && d1 <= 0 && d2 > 0)
        {
            wn++;
        }
        if (k < 0 && d2 <= 0 && d1 > 0)
        {
            wn--;
        }
    }
    if (wn != 0)
    {
        return 1;
    }
    
    return 0;
}

int checkConvexHullIntersection(Point *p, Point *q, int np, int nq)
{
    for (int i = 0; i < np; i++)
    {
        if (isPointInPolygon(p[i], q, nq))
        {
            return 1;
        }
    }
    for (int i = 0; i < nq; i++)
    {
        if (isPointInPolygon(q[i], p, np))
        {
            return 1;
        }
    }
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nq; j++)
        {
            if (SegmentProperIntersection(p[i], p[(i + 1) % np], q[j], q[(j + 1) % nq]))
            {
                return 1;
            }
        }
    }
    
    return 0;
}

void solve(Point &p, Point q, double x1, double y1)
{
    p.x = q.x + x1 * 1e10;
    p.y = q.y + y1 * 1e10;
}

int main()
{
    int T, ce = 0;
    scanf("%d", &T);
 
    while (T--)
    {
        
        double x, y;
        for (int i = 0; i < 3; i++)
        {
            scanf("%lf%lf", &x, &y);
            p1[i] = (Point){x, y};
        }
        double x1, y1, x2, y2;
        scanf("%lf%lf", &x1, &y1);
        for(int i = 0; i < 3; i++)
        {
            scanf("%lf%lf",&x,&y);
            p2[i] = (Point){x, y};
        }
        scanf("%lf%lf", &x2, &y2);
        
        x1 += x2;
        y1 += y2;
        solve(p1[3], p1[0], x1, y1);
        solve(p1[4], p1[1], x1, y1);
        solve(p1[5], p1[2], x1, y1);
        int k1 = ConvexHull(p1, 6, c1);
        int k2 = ConvexHull(p2, 3, c2);
        bool tag = checkConvexHullIntersection(c1, c2, k1, k2);
        
        printf("Case #%d: %s\n", ++ce, tag == 0 ? "YES" : "NO");
    }
    
    return 0;
}
