//
//  main.cpp
//  f-Liuctic的计算几何库
//
//  Created by ZYJ on 16/7/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

/*
 *  Liuctic 的计算几何库
 *  p-Lpoint ln,l - Lline ls - Llineseglr - Lrad
 *  求平面上两点之间的距离            p2pdis
 *  返回(P1-P0)*(P2-P0)的叉积       xmulti
 *  确定两条线段是否相交              lsinterls
 *  判断点p是否在线段l上             ponls
 *  判断两个点是否相等               Euqal_Point
 *  线段非端点相交                  lsinterls_A
 *  判断点q是否在多边形Polygon内      pinplg
 *  多边形的面积                     area_of_polygon
 *  解二次方程                       Ax^2+Bx+C=0 equa
 *  点到直线距离                     p2lndis
 *  直线与圆的交点,已知直线与圆相交     lncrossc
 *  点是否在射线的正向               samedir
 *  射线与圆的第一个交点              lrcrossc
 *  求点p1关于直线ln的对称点p2        mirror
 *  两直线夹角(弧度)                angle_LL
 */
#define infinity 1e20
#define EP 1e-10

const int MAXV = 300;
const double PI = 2.0 * asin(1.0);  //  高精度PI

struct Lpoint
{
    double x, y;
};  //  点
struct Llineseg
{
    Lpoint a, b;
};  //  线段
struct Ldir
{
    double dx, dy;
};  //  方向向量
struct Lline
{
    Lpoint p;
    Ldir dir;
};  //  直线
struct Lrad
{
    Lpoint Sp;
    Ldir dir;
};  //  射线
struct Lround
{
    Lpoint co;
    double r;
};  //  圆

//  求平面上两点之间的距离

double p2pdis(Lpoint p1, Lpoint p2)
{
    return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}

//  (P1-P0)*(P2-P0)的叉积

/*
 *  若结果为正,则<P0,P1>在<P0,P2>的顺时针方向; 
 *  若为0则<P0,P1><P0,P2>共线;
 *  若为负则<P0,P1>在<P0,P2>的在逆时针方向; 
 *  可以根据这个函数确定两条线段在交点处的转向,比如确定p0p1和p1p2在p1处是左转还是右转,只要求(p2-p0)*(p1-p0),
 *  若<0则左转,>0则右转,=0则共线
 */
double xmulti(Lpoint p1, Lpoint p2, Lpoint p0)
{
    return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
}

//  确定两条线段是否相交

double mx(double t1, double t2)
{
    if (t1 > t2)
    {
        return t1;
    }
    return t2;
}
double mn(double t1, double t2)
{
    if (t1 < t2)
    {
        return t1;
    }
    return t2;
}
int lsinterls(Llineseg u, Llineseg v)
{
    return ((mx(u.a.x, u.b.x) >= mn(v.a.x, v.b.x)) && (mx(v.a.x, v.b.x) >= mn(u.a.x, u.b.x)) && (mx(u.a.y, u.b.y) >= mn(v.a.y, v.b.y)) && (mx(v.a.y, v.b.y) >= mn(u.a.y, u.b.y)) && (xmulti(v.a, u.b, u.a) * xmulti(u.b, v.b, u.a) >= 0) && (xmulti(u.a, v.b, v.a) * xmulti(v.b, u.b, v.a) >= 0));
}

//  判断点p是否在线段l上

int ponls(Llineseg l, Lpoint p)
{
    return ((xmulti(l.b, p, l.a) == 0) && (((p.x - l.a.x) * (p.x - l.b.x) < 0) || ((p.y - l.a.y) * (p.y - l.b.y) < 0)));
}

//  判断两个点是否相等

int Euqal_Point(Lpoint p1, Lpoint p2)
{
    return ((fabs(p1.x - p2.x) < EP) && (fabs(p1.y - p2.y) < EP));
}

//  线段相交判断函数

/*
 *  当且仅当u,v相交并且交点不是u,v的端点时函数为true;
 */
int lsinterls_A(Llineseg u, Llineseg v)
{
    return ((lsinterls(u, v)) && (!Euqal_Point(u.a, v.a)) && (!Euqal_Point(u.a, v.b)) && (!Euqal_Point(u.b, v.a)) && (!Euqal_Point(u.b, v.b)));
}

//  判断点q是否在多边形内

/*
 *  其中多边形是任意的凸或凹多边形,
 *  Polygon中存放多边形的逆时针顶点序列
 */
int pinplg(int vcount, Lpoint Polygon[], Lpoint q)
{
    int c = 0, i, n;
    Llineseg l1, l2;
    l1.a = q;
    l1.b = q;
    l1.b.x = infinity;
    n = vcount;
    for (i = 0; i < vcount; i++)
    {
        l2.a = Polygon[i];
        l2.b = Polygon[(i + 1) % n];
        if ((lsinterls_A(l1, l2)) || ((ponls(l1, Polygon[(i + 1) % n])) && (((!ponls(l1, Polygon[(i + 2) % n])) && (xmulti(Polygon[i], Polygon[(i + 1) % n], l1.a) * xmulti(Polygon[(i + 1) % n], Polygon[(i + 2) % n], l1.a) > 0)) || ((ponls(l1, Polygon[(i + 2) % n])) && (xmulti(Polygon[i], Polygon[(i + 2) % n], l1.a) * xmulti(Polygon[(i + 2) % n], Polygon[(i + 3) % n], l1.a) > 0)))))
        {
            c++;
        }
    }
    return (c % 2 != 0);
}

