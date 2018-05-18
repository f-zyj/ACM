//
//  main.cpp
//  f-51Nod-1030-大数进制转换
//
//  Created by ZYJ on 2017/8/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstring>
#include <algorithm>
#include <stdio.h>

#define ll unsigned long long

using namespace std;

const int MAXN = 100000 + 10;
const int MAXP_10 = 18;
const int MAXP_36 = 11;
const int MAGIC_1 = 4;
const int MAGIC_2 = 10;
const int MAGIC_3 = 13;
const int MAGIC_4 = 36;

int len_c;
ll r[MAXN * MAGIC_3];
ll c[MAXN];
ll pow_10[MAXP_10];
ll pow_36[MAXP_36];
char s[MAXN];

//  字符转换为数字
int cTon(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return c - 'A' + 10;
}

//  截位转换
void convert()
{
    int t = 0;
    int len = (int)strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        if ((i - 1) % MAGIC_1 == 0)
        {
            t++;
        }
        c[t] = c[t] * MAGIC_4 + cTon(s[i]);
    }
    len_c = t;
}

void solve()
{
    ll num;
    bool b;
    for (int j = 1; j <= len_c; )
    {
        num = 0, b = false;
        for (int i = j; i <= len_c; )
        {
            num = num * pow_36[MAGIC_1] + c[i];
            c[i++] = 0;
            if (num >= pow_10[MAGIC_3])
            {
                c[i - 1] = num / pow_10[MAGIC_3];
                num %= pow_10[MAGIC_3];
            }
            if (c[i - 1])
            {
                b = 1;
            }
            if (!b)
            {
                j = i;
            }
        }
        r[++r[0]] = num;
    }
}

template <class T>
inline void print_d(T x)
{
    if (x > 9)
    {
        print_d(x / 10);
    }
    putchar(x % 10 + '0');
}

void output()
{
    print_d(r[r[0]]);
    for (int i = (int)r[0] - 1; i > 0; i--)
    {
        ll x = r[i], t = 1;
        while (x < pow_10[MAGIC_3 - t])
        {
            putchar('0');
            t++;
        }
        print_d(r[i]);
    }
    putchar(10);
}

void init()
{
    pow_10[0] = pow_36[0] = 1;
    for (int i = 1; i < MAXP_10; i++)
    {
        pow_10[i] = pow_10[i - 1] * MAGIC_2;
    }
    for (int i = 1; i < MAXP_36; i++)
    {
        pow_36[i] = pow_36[i - 1] * MAGIC_4;
    }
}

int main()
{
    init();
    
    scanf("%s", s + 1);
    
    convert();
    
    solve();
    
    output();
    
    return 0;
}

//  go
//package main
//
//import
//(
//    "bufio"
//    "fmt"
//    "math/big"
//    "os"
//)
//
//func main()
//{
//    bio := bufio.NewReader(os.Stdin)
//    line, _ := bio.ReadString(0)
//    n := big.NewInt(0)
//    n.SetString(string(line), 36)
//    fmt.Println(n.String())
//}

//  py3
//print(int(input(),36))

