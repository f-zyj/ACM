//
//  main.cpp
//  f-51Nod-1028-大数乘法 V2
//
//  Created by ZYJ on 2016/10/9.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const double PI = acos(-1.0);
const int MAXN = 4e5 + 10;

//  复数结构体
struct Complex
{
    double x, y;    //  实部和虚部 x + yi
    Complex(double _x = 0.0, double _y = 0.0)
    {
        x = _x;
        y = _y;
    }
    Complex operator - (const Complex &b) const
    {
        return Complex(x - b.x, y - b.y);
    }
    Complex operator + (const Complex &b) const
    {
        return Complex(x + b.x, y + b.y);
    }
    Complex operator * (const Complex &b) const
    {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

//  进行FFT和IFFT前的反转变换
//  位置i和（i二进制反转后的位置）互换
//  len必须去2的幂
void change(Complex y[], int len)
{
    int i, j, k;
    for (i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
        {
            swap(y[i], y[j]);
        }
        //  交换护卫小标反转的元素，i < j保证交换一次
        //  i做正常的+1，j左反转类型的+1，始终保持i和j是反转的
        k = len / 2;
        while (j >= k)
        {
            j -= k;
            k /= 2;
        }
        if (j < k)
        {
            j += k;
        }
    }
    return ;
}

//  FFT
//  len必须为2 ^ k形式
//  on == 1时是DFT，on == -1时是IDFT
void fft(Complex y[], int len, int on)
{
    change(y, len);
    for (int h = 2; h <= len; h <<= 1)
    {
        Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
    {
        for (int i = 0; i < len; i++)
        {
            y[i].x /= len;
        }
    }
}

//  求卷积
//  用于大数乘法
void conv(Complex a[], Complex b[], int ans[], int len)
{
    fft(a, len, 1);
    fft(b, len, 1);
    for (int i = 0; i < len; i++)
    {
        a[i] = a[i] * b[i];
    }
    fft(a, len, -1);
    //  精度复原
    for (int i = 0; i < len; i++)
    {
        ans[i] = a[i].x + 0.5;
    }
}

//  进制恢复
//  用语大数乘法
void turn(int ans[], int len, int unit)
{
    for (int i = 0; i < len; i++)
    {
        ans[i + 1] += ans[i] / unit;
        ans[i] %= unit;
    }
}

char str_1[MAXN], str_2[MAXN];
Complex za[MAXN], zb[MAXN];
int ans[MAXN];
int len;

void init(char str_1[], char str_2[])
{
    int len_1 = (int)strlen(str_1);
    int len_2 = (int)strlen(str_2);
    len = 1;
    
    while (len < 2 * len_1 || len < 2 * len_2)
    {
        len <<= 1;
    }
    
    int i = 0;
    for (; i < len_1; i++)
    {
        za[i].x = str_1[len_1 - i - 1] - '0';
        za[i].y = 0.0;
    }
    while (i < len)
    {
        za[i].x = za[i].y = 0.0;
        i++;
    }
    for (i = 0; i < len_2; i++)
    {
        zb[i].x = str_2[len_2 - i - 1] - '0';
        zb[i].y = 0.0;
    }
    while (i < len)
    {
        zb[i].x = zb[i].y = 0.0;
        i++;
    }
    
    return ;
}

void solve()
{
    conv(za, zb, ans, len);
    turn(ans, len, 10);
    while (ans[len - 1] == 0)
    {
        len--;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%d", ans[i]);
    }
    printf("\n");
    
    return ;
}

int main()
{
    while (~scanf("%s%s", str_1, str_2))
    {
        init(str_1, str_2);
        solve();
    }
    
    return 0;
}
