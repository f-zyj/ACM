//
//  main.cpp
//  f-51Nod-1029-大数除法
//
//  Created by ZYJ on 2017/8/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <cmath>

typedef long long ll;

int powermod(int a, int exp, int moder)
{
    int ret = 1;
    for (; exp; exp >>= 1)
    {
        if (exp & 1)
        {
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

void addminus(int *a, int *b, int &lengtha, int &lengthb, int type)
{
    int length = std::max(lengtha, lengthb);
    for (int i = 0; i < length; ++i)
    {
        a[i] += type == 1 ? b[i] : -b[i];
        a[i] >= 10 ? (a[i] -= 10, ++a[i + 1]) : a[i] < 0 ? (a[i] += 10, --a[i + 1]) : 0;
    }
    for (lengtha = length + 1; lengtha && !a[lengtha - 1]; --lengtha) ;
}

struct BigInteger
{
    const static int MAXN = 19;
    const static int MOD = (119 << 23) + 1;   //  998244353
    const static int root = 3;
    const static int invroot = 332748118;
    
    int a[1 << MAXN];
    int length, sig;
    
    BigInteger()
    {
        memset(a, 0, sizeof(a));
        length = sig = 0;
    }
    
    void clear()
    {
        memset(a, 0, sizeof(int) * length);
        length = sig = 0;
    }
    
    void read()
    {
        clear();
        char ch = getchar();
        for (; (ch < '0' || ch > '9') && ch != '-'; ch = getchar()) ;
        ch == '-' ? (sig = -1, ch = getchar()) : sig = 1;
        for (; ch >= '0' && ch <= '9'; ch = getchar())
        {
            a[length ++] = ch - '0';
        }
        std::reverse(a, a + length);
        for (; length && !a[length - 1]; --length) ;
        sig = length ? sig : 0;
    }
    
    void write()
    {
        if (!sig)
        {
            return (void)putchar('0');
        }
        if (sig < 0)
        {
            putchar('-');
        }
        for (int i = length - 1; i >= 0; i--)
        {
            putchar(a[i] + '0');
        }
    }
    
    template <typename T>
    T tointeger()
    {
        T ret = 0;
        for (int i = length - 1; i >= 0; ++i)
        {
            ret = ret * 10 + a[i];
        }
        return ret * sig;
    }
    
    bool equal(const BigInteger &p) const &
    {
        if (sig != p.sig || length != p.length)
        {
            return false;
        }
        for (int i = 0; i < length; ++i)
        {
            if (a[i] != p.a[i])
            {
                return false;
            }
        }
        return true;
    }
    
    bool greater(const BigInteger &p) const &
    {
        if (sig != p.sig)
        {
            return sig > p.sig;
        }
        if (length != p.length)
        {
            return length > p.length ^ sig == -1;
        }
        for (int i = length - 1; i >= 0; --i)
        {
            if (a[i] > p.a[i])
            {
                return sig > 0;
            }
            else if (a[i] < p.a[i])
            {
                return sig < 0;
            }
        }
        return false;
    }
    
    void leftshift(int dis)
    {
        for (int i = length + dis - 1; i >= dis; --i)
        {
            a[i] = a[i - dis];
        }
        memset(a, 0, sizeof(int) * dis);
        length += dis;
    }
    
    void rightshift(int dis)
    {
        if (dis >= length)
        {
            return clear();
        }
        for (int i = 0; i < length - dis; ++i)
        {
            a[i] = a[i + dis];
        }
        memset(a + length - dis, 0, sizeof(int) * dis);
        length = length - dis > 0 ? length - dis : 0;
    }
    
    void addone()
    {
        sig >= 0 ? ++ a[0] : --a[0];
        for (int i = 0; i < length; ++i)
        {
            if (a[i] < 10 && a[i] >= 0)
            {
                break;
            }
            a[i] >= 10 ? (a[i] -= 10, ++a[i + 1]) : (a[i] += 10, --a[i + 1]);
        }
        if (a[length])
        {
            ++length;
        }
        if (!a[length - 1])
        {
            --length;
        }
        sig = length ? (sig >= 0 ? 1 : -1) : 0;
    }
    
    void minusone()
    {
        sig = -sig;
        addone();
        sig = -sig;
    }
    
    bool absgreaterequal(BigInteger &q)
    {
        if (length != q.length)
        {
            return length > q.length;
        }
        for (int i = length - 1; i >= 0; -- i)
        {
            if (a[i] > q.a[i])
            {
                return true;
            }
            if (a[i] < q.a[i])
            {
                return false;
            }
        }
        return true;
    }
    
    void abs()
    {
        sig = std::abs(sig);
    }
    
    void neg()
    {
        sig = -sig;
    }
    
    void assign(BigInteger &q)
    {
        memset(a, 0, sizeof(int) * length);
        memcpy(a, q.a, sizeof(int) * q.length);
        length = q.length;
        sig = q.sig;
    }
    
    template <typename T>
    void assign(T q)
    {
        memset(a, 0, sizeof(int) * length);
        if (!q)
        {
            return (void)(sig = length = 0);
        }
        q < 0 ? sig = -1, q = -q : sig = 1;
        length = 0;
        for (; q; q /= 10)
        {
            a[length++] = q % 10;
        }
    }
    
    void add(BigInteger &q)
    {
        static BigInteger aux;
        if (!q.sig)
        {
            return ;
        }
        if (!sig)
        {
            assign(q);
            return ;
        }
        if (sig == q.sig)
        {
            addminus(a, q.a, length, q.length, 1);
            return ;
        }
        if (absgreaterequal(q))
        {
            addminus(a, q.a, length, q.length, -1);
            sig = length ? sig : 0;
            return ;
        }
        aux.assign(q);
        addminus(q.a, a, q.length, length, -1);
        assign(q);
        q.assign(aux);
    }
    
    void minus(BigInteger &q)
    {
        q.neg();
        add(q);
        q.neg();
    }
    
    void NTT(int *a, int length, int type)
    {
        int len = -1;
        for (int x = length; x; ++len, x >>= 1) ;
        for (int i = 1, j = 0; i < length - 1; ++i)
        {
            for (int s = length; j ^= s >>= 1, ~j & s; ) ;
            if (i < j)
            {
                std::swap(a[i], a[j]);
            }
        }
        
        for (int i = 1; i <= len; ++ i)
        {
            int unit = powermod(type == 1 ? root : invroot, (MOD - 1) >> i, MOD), szk = 1 << (i - 1);
            for (int j = 0; j < length; j += 1 << i)
            {
                for (int k = j, w = 1; k < j + szk; ++k)
                {
                    int s = a[k], t = 1ll * w * a[k + szk] % MOD;
                    a[k] = s + t >= MOD ? s + t - MOD : s + t;
                    a[k + szk] = s - t < 0 ? s - t + MOD : s - t;
                    w = 1ll * w * unit % MOD;
                }
            }
        }
        if (type == 1)
        {
            return ;
        }
        int inv = powermod(length, MOD - 2, MOD);
        for (int i = 0; i < length; ++ i)
        {
            a[i] = 1ll * a[i] * inv % MOD;
        }
    }
    
    void mult(BigInteger &q)
    {
        static int aux[1 << MAXN];
        if (!sig || !q.sig)
        {
            return clear();
        }
        int n = length + q.length;
        int lengthans = 1;
        for (; lengthans < n; lengthans <<= 1) ;
        memcpy(aux, q.a, sizeof(int) * lengthans);
        NTT(a, lengthans, 1);
        NTT(aux, lengthans, 1);
        for (int i = 0; i < lengthans; i++)
        {
            a[i] = 1ll * a[i] * aux[i] % MOD;
        }
        NTT(a, lengthans, -1);
        for (int i = 0; i < n - 1; i++)
        {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
        }
        length = n;
        for (; length && !a[length - 1]; --length) ;
        sig *= q.sig;
    }
    
    void mult(int q)
    {
        if (!q || !sig)
        {
            return clear();
        }
        ll x = std::abs(q), remain = 0;
        for (int i = 0; i < length; ++i)
        {
            remain += a[i] * x;
            a[i] = remain % 10;
            remain /= 10;
        }
        a[length] = (int)remain;
        for (; a[length]; ++length)
        {
            a[length + 1] = a[length] / 10;
            a[length] %= 10;
        }
        for (; length && !a[length - 1]; --length) ;
        sig *= q < 0 ? -1 : 1;
    }
    
    void power(int exp)
    {
        static BigInteger aux;
        if (!sig)
        {
            return ;
        }
        aux.assign<int> (1);
        for (; exp; exp >>= 1)
        {
            if (exp & 1)
            {
                aux.mult(*this);
            }
            aux.mult(aux);
        }
        assign(aux);
    }
    
    void divide(BigInteger &q)
    {
        static BigInteger aux, aux1;
        if (!sig || !q.sig)
        {
            return ;
        }
        if (length < q.length)
        {
            return clear();
        }
        bool neg1 = sig == 1, neg2 = q.sig == 1;
        abs(), q.abs();
        int num = 0;
        for (int i = q.length - 1; i >= q.length - 3; --i)
        {
            (num *= 10) += i >= 0 ? q.a[i] : 0;
        }
        num = 100000 / num;
        int nowprecision = 1;
        aux.assign<int> (num);
        for (; nowprecision <= length - q.length; nowprecision <<= 1)
        {
            aux1.clear();
            aux1.length = (nowprecision << 1) + 3, aux1.sig = 1;
            for (int i = q.length - aux1.length; i < q.length; ++i)
            {
                aux1.a[i - q.length + aux1.length] = i >= 0 ? q.a[i] : 0;
            }
            aux1.mult(aux), aux1.rightshift(nowprecision + 2);
            aux1.mult(aux),	aux1.rightshift(nowprecision + 2);
            aux.mult(2);
            aux.leftshift(nowprecision);
            aux.minus(aux1);
        }
        aux.mult(*this);
        aux.rightshift(q.length + nowprecision + 1);
        aux1.assign(aux);
        aux1.mult(q);
        minus(aux1);
        int flag = absgreaterequal(q) ? 2 : sig < 0 ? 1 : 0;
        assign(aux);
        if (flag)
        {
            flag == 1 ? minusone() : addone();
        }
        if (!neg2)
        {
            q.neg();
        }
        sig *= neg1 ^ neg2 ? -1 : 1;
    }
    
    int divide(int q)
    {
        if (!sig || !q)
        {
            return 0;
        }
        ll remain = 0, x = std::abs(q);
        for (int i = length - 1; i >= 0; --i)
        {
            remain = remain * 10 + a[i];
            a[i] = (int)(remain / x);
            remain %= x;
        }
        for (; length && !a[length - 1]; --length) ;
        remain *= sig;
        sig *= q < 0 ? -1 : 1;
        if (!length)
        {
            sig = 0;
        }
        return (int)remain;
    }
    
    void sqrt()
    {
        static BigInteger aux, aux1, aux2;
        if (sig <= 0)
        {
            return ;
        }
        int num = 0;
        for (int i = length - 1; i >= length - 8; --i)
        {
            (num *= 10) += i >= 0 ? a[i] : 0;
        }
        ll x = length & 1 ? 10000000000000ll : 100000000000000ll;
        num = std::sqrt(1.0 * x / num);
        int nowprecision = 2;
        aux.assign<int> (num);
        for (; nowprecision <= (length >> 1) + 1; nowprecision = (nowprecision << 1) - 1)
        {
            aux1.clear(), aux2.clear();
            aux1.length = (nowprecision << 1) + 1 + (length & 1), aux1.sig = 1;
            for (int i = length - aux1.length; i < length; ++i)
            {
                aux1.a[i - length + aux1.length] = i >= 0 ? a[i] : 0;
            }
            aux1.mult(aux), aux1.rightshift(nowprecision + 1);
            aux1.mult(aux),	aux1.rightshift(nowprecision + 1);
            aux1.divide(2);
            aux2.length = (nowprecision + 1) << 1, aux2.sig = 1;
            aux2.a[aux2.length - 1] = 1, aux2.a[aux2.length - 2] = 5;
            aux2.minus(aux1);
            aux.mult(aux2);
            aux.rightshift(nowprecision + 2);
        }
        aux.mult(*this);
        aux.rightshift((length >> 1) + nowprecision + 1);
        aux1.assign(aux);
        aux1.mult(aux1);
        aux2.assign(*this);
        aux2.mult(2);
        minus(aux1);
        int flag = greater(aux2) ? 2 : sig < 0 ? 1 : 0;
        assign(aux);
        if (flag)
        {
            flag == 1 ? minusone() : addone();
        }
    }
};

BigInteger a, b, c;

int main()
{
    a.read();
    b.read();
    
    c.assign(a);
    a.divide(b);
    a.write();
    putchar('\n');
    
    a.mult(b);
    c.minus(a);
    c.write();
    putchar('\n');
    
    return 0;
}
