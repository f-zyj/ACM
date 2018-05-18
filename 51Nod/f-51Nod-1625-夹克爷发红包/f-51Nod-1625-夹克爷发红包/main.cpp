//
//  main.cpp
//  f-51Nod-1625-夹克爷发红包
//
//  Created by ZYJ on 16/8/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//  WA
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//
//typedef long long ll;
//
//using namespace std;
//
//const int MAXN = 13;
//const int MAXM = 203;
//
//ll matrix[MAXN][MAXM];
//ll matrixF[MAXN][MAXM]; //  红包状态，0为普通红包，1为高级红包
//ll sumN[MAXN];
//ll sumM[MAXM];
//
//int main(int argc, const char * argv[])
//{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    int n, m, x, k;
//    
//    while (cin >> n >> m >> x >> k)
//    {
//        memset(sumN, 0, sizeof(sumN));
//        memset(sumM, 0, sizeof(sumM));
//        memset(matrixF, 0, sizeof(matrixF));
//        
//        ll nx = 1ll * n * x;
//        ll mx = 1ll * m * x;
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= m; j++)
//            {
//                scanf("%lld", matrix[i] + j);
//                sumN[i] += matrix[i][j];
//                sumM[j] += matrix[i][j];
//            }
//        }
//        
//        while (k--)
//        {
//            //  按行查找
//            ll diffN = 0;
//            int posN = 0;
//            for (int i = 1; i <= n; i++)
//            {
//                if (mx - sumN[i] > diffN)
//                {
//                    diffN = mx - sumN[i];
//                    posN = i;
//                }
//            }
//            //  按列查找
//            ll diffM = 0;
//            int posM = 0;
//            for (int i = 1; i <= m; i++)
//            {
//                if (nx - sumM[i] > diffM)
//                {
//                    diffM = nx - sumM[i];
//                    posM = i;
//                }
//            }
//            //  列差大于行差
//            if (diffM > diffN)
//            {
//                if (diffM <= 0)
//                {
//                    break;
//                }
//                sumM[posM] = nx;
//                for (int i = 1; i <= n; i++)
//                {
//                    sumN[i] = sumN[i] + x - matrix[i][posM];
//                }
//                for (int i = 1; i <= n; i++)
//                {
//                    matrix[i][posM] = x;
//                }
//            }
//            else    //  行差大于列差
//            {
//                if (diffN <= 0)
//                {
//                    break;
//                }
//                sumN[posN] = mx;
//                for (int i = 1; i <= m; i++)
//                {
//                    sumM[i] = sumM[i] + x - matrix[posN][i];
//                }
//                for (int i = 1; i <= m; i++)
//                {
//                    matrix[posN][i] = x;
//                }
//            }
//        }
//        
//        ll ans = 0;
//        for (int i = 0; i <= n; i++)
//        {
//            ans += sumN[i];
//        }
//        
//        cout << ans << '\n';
//    }
//    
//    return 0;
//}


// AC
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define  LL long long

using namespace std;

const int MAXN = 11;
const int MAXM = 201;

LL money[MAXN][MAXM];
int rlist[MAXN];

vector<LL> rowSum;
vector<LL> colSum;
vector<LL> h;       //  替换完行后，存储替换列的收益

//  检索第i种组合使用了几组高级红包
int count(int num)
{
    int ret = 0;
    while (num)
    {
        if (num & 1)
        {
            ret++;
        }
        num >>= 1;
    }
    return ret;
}

bool cmp(const LL &a, const LL &b)
{
    return a > b;
}

int main()
{
    LL n, m, x, k;
    LL sum = 0; //  所有红包总和
    scanf("%lld %lld %lld %lld", &n, &m, &x, &k);
    rowSum.resize(n, 0);
    colSum.resize(m, 0);
    h.resize(m, 0);
    
    for (int i = 0; i < n; ++ i)
    {
        for (int j = 0; j < m; ++ j)
        {
            scanf("%lld", &money[i][j]);
            rowSum[i] += money[i][j];
            colSum[j] += money[i][j];
            sum += money[i][j];
        }
    }
    LL row_max = 1ll * x * m;           //  整行为高级红包
    LL col_max = 1ll * x * n;           //  整列为高级红包
    LL ans = sum;                       //  初始为sum
    for (int i = 0; i < (1 << n); i++)  //  枚举所有行的组合 (1 << n)种组合
    {
        LL ret = sum;
        int idx = 0;
        int cnt = count(i);             //  高级红包使用组数
        if (k < cnt)                    //  如果超过了k，肯定不行，因为最多发k组
        {
            continue;
        }
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))           //  为1的标示这一行替换固定红包x，求出收益，并标示替换了哪些行
            {
                ret += row_max - rowSum[j];
                rlist[idx++] = j;       //  记录高级红包发放行数
            }
        }
        for (int j = 0; j < m; ++j)     //  求出替换完行后，每一列如果被替换所得的收益
        {
            h[j] = col_max - colSum[j];
            for (int l = 0; l < idx; ++l)
            {
                h[j] += money[rlist[l]][j] - x;
            }
        }
        sort(h.begin(), h.end(), cmp);  //  根据收益大小排序，得到最大收益的列的顺序
        for (int j = 0; j + cnt < k && h[j] > 0; ++j)   //  k-cnt剩余的就通过替换列来补充，直接加上列的收益即可
        {
            ret += h[j];
        }
        ans = max(ans, ret);            //  更新最大收益
    }
    printf("%lld\n", ans);
    
    return 0;
}