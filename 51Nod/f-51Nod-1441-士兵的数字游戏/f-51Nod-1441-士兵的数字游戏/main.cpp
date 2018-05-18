//
//  main.cpp
//  f-51Nod-1441-士兵的数字游戏
//
//  Created by ZYJ on 16/9/20.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#include <string.h>
//
//const int MAXN = 5e6 + 10;
//const int MAXF = 1e2;
//
//int prime[MAXN];
//int res[MAXN];
//bool notprime[MAXN];
//
//void getNotPrime()
//{
//    memset(notprime, false, sizeof(notprime));
//    notprime[0] = notprime[1] = true;
//    for (int i = 2; i < MAXN; i++)
//    {
//        if (!notprime[i])
//        {
//            if (i > MAXN / i)
//            {
//                continue;
//            }
//            for (int j = i * i; j < MAXN; j += i)
//            {
//                notprime[j] = true;
//            }
//        }
//    }
//    return ;
//}
//
//void getPrime()
//{
//    for (int i = 2; i < MAXN; i++)
//    {
//        if (!notprime[i])
//        {
//            prime[++prime[0]] = i;
//        }
//    }
//    
//    return ;
//}
//
///*
// *  合数分解
// *  factor[i][0]存放分解的素数
// *  factor[i][1]存放对应素数出现的次数
// *  fatCnt存放合数分解出的素数个数(相同的素数只算一次)
// */
//
//int factor[MAXF][2];
//int fatCnt;
//
//int getFactors(int x)
//{
//    fatCnt = 0;
//    int tmp = x;
//    
//    for (int i = 1; prime[i] <= tmp / prime[i]; i++)
//    {
//        factor[fatCnt][1] = 0;
//        if (!notprime[tmp])
//        {
//            factor[fatCnt][0] = tmp;
//            factor[fatCnt++][1]++;
//            tmp = 1;
//            break;
//        }
//        if (tmp % prime[i] == 0)
//        {
//            factor[fatCnt][0] = prime[i];
//            while (tmp % prime[i] == 0)
//            {
//                factor[fatCnt][1]++;
//                tmp /= prime[i];
//            }
//            fatCnt++;
//        }
//    }
//    
//    if (tmp != 1)
//    {
//        factor[fatCnt][0] = tmp;
//        factor[fatCnt++][1] = 1;
//    }
//    
//    int res = 0;
//    for (int i = 0; i < fatCnt; i++)
//    {
//        res += factor[i][1];
//    }
//    
//    return res;
//}
//
//int main(int argc, const char * argv[])
//{
////    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
////    freopen("/Users/zyj/Desktop/output.txt", "w", stdout);
//    getPrime();
//    getNotPrime();
//    
//    //  预处理
//    for (int i = 2; i < MAXN; i++)
//    {
//        if (!notprime[i])
//        {
//            res[i] = res[i - 1] + 1;
//            continue;
//        }
//        res[i] = res[i - 1] + getFactors(i);
//    }
//    
//    int t;
//    scanf("%d", &t);
//    
//    int ans;
//    int a, b;
//    while (t--)
//    {
//        ans = 0;
//        scanf("%d %d", &a, &b);
////        printf("%d %d  ", res[a], res[b]);
//        ans = res[a] - res[b];
//        printf("%d\n", ans);
//    }
//
//    return 0;
//}

#include <stdio.h>

const int MAXN = 5e6 + 10;
const int BUFSIZE = 20 << 20;   //  <<10 kb,<<20 MB

char Buf[BUFSIZE + 1], *buf = Buf;

inline void scan(int &a)
{
    for (a = 0; *buf < '0' || *buf > '9'; buf++) ;
    while (*buf >= '0' && *buf <= '9')
    {
        a = a * 10 + (*buf - '0');
        buf++;
    }
    return ;
}

int pre[MAXN];
int a[MAXN];

int prime[MAXN];
int pk = 0;     //  质数个数

void getPrime()
{
    a[1] = 0;
    for (int i = 2; i < MAXN; i++)
    {
        if (a[i] == 0)
        {
            prime[pk++] = i;
            a[i] = 1;
        }
        for (int j = 0; i * prime[j] < MAXN; j++)
        {
            a[i * prime[j]] = a[i] + 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    return ;
}

int main()
{
    fread(Buf,1,BUFSIZE,stdin);
    
    getPrime();
    
    for (int i = 1; i < MAXN; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    
    int t;
    scan(t);
    while (t--)
    {
        int x, y;
        scan(x);
        scan(y);
        printf("%d\n", pre[x] - pre[y]);
    }
    return 0;
}