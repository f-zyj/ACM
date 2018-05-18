//
//  main.cpp
//  f-旋转卡壳
//
//  Created by ZYJ on 16/7/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

//  求解平面最远点对

/*
struct Point
{
    int x, y;
    Point(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
    Point operator - (const Point &b)const
    {
        return Point(x - b.x, y - b.y);
    }
    int operator ^(const Point &b)const
    {
        return x * b.y - y * b.x;
    }
    int operator *(const Point &b)const
    {
        return x * b.x + y * b.y;
    }
    void input()
    {
        scanf("%d%d", &x, &y);
        return ;
    }
};

//  距离的平方
int dist2(Point a, Point b)
{
    return (a - b) * (a - b);
}

//  二维凸包,int
const int MAXN = 50010;
Point list[MAXN];
int Stack[MAXN], top;
bool _cmp(Point p1, Point p2)
{
    int tmp = (p1 - list[0]) ^ (p2 - list[0]);
    if (tmp > 0)
    {
        return true;
    }
    else if (tmp == 0 && dist2(p1, list[0]) <= dist2(p2, list[0]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Graham(int n)
{
    Point p0;
    int k = 0;
    p0 = list[0];
    for (int i = 1; i < n; i++)
    {
        if (p0.y > list[i].y || (p0.y == list[i].y && p0.x > list[i].x))
        {
            p0 = list[i];
            k = i;
        }
    }
    swap(list[k], list[0]);
    sort(list + 1, list + n, _cmp);
    if (n == 1)
    {
        top = 1;
        Stack[0] = 0;
        return ;
    }
    if (n == 2)
    {
        top = 2;
        Stack[0] = 0;
        Stack[1] = 1;
        return ;
    }
    Stack[0] = 0;
    Stack[1] = 1;
    top = 2;
    for (int i = 2; i < n; i++)
    {
        while (top > 1 && ((list[Stack[top - 1]] - list[Stack[top - 2]]) ^ (list[i] - list[Stack[top - 2]])) <= 0)
        {
            top--;
        }
        Stack[top++] = i;
    }
    return ;
}
 */
//
////  旋转卡壳,求两点间距离平方的最大值
//int rotating_calipers(Point p[],int n)
//{
//    int ans = 0;
//    Point v;
//    int cur = 1;
//    for (int i = 0; i < n; i++)
//    {
//        v = p[i] - p[(i + 1) % n];
//        while ((v ^ (p[(cur + 1) % n] - p[cur])) < 0)
//        {
//            cur = (cur + 1) % n;
//        }
//        ans = max(ans, max(dist2(p[i], p[cur]), dist2(p[(i + 1) % n], p[(cur + 1) % n])));
//    }
//    return ans;
//}
//
//Point p[MAXN];
//
//int main()
//{
//    int n;
//    while (scanf("%d", &n) == 1)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            list[i].input();
//        }
//        Graham(n);
//        for (int i = 0; i < top; i++)
//        {
//            p[i] = list[Stack[i]];
//        }
//        printf("%d\n", rotating_calipers(p, top));
//    }
//    return 0;
//}

//  求解平面点集最大三角形

//  旋转卡壳计算平面点集最大三角形面积
//int rotating_calipers(Point p[], int n)
//{
//    int ans = 0;
//    Point v;
//    for (int i = 0; i < n; i++)
//    {
//        int j = (i + 1) % n;
//        int k = (j + 1) % n;
//        while (j != i && k != i)
//        {
//            ans = max(ans, abs((p[j] - p[i]) ^ (p[k] - p[i])));
//            while (((p[i] - p[j]) ^ (p[(k + 1) % n] - p[k])) < 0)
//            {
//                k = (k + 1) % n;
//            }
//            j = (j + 1) % n;
//        }
//    }
//    return ans;
//}
//
//Point p[MAXN];
//
//int main()
//{
//    int n;
//    while (scanf("%d",&n) == 1)
//    {
//        if (n == -1)
//        {
//            break;
//        }
//        for (int i = 0; i < n; i++)
//        {
//            list[i].input();
//        }
//        Graham(n);
//        for (int i = 0; i < top; i++)
//        {
//            p[i] = list[Stack[i]];
//        }
//        printf("%.2f\n", (double)rotating_calipers(p, top) / 2);
//    }
//    return 0;
//}

//  求解两凸包最小距离

const double eps = 1e-8;

