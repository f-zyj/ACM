//
//  main.cpp
//  f-Karp-Rabin算法
//
//  Created by ZYJ on 16/6/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//  Karp-Rabin字符串匹配

/*
 *  hash(w[0 ... m - 1]) =
 *  (w[0] * 2 ^ (m - 1) + ... + w[m - 1] * 2 ^ 0) % q;
 *  hash(w[j + 1 ... j + m]) =
 *  rehash(y[j], y[j + m], hash(w[j ... j + m - 1]);
 *  rehash(a, b, h) = ((h - a * 2 ^ (m - 1)) * 2 + b) % q;
 *  可以用q = 2 ^ 32简化%运算
 */

//#define REHASH(a, b, h) (((h - (a) * b) << 1) + b)
//
//int krmatch(char *x, int m, char *y, int n)
//{
//    //search x in y
//    int d, hx, hy, i, j;
//    for (d = i = 1; i < m; i++)
//    {
//        d = (d << 1);
//    }
//    for (hy = hx = i = 0; i < m; i++)
//    {
//        hx = ((hx << 1) + x[i]);
//        hy = ((hy << 1) + y[i]);
//    }
//    for (j = 0; j <= n - m; j++)
//    {
//        if (hx == hy && memcmp(x, y + j, m) == 0)
//        {
//            return j;
//        }
//        hy = REHASH(y[j], y[j + m], hy);
//    }
//    return 0;   //理论上不会背执行，全部都应该从上一个return返回
//}

//  Karp-Rabin字符块匹配

/*
 *  Text: n * m matrix;
 *  Pattern: x * y matrix;
 */

//#define uint unsigned int //  C++中自带
const int A = 1024, B = 128;
const uint E = 27;
char text[A][A];
char patt[B][B];

uint ht, hp;
uint pw[B * B];
uint hor[A];
uint ver[A][A];

int n, m, x, y;

void init()
{
    int i, j = B * B;
    for (i = 1, pw[0] = 1; i < j; i++)
    {
        pw[i] = pw[i - 1] * E;
    }
    return ;
}

void hash()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0, hor[i] = 0; j < y; j++)
        {
            hor[i] *= pw[x];
            hor[i] += text[i][j] - 'a';
        }
    }
    for (j = 0; j < m; j++)
    {
        for (i = 0, ver[0][j] = 0; i < x; i++)
        {
            ver[0][j] *= E;
            ver[0][j] += text[i][j] - 'a';
        }
        for (i = 1; i <= n - x; i++)
        {
            ver[i][j] = (ver[i - 1][j] - (text[i - 1][j] - 'a') * pw[x - 1]) * E + text[i + x - 1][j] - 'a';
        }
    }
    for (j = 0, ht = hp = 0; j < y; j++)
    {
        for (i = 0; i < x; i++)
        {
            ht *= E;
            ht += text[i][j] - 'a';
            hp *= E;
            hp += patt[i][j] - 'a';
        }
    }
    return ;
}

void read()
{
    int i;
    std::cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        std::cin >> text[i];
    }
    for (i = 0; i < x; i++)
    {
        std::cin >> patt[i];
    }
    return ;
}

int solve()
{
    if (n == 0 || m == 0 || x == 0 || y == 0)
    {
        return 0;
    }
    int i, j, cnt = 0;
    uint t;
    for (i = 0; i <= n - x; i++)
    {
        for (j = 0, t = ht; j <= m - y; j++)
        {
            if (t == hp)
            {
                cnt++;
            }
            t = (t - ver[i][j] * pw[y * x - x]) * pw[x] + ver[i][j + y];
        }
        ht = (ht - hor[i] * pw[x - 1]) * E + hor[i + x];
    }
    return cnt;
}

int main(int argc, const char * argv[])
{
    int T;
    
    init();
    for (std::cin >> T; T; T--)
    {
        read();
        hash();
        std::cout << solve() << '\n';
    }
    
    return 0;
}