//  多边形的面积

/*
 *  要求按照逆时针方向输入多边形顶点
 *  可以是凸多边形或凹多边形 
 */
double area_of_polygon(int vcount, double x[], double y[], Lpoint plg[])
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

//  解二次方程 Ax^2+Bx+C=0

/*
 *  返回-1表示无解 返回1 表示有解
 */
int equa(double A, double B, double C, double &x1, double &x2)
{
    double f = B * B - 4 * A * C;
    if (f < 0)
    {
        return -1;
    }
    x1 = (-B + sqrt(f)) / (2 * A);
    x2 = (-B - sqrt(f)) / (2 * A);
    return 1;
}

//  计算直线的一般式 Ax+By+C=0

void format(Lline ln, double &A, double &B, double &C)
{
    A = ln.dir.dy;
    B = -ln.dir.dx;
    C = ln.p.y * ln.dir.dx - ln.p.x * ln.dir.dy;
    return ;
}

//  点到直线距离

double p2ldis(Lpoint a, Lline ln)
{
    double A, B, C;
    format(ln, A, B, C);
    return (fabs(A * a.x + B * a.y + C) / sqrt(A * A + B * B));
}

//  直线与圆的交点,已知直线与圆相交

int lncrossc(Lline ln, Lround Y, Lpoint &p1, Lpoint &p2)
{
    double A, B, C, t1, t2;
    int zz = -1;
    format(ln, A, B, C);
    if (fabs(B) < 1e-8)
    {
        p1.x = p2.x = -1.0 * C / A;
        zz = equa(1.0, -2.0 * Y.co.y, Y.co.y * Y.co.y + (p1.x - Y.co.x) * (p1.x - Y.co.x) - Y.r * Y.r, t1, t2);
        p1.y = t1;
        p2.y = t2;
    }
    else if (fabs(A) < 1e-8)
    {
        p1.y = p2.y = -1.0 * C / B;
        zz = equa(1.0, -2.0 * Y.co.x, Y.co.x * Y.co.x + (p1.y - Y.co.y) * (p1.y - Y.co.y) - Y.r * Y.r, t1, t2);
        p1.x = t1;
        p2.x = t2;
    }
    else
    {
        zz = equa(A * A + B * B, 2.0 * A * C + 2.0 * A * B * Y.co.y - 2.0 * B * B * Y.co.x, B * B * Y.co.x * Y.co.x + C * C + 2* B * C * Y.co.y + B * B * Y.co.y * Y.co.y - B * B * Y.r * Y.r, t1, t2);
        p1.x = t1, p1.y = -1 * (A / B * t1 + C / B);
        p2.x = t2, p2.y = -1 * (A / B * t2 + C / B);
    }
    return 0;
}

//  点是否在射线的正向

bool samedir(Lrad ln, Lpoint P)
{
    double ddx, ddy;
    ddx = P.x - ln.Sp.x;
    ddy = P.y - ln.Sp.y;
    if ((ddx * ln.dir.dx > 0 || fabs(ddx * ln.dir.dx) < 1e-7) && (ddy * ln.dir.dy > 0 || (fabs(ddy * ln.dir.dy) < 1e-7)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//  射线与圆的第一个交点

/*
 *  已经确定射线所在直线与圆相交返回-1表示不存正向交点,否则返回1 
 */
int lrcrossc(Lrad ln, Lround Y, Lpoint &P)
{
    Lline ln2;
    Lpoint p1, p2;
    int res = -1;
    double dis = 1e20;
    ln2.p = ln.Sp, ln2.dir = ln.dir;
    lncrossc(ln2, Y, p1, p2);
    if (samedir(ln, p1))
    {
        res = 1;
        if (p2pdis(p1, ln.Sp) < dis)
        {
            dis = p2pdis(p1, ln.Sp);
        }
        P = p1;
    }
    if (samedir(ln, p2))
    {
        res = 1;
        if (p2pdis(p2, ln.Sp) < dis)
        {
            dis = p2pdis(p2, ln.Sp);
            P = p2;
        }
    }
    return res;
}

//  求点p1关于直线ln的对称点p2

Lpoint mirror(Lpoint P, Lline ln)
{
    Lpoint Q;
    double A, B, C;
    format(ln, A, B, C);
    Q.x = ((B * B - A * A) * P.x - 2 * A * B * P.y - 2 * A * C) / (A * A + B * B);
    Q.y = ((A * A - B * B) * P.y - 2 * A * B * P.x - 2 * B * C) / (A * A + B * B);
    return Q;
}

//  两直线夹角(弧度)

double angle_LL(Lline line1, Lline line2)
{
    double A1, B1, C1;
    format(line1, A1, B1, C1);
    double A2, B2, C2;
    format(line2, A2, B2, C2);
    if (A1 * A2 + B1 * B2 == 0)
    {
        return PI / 2.0;    //  垂直
    }
    else
    {
        double t = fabs((A1 * B2 - A2 * B1) / (A1 * A2 + B1 * B2));
        return atan(t);
    }
}