int sgn(double x)
{
    if (fabs(x) < eps)
    {
        return 0;
    }
    if (x < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

struct Point
{
    double x, y;
    Point(double _x = 0, double _y = 0)
    {
        x = _x;
        y = _y;
    }
    Point operator - (const Point &b)const
    {
        return Point(x - b.x, y - b.y);
    }
    double operator ^ (const Point &b)const
    {
        return x * b.y - y * b.x;
    }
    double operator * (const Point &b)const
    {
        return x * b.x + y * b.y;
    }
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
};

struct Line
{
    Point s, e;
    Line(){}
    Line(Point _s, Point _e)
    {
        s = _s;
        e = _e;
    }
};

//  两点间距离
double dist(Point a, Point b)
{
    return sqrt((a - b) * (a - b));
}

//  点到线段的距离,返回点到线段最近的点
Point NearestPointToLineSeg(Point P, Line L)
{
    Point result;
    double t = ((P - L.s) * (L.e - L.s)) / ((L.e - L.s) * (L.e - L.s));
    if (t >=0 && t <= 1)
    {
        result.x = L.s.x + (L.e.x - L.s.x) * t;
        result.y = L.s.y + (L.e.y - L.s.y) * t;
    }
    else
    {
        if (dist(P,L.s) < dist(P,L.e))
        {
            result = L.s;
        }
        else
        {
            result = L.e;
        }
    }
    return result;
}

/*
 * 求凸包,Graham算法
 * 点的编号0~n-1
 * 返回凸包结果Stack[0~top-1]为凸包的编号 
 */
const int MAXN = 10010;
Point list[MAXN];
int Stack[MAXN], top;   //  相对于list[0]的极角排序
bool _cmp(Point p1, Point p2)
{
    double tmp = (p1 - list[0]) ^ (p2 - list[0]);
    if (sgn(tmp) > 0)
    {
        return true;
    }
    else if (sgn(tmp) == 0 && sgn(dist(p1, list[0]) - dist(p2, list[0])) <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Graham(int n)
{
    Point p0;
    int k = 0;
    p0 = list[0];   //  找最下边的一个点
    for (int i = 1; i < n; i++)
    {
        if ((p0.y > list[i].y) || (p0.y == list[i].y && p0.x > list[i].x))
        {
            p0 = list[i];
            k = i;
        }
    }
    swap(list[k], list[0]);
    sort(list + 1, list + n, _cmp);
    if (n == 1)
    {
        top = 1;
        Stack[0] = 0;
        return ;
    }
    if (n == 2)
    {
        top = 2;
        Stack[0] = 0;
        Stack[1] = 1;
        return ;
    }
    Stack[0] = 0;
    Stack[1] = 1;
    top = 2;
    for (int i = 2; i < n; i++)
    {
        while (top > 1 && sgn((list[Stack[top - 1]] - list[Stack[top - 2]]) ^ (list[i] - list[Stack[top - 2]])) <= 0)
        {
            top--;
        }
        Stack[top++] = i;
    }
    return ;
}

//  点p0到线段p1p2的距离
double pointtoseg(Point p0, Point p1, Point p2)
{
    return dist(p0, NearestPointToLineSeg(p0, Line(p1, p2)));
}

//  平行线段p0p1和p2p3的距离
double dispallseg(Point p0, Point p1, Point p2, Point p3)
{
    double ans1 = min(pointtoseg(p0, p2, p3), pointtoseg(p1, p2, p3));
    double ans2 = min(pointtoseg(p2, p0, p1), pointtoseg(p3, p0, p1));
    return min(ans1, ans2);
}

//  得到向量a1a2和b1b2的位置关系
double Get_angle(Point a1, Point a2, Point b1, Point b2)
{
    return (a2 - a1) ^ (b1 - b2);
}

double rotating_calipers(Point p[], int np, Point q[], int nq)
{
    int sp = 0, sq = 0;
    for (int i = 0; i < np; i++)
    {
        if (sgn(p[i].y - p[sp].y) < 0)
        {
            sp = i;
        }
    }
    for (int i = 0; i < nq; i++)
    {
        if (sgn(q[i].y - q[sq].y) > 0)
        {
            sq = i;
        }
    }
    double tmp;
    double ans = dist(p[sp], q[sq]);
    for (int i = 0; i < np; i++)
    {
        while (sgn(tmp = Get_angle(p[sp], p[(sp + 1) % np], q[sq], q[(sq + 1) % nq])) < 0)
        {
            sq = (sq + 1) % nq;
        }
        if (sgn(tmp) == 0)
        {
            ans = min(ans, dispallseg(p[sp], p[(sp + 1) % np], q[sq], q[(sq + 1) % nq]));
        }
        else
        {
            ans = min(ans, pointtoseg(q[sq], p[sp], p[(sp + 1) % np]));
        }
        sp = (sp + 1) % np;
    }
    return ans;
}

double solve(Point p[], int n, Point q[], int m)
{
    return min(rotating_calipers(p, n, q, m), rotating_calipers(q, m, p, n));
}

Point p[MAXN], q[MAXN];

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            list[i].input();
        }
        Graham(n);
        for (int i = 0; i < top; i++)
        {
            p[i] = list[i];
        }
        n = top;
        for (int i = 0; i < m; i++)
        {
            list[i].input();
        }
        Graham(m);
        for (int i = 0; i < top; i++)
        {
            q[i] = list[i];
        }
        m = top;
        printf("%.4f\n", solve(p, n, q, m));
    }
    return 0;
}


