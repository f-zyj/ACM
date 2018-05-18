//
//  main.cpp
//  f-51Nod-1562-玻璃切割
//
//  Created by ZYJ on 2017/3/31.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <stdio.h>
//#include <set>
//
//using namespace std;
//
//inline void scan_d(int &ret)
//{
//    char c;
//    ret = 0;
//    while ((c = getchar()) < '0' || c > '9');
//    while (c >= '0' && c <= '9')
//    {
//        ret = ret * 10 + (c - '0'), c = getchar();
//    }
//}
//
//set<int> W, H;
//set<int>::iterator it;
//multiset<int> WL, HL;
//multiset<int>::iterator it_;
//
//int main(int argc, const char * argv[])
//{
////        freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    int w, h, n;
//    cin >> w >> h >> n;
//    W.insert(0);
//    W.insert(w);
//    
//    H.insert(0);
//    H.insert(h);
//    
//    WL.insert(w);
//    HL.insert(h);
//    
//    char S[3];
//    int tag;
//    
//    while (n--)
//    {
//        scanf("%s", S);
//        scan_d(tag);
//        if (S[0] == 'V')
//        {
//            W.insert(tag);
//            
//            it = W.find(tag);
//            int right = (* ++it);
//            it--;
//            int left = (* --it);
//            it_ = WL.find(right - left);
//            WL.erase(it_);
//            WL.insert(right - tag);
//            WL.insert(tag - left);
//        }
//        else
//        {
//            H.insert(tag);
//            
//            it = H.find(tag);
//            int right = (* ++it);
//            it--;
//            int left = (* --it);
//            it_ = HL.find(right - left);
//            HL.erase(it_);
//            HL.insert(right - tag);
//            HL.insert(tag - left);
//        }
//        
//        it_ = WL.end();
//        long long resW = (* --it_);
//        it_ = HL.end();
//        long long resH = (* --it_);
//        
//        printf("%lld\n", resW * resH);
//    }
//    
//    return 0;
//}


#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 2e5 + 10;

int maxW, maxH;
int preW[MAXN], preH[MAXN];
int rankW[MAXN], rankH[MAXN];
int visW[MAXN], visH[MAXN];

int w, h, n;

char opt[3];
int op[MAXN];
int num[MAXN];
long long ans[MAXN];

inline void scan_d(int &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}

int findW(int x)
{
    if (preW[x] != x)
    {
        preW[x] = findW(preW[x]);
    }
    return preW[x];
}

void joinW(int x, int y)
{
    x = findW(x);
    y = findW(y);
    
    if (x == y)
    {
        return ;
    }
    
    preW[y] = x;
    rankW[x] += rankW[y];
    maxW = max(rankW[x], maxW);
}

int findH(int x)
{
    if (preH[x] != x)
    {
        preH[x] = findH(preH[x]);
    }
    return preH[x];
}

void joinH(int x, int y)
{
    x = findH(x);
    y = findH(y);
    
    if (x == y)
    {
        return ;
    }
    
    preH[y] = x;
    rankH[x] += rankH[y];
    
    maxH = max(rankH[x], maxH);
}

void init()
{
    for (int i = 0; i <= w; i++)
    {
        preW[i] = i;
        rankW[i] = 1;
    }
    for (int i = 0; i <= h; i++)
    {
        preH[i] = i;
        rankH[i] = 1;
    }
    memset(visW, 0, sizeof(visW));
    memset(visH, 0, sizeof(visH));
    memset(op, 0, sizeof(op));
}

int main()
{
    cin >> w >> h >> n;
    
    init();
    
    rankW[0] = rankH[0] = 0;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%s", opt);
        scan_d(num[i]);
        
        if (opt[0] == 'H')
        {
            op[i] = 1;
            visH[num[i]] = 1;
        }
        else
        {
            visW[num[i]] = 1;
        }
    }
    
    maxH = 1;
    maxW = 1;
    
    for (int i = 1; i < w; i++)
    {
        if (!visW[i])
        {
            joinW(i, i + 1);
        }
    }
    
    for (int i = 1; i < h; i++)
    {
        if (!visH[i])
        {
            joinH(i, i + 1);
        }
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = (long long)(maxH) * (maxW);
        
        if (op[i])
        {
            joinH(num[i], num[i] + 1);
        }
        else
        {
            joinW(num[i], num[i] + 1);
        }
    }
    
    
    for (int i = 0; i < n; i++)
    {  
        printf("%lld\n", ans[i]);
    }  
    
    return 0;  
}
