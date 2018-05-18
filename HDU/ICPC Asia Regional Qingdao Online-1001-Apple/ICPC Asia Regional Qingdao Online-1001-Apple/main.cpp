//
//  main.cpp
//  ICPC Asia Regional Qingdao Online-1001-Apple
//
//  Created by ZYJ on 2017/9/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

using namespace std;

typedef long long ll;

///*
// *  < , <= , + , - , * , / , %(修改/的最后一行可得)
// */
//const int base = 10000;     //  (base^2) fit into int
//const int width = 4;        //  width = log_10(base)
//const int MAXN = 100000;    //  MAXN * width: 可表示的最大位数
//const int MAXC = 1e5 + 10;
//
//struct bint
//{
//    int ln, v[MAXN];
//    
//    bint (int r = 0)
//    {
//        //  r应该是字符串!
//        for (ln = 0; r > 0; r /= base)
//        {
//            v[ln++] = r % base;
//        }
//    }
//    
//    bint &operator = (const bint &r)
//    {
//        memcpy(this, &r, (r.ln + 1) * sizeof(int));
//        return *this;
//    }
//};
//
//bool operator < (const bint &a, const bint &b)
//{
//    int i;
//    if (a.ln != b.ln)
//    {
//        return a.ln < b.ln;
//    }
//    for (i = a.ln - 1; i >= 0 && a.v[i] == b.v[i]; i--) ;
//    
//    return i < 0 ? 0 : a.v[i] < b.v[i];
//}
//
//bool operator <= (const bint &a, const bint &b)
//{
//    return !(b < a);
//}
//
//bint operator + (const bint &a, const bint &b)
//{
//    bint res;
//    int i, cy = 0;
//    for (i = 0; i < a.ln || i < b.ln || cy > 0; i++)
//    {
//        if (i < a.ln)
//        {
//            cy += a.v[i];
//        }
//        if (i < b.ln)
//        {
//            cy += b.v[i];
//        }
//        res.v[i] = cy % base;
//        cy /= base;
//    }
//    res.ln = i;
//    
//    return res;
//}
//
//bint operator - (const bint &a, const bint &b)
//{
//    bint res;
//    int i, cy = 0;
//    for (res.ln = a.ln, i = 0; i < res.ln; i++)
//    {
//        res.v[i] = a.v[i] - cy;
//        if (i < b.ln)
//        {
//            res.v[i] -= b.v[i];
//        }
//        if (res.v[i] < 0)
//        {
//            cy = 1, res.v[i] += base;
//        }
//        else
//        {
//            cy = 0;
//        }
//    }
//    while (res.ln > 0 && res.v[res.ln - 1] == 0)
//    {
//        res.ln--;
//    }
//    
//    return res;
//}
//
//bint operator * (const bint &a, const bint &b)
//{
//    bint res;
//    res.ln = 0;
//    if (0 == b.ln)
//    {
//        res.v[0] = 0;
//        return res;
//    }
//    int i, j, cy;
//    for (i = 0; i < a.ln; i++)
//    {
//        for (j = cy = 0; j < b.ln || cy > 0; j++, cy /= base)
//        {
//            if (j < b.ln)
//            {
//                cy += a.v[i] * b.v[j];
//            }
//            if (i + j < res.ln)
//            {
//                cy += res.v[i + j];
//            }
//            if (i + j >= res.ln)
//            {
//                res.v[res.ln++] = cy % base;
//            }
//            else
//            {
//                res.v[i + j] = cy % base;
//            }
//        }
//    }
//    
//    return res;
//}
//
//bint operator / (const bint &a, const bint &b)
//{   //  !b != 0
//    bint tmp, mod, res;
//    int i, lf, rg, mid;
//    mod.v[0] = mod.ln = 0;
//    for (i = a.ln - 1; i >= 0; i--)
//    {
//        mod = mod * base + a.v[i];
//        for (lf = 0, rg = base -1; lf < rg;)
//        {
//            mid = (lf + rg + 1) / 2;
//            if (b * mid <= mod)
//            {
//                lf = mid;
//            }
//            else
//            {
//                rg = mid - 1;
//            }
//        }
//        res.v[i] = lf;
//        mod = mod - b * lf;
//    }
//    res.ln = a.ln;
//    while (res.ln > 0 && res.v[res.ln - 1] == 0)
//    {
//        res.ln--;
//    }
//    
//    return res;     //  return mod; 就是%运算
//}
//
//int digits(bint& a) //  返回位数
//{
//    if (a.ln == 0)
//    {
//        return 0;
//    }
//    int l = (a.ln - 1) * 4;
//    for (int t = a.v[a.ln - 1]; t; ++l, t /= 10);
//    
//    return l;
//}
//
//bool read(bint &b, char buf[])  //  读取失败返回0
//{
//    if (1 != scanf("%s", buf))
//    {
//        return 0;
//    }
//    int w, u, ln = (int)strlen(buf);
//    memset(&b, 0, sizeof(bint));
//    if ('0' == buf[0] && 0 == buf[1])
//    {
//        return 1;
//    }
//    for (w = 1, u = 0; ln; )
//    {
//        u += (buf[--ln] - '0') * w;
//        if (w * 10 == base)
//        {
//            b.v[b.ln++] = u;
//            w = 1;
//            u = 0;
//        }
//        else
//        {
//            w *= 10;
//        }
//    }
//    if (w != 1)
//    {
//        b.v[b.ln++] = u;
//    }
//    
//    return 1;
//}
//
//void write(const bint &v)
//{
//    int i;
//    printf("%d", v.ln == 0 ? 0 : v.v[v.ln - 1]);
//    for (i = v.ln - 2; i >= 0; i--)
//    {
//        printf("%04d", v.v[i]); //  !!! 4 == width
//    }
//    printf("\n");
//    
//    return ;
//}
//
//char buf[MAXC];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
//    int x1, y1, x2, y2, x3, y3, x, y;
//    bint a, b, c, g, e, f, X, Y, R, R_;
//    while (T--)
//    {
//        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y;
//        
//        e = 2 * (x2 - x1);
//        f = 2 * (y2 - y1);
//        g = x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1;
//        a = 2 * (x3 - x2);
//        b = 2 * (y3 - y2);
//        c = x3 * x3 - x2 * x2 + y3 * y3 - y2 * y2;
//        X = (g * b - c * f) / (e * b - a * f);
//        Y = (a * g - c * e) / (a * f - b * e);
//        R = (X - x1) * (X - x1) + (Y - y1) * (Y - y1);
//        R_ = (X - x) * (X - x) + (Y - y) * (Y - y);
//        
//        if (R_ < R)
//        {
//            cout << "Rejected\n";
//        }
//        else
//        {
//            cout << "Accepted\n";
//        }
//    }
    
    return 0;
}

