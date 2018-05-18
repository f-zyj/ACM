//
//  main.cpp
//  f-51Nod-1059-N的阶乘 V2
//
//  Created by ZYJ on 2017/8/30.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

struct complex
{
    double real, imag;
    
    complex(double real1 = 0.0, double imag1 = 0.0)
    {
        real = real1;
        imag = imag1;
    }
    
    void operator == (const complex &a)
    {
        real = a.real;
        imag = a.imag;
    }
};

complex operator * (const complex &n1, const complex &n2)
{
    return complex(n1.real * n2.real - n1.imag * n2.imag, n1.real * n2.imag + n1.imag * n2.real);
}

complex operator + (const complex &n1, const complex &n2)
{
    return complex(n1.real + n2.real, n1.imag + n2.imag);
}

complex operator - (const complex &n1, const complex &n2)
{
    return complex(n1.real - n2.real, n1.imag - n2.imag);
}

const static int WORDSIZE = 500000;
const static int SIZEN = 262144;
const static int MOD = 10000;
const static int N = 100000;

int cnta1, cntb1;
int a1[SIZEN];
int b1[SIZEN];
int rev[SIZEN];
char word[WORDSIZE];
complex e1[SIZEN >> 1];
complex e2[SIZEN >> 1];
complex A[SIZEN];
complex w1[SIZEN];
complex w2[SIZEN];

struct BigInteger
{
    int l, r;
};

int cntp1, cntq1;
BigInteger p1[N];
BigInteger q1[N];

void Reverse(int N, int bitlength)
{
    for (int i = 0; i < N; i++)
    {
        int temp = i, len = bitlength;
        while (temp)
        {
            rev[i] |= (temp & 1) << (len--);
            temp >>= 1;
        }
    }
}

void DFT(complex *A, complex *w1, complex *e, int N)
{
    int k = SIZEN / N;
    int bit = 0;
    while (k)
    {
        bit++;
        k >>= 1;
    }
    for (int i = 0; i < N; i++)
    {
        w1[i] = A[rev[i] >> bit];
    }
    for (int h = 2; h <= N; h <<= 1)
    {
        int h1 = h, bit1 = -1;
        while (h1)
        {
            bit1++;
            h1 >>= 1;
        }
        for (int i = 0; i < N; i += h)
        {
            int k = h >> 1, q = SIZEN >> bit1;
            for (int j = i; j < i + k; j++)
            {
                complex u = w1[j];
                complex t = e[q*(j - i)] * w1[j + k];
                w1[j] = u + t;
                w1[j + k] = u - t;
            }
        }
    }
}

void Multiplication(int l1, int r1, int l2, int r2, int *a, int *b, int &cntb)
{
    int length1 = r1 - l1, length2 = r2 - l2;
    if (length1 <= 40 && length2 <= 40)
    {
        int tempcntb = cntb + length1 + length2 + 1;
        for (int i = cntb; i <= tempcntb; i++)
        {
            b[i] = 0;
        }
        tempcntb = cntb;
        for (int i = l1; i < r1; i++)
        {
            int number = a[i];
            for (int j = l2; j < r2; j++)
            {
                int pos = cntb + i + j - l1 - l2;
                b[pos] += a[j] * number;
                if (b[pos] >= MOD)
                {
                    b[pos + 1] += b[pos] / MOD;
                    b[pos] %= MOD;
                }
            }
        }
        int length = length1 + length2 + 1 + tempcntb;
        for (int k = tempcntb; k <= length; k++)
        {
            if (b[k] != 0)
            {
                cntb = k + 1;
            }
        }
        
        return ;
    }
    
    int tempLength = max(length1, length2);
    int N = 1, bitlength = 0;
    while (N < tempLength)
    {
        N <<= 1;
        bitlength++;
    }
    N <<= 1;
    for (int i = 0; i < length1; i++)
    {
        A[i] = complex(a[i + l1], 0);
    }
    for (int i = length1; i < N; i++)
    {
        A[i] = complex(0, 0);
    }
    DFT(A, w1, e1, N);
    for (int i = 0; i < length2; i++)
    {
        A[i] = complex(a[i + l2], 0);
    }
    for (int i = length2; i < N; i++)
    {
        A[i] = complex(0, 0);
    }
    DFT(A, w2, e1, N);
    for (int i = 0; i < N; i++)
    {
        A[i] = w2[i] * w1[i];
    }
    DFT(A, w1, e2, N);
    ull temp = 0, temp1 = 0;
    int anslength = 0, lastcntb = cntb;
    double ND = N;
    for (int i = 0; i < N; i++)
    {
        temp += w1[i].real / ND + 0.1;
        temp1 = temp / MOD; temp %= MOD;
        b[cntb++] = (int)temp;
        if (temp != 0)
        {
            anslength = i + 1;
        }
        temp = temp1;
    }
    cntb = lastcntb + anslength;
}

