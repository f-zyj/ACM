//
//  main.cpp
//  f-51Nod-1186-质数检测 V2
//
//  Created by ZYJ on 16/8/13.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAXL 4
#define M10 1000000000
#define Z10 9

const int zero[MAXL - 1] = {0};

struct bnum
{
    int data[MAXL]; //  断成每截9个长度
    
    //  读取字符串并转存
    void read()
    {
        memset(data, 0, sizeof(data));
        char buf[32];
        scanf("%s", buf);
        int len = (int)strlen(buf);
        int i = 0, k;
        while (len >= Z10)
        {
            for (k = len - Z10; k < len; ++k)
            {
                data[i] = data[i] * 10 + buf[k] - '0';
            }
            ++i;
            len -= Z10;
        }
        if (len > 0)
        {
            for (k = 0; k < len; ++k)
            {
                data[i] = data[i] * 10 + buf[k] - '0';
            }
        }
    }
    
    bool operator == (const bnum &x)
    {
        return memcmp(data, x.data, sizeof(data)) == 0;
    }
    
    bnum & operator = (const int x)
    {
        memset(data, 0, sizeof(data));
        data[0] = x;
        return *this;
    }
    
    bnum operator + (const bnum &x)
    {
        int i, carry = 0;
        bnum ans;
        for (i = 0; i < MAXL; ++i)
        {
            ans.data[i] = data[i] + x.data[i] + carry;
            carry = ans.data[i] / M10;
            ans.data[i] %= M10;
        }
        return  ans;
    }
    
    bnum operator - (const bnum &x)
    {
        int i, carry = 0;
        bnum ans;
        for (i = 0; i < MAXL; ++i)
        {
            ans.data[i] = data[i] - x.data[i] - carry;
            if (ans.data[i] < 0)
            {
                ans.data[i] += M10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
        }
        return ans;
    }
    
    //  assume *this < x * 2
    bnum operator % (const bnum &x)
    {
        int i;
        for (i = MAXL - 1; i >= 0; --i)
        {
            if (data[i] < x.data[i])
            {
                return *this;
            }
            else if (data[i] > x.data[i])
            {
                break;
            }
        }
        return ((*this) - x);
    }
    
    bnum & div2()
    {
        int  i, carry = 0, tmp;
        for (i = MAXL - 1; i >= 0; --i)
        {
            tmp = data[i] & 1;
            data[i] = (data[i] + carry) >> 1;
            carry = tmp * M10;
        }
        return *this;
    }
    
    bool is_odd()
    {
        return (data[0] & 1) == 1;
    }
    
    bool is_zero()
    {
        for (int i = 0; i < MAXL; ++i)
        {
            if (data[i])
            {
                return false;
            }
        }
        return true;
    }
};

void mulmod(bnum &a0, bnum &b0, bnum &p, bnum &ans)
{
    bnum tmp = a0, b = b0;
    ans = 0;
    while (!b.is_zero())
    {
        if (b.is_odd())
        {
            ans = (ans + tmp) % p;
        }
        tmp = (tmp + tmp) % p;
        b.div2();
    }
}

void powmod(bnum &a0, bnum &b0, bnum &p, bnum &ans)
{
    bnum tmp = a0, b = b0;
    ans = 1;
    while (!b.is_zero())
    {
        if (b.is_odd())
        {
            mulmod(ans, tmp, p, ans);
        }
        mulmod(tmp, tmp, p, tmp);
        b.div2();
    }
}

bool MillerRabinTest(bnum &p, int iter)
{
    int i, small = 0, j, d = 0;
    for (i = 1; i < MAXL; ++i)
    {
        if (p.data[i])
        {
            break;
        }
    }
    if (i == MAXL)
    {
        // small integer test
        if (p.data[0] < 2)
        {
            return  false;
        }
        if (p.data[0] == 2)
        {
            return  true;
        }
        small = 1;
    }
    if (!p.is_odd())
    {
        return false;   //  even number
    }
    bnum a, s, m, one, pd1;
    one = 1;
    s = pd1 = p - one;
    while (!s.is_odd())
    {
        s.div2();
        ++d;
    }
    
    for (i = 0; i < iter; ++i)
    {
        a = rand();
        if (small)
        {
            a.data[0] = a.data[0] % (p.data[0] - 1) + 1;
        }
        else
        {
            a.data[1] = a.data[0] / M10;
            a.data[0] %= M10;
        }
        if (a == one)
        {
            continue;
        }
        
        powmod(a, s, p, m);
        
        for (j = 0; j < d && !(m == one) && !(m == pd1); ++j)
        {
            mulmod(m, m, p, m);
        }
        if (!(m == pd1) && j > 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    bnum x;
    
    x.read();
    puts(MillerRabinTest(x, 5) ? "Yes" : "No");
    
    return 0;
}