void Print(int len, int *a)
{
    char *out = word + WORDSIZE;
    *(--out) = '\n';
    int linesize = 1000;
    int cnt = len * 4;
    if (a[len - 1] <= 9)
    {
        cnt -= 3;
    }
    else if (a[len - 1] <= 99)
    {
        cnt -= 2;
    }
    else if (a[len - 1] <= 999)
    {
        cnt--;
    }
    cnt %= linesize;
    cnt = linesize - cnt;
    for (int i = 0; i < len; i++)
    {
        int number = a[i];
        *(--out) = number % 10 + '0';
        number /= 10;
        if (++cnt == linesize)
        {
            *(--out) = '\n'; cnt = 0;
        }
        *(--out) = number % 10 + '0';
        number /= 10;
        if (++cnt == linesize)
        {
            *(--out) = '\n'; cnt = 0;
        }
        *(--out) = number % 10 + '0';
        number /= 10;
        if (++cnt == linesize)
        {
            *(--out) = '\n'; cnt = 0;
        }
        *(--out) = number % 10 + '0';
        number /= 10;
        if (++cnt == linesize)
        {
            *(--out) = '\n'; cnt = 0;
        }
    }
    
    while (*out == '0' || *out == '\n')
    {
        out++;
    }
    fwrite(out, 1, word + WORDSIZE - out, stdout);
}

void factorial()
{
    BigInteger *p = p1, *q = q1;
    int cntp = cntp1, cntq = cntq1;
    int cnta = cnta1, cntb = cntb1;
    int *a = a1, *b = b1;
    while (1)
    {
        if (cntp == 1)
        {
            Print(p[0].r, a);
            break;
        }
        for (int i = 0; i < (cntp >> 1); i++)
        {
            q[cntq].l = cntb;
            Multiplication(p[i].l, p[i].r, p[cntp - i - 1].l, p[cntp - i - 1].r, a, b, cntb);
            q[cntq++].r = cntb;
        }
        if ((cntp & 1) == 1)
        {
            q[cntq].l = cntb;
            int l = p[(cntp >> 1)].l;
            int r = p[(cntp >> 1)].r;
            for (int i = l; i < r; i++)
            {
                b[cntb++] = a[i];
            }
            q[cntq++].r = cntb;
        }
        swap(p, q);
        swap(a, b);
        swap(cntp, cntq);
        swap(cnta, cntb);
        cntq = 0;
        cntb = 0;
    }
}

void init(int n)
{
    int l = 0;
    int n1 = min(n, 99);
    int number = 1;
    for (int i = 1; i <= n1; i++)
    {
        if (number * i >= MOD)
        {
            a1[cnta1++] = number;
            p1[cntp1].l = l;
            p1[cntp1++].r = cnta1;
            l = cnta1;
            number = i;
        }
        else number *= i;
    }
    if (number > 1)
    {
        a1[cnta1++] = number;
        p1[cntp1].l = l;
        p1[cntp1++].r = cnta1;
        l = cnta1;
    }
    for (int i = n1 + 1; i <= n; i++)
    {
        if (i >= MOD)
        {
            a1[cnta1++] = i % MOD;
            a1[cnta1++] = i / MOD;
        }
        else a1[cnta1++] = i;
        p1[cntp1].l = l;
        p1[cntp1++].r = cnta1;
        l = cnta1;
    }
    int bitlength = 0, N = SIZEN >> 1;
    while (N)
    {
        bitlength++;
        N >>= 1;
    }
    Reverse(SIZEN, bitlength);
    double pin2 = 2.0 * acos(-1.0) / SIZEN;
    int N1 = SIZEN >> 2, N2 = SIZEN >> 1;
    for (int i = 0; i <= N1; i++)
    {
        e1[i] = complex(cos(pin2 * i), sin(pin2 * i));
    }
    for (int i = N1 + 1; i < N2; i++)
    {
        e1[i] = complex(-e1[N2 - i].real, e1[N2 - i].imag);
    }
    for (int i = 0; i < N2; i++)
    {
        e2[i] = complex(e1[i].real, -e1[i].imag);
    }
}

int n;

int main()
{
    scanf("%d", &n);
    
    init(n);
    factorial();
    
    return 0;
}
