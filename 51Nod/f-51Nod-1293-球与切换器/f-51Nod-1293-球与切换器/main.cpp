//
//  main.cpp
//  f-51Nod-1293-球与切换器
//
//  Created by ZYJ on 2017/4/20.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//const int MAXN = 1e3 + 10;
//
//struct box
//{
//    int lx, ly;
//    int x, y;
//    long long num;
//    
//    box(int lx_, int ly_, int x_, int y_, long long num_)
//    : lx(lx_), ly(ly_), x(x_), y(y_), num(num_) {}
//};
//
//int M, N;
//long long K;
//long long ans = 0;
//int B[MAXN][MAXN];
//
//queue<box> qb;
//
//template <class T>
//inline void scan_d(T &ret)
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
//void solve()
//{
//    box b(0, 1, 1, 1, K);
//    qb.push(b);
//    
//    while (!qb.empty())
//    {
//        b = qb.front();
//        qb.pop();
//        
//        if (b.x == N + 1 && b.y == M)
//        {
//            ans += b.num;
//            continue;
//        }
//        if (b.x == N + 1 || b.y == M + 1)
//        {
//            continue;
//        }
//        
//        long long temp;
//        switch (B[b.x][b.y])
//        {
//            case 0:
//                if (b.lx == b.x)
//                {
//                    qb.push(box(b.x, b.y, b.x, b.y + 1, b.num));
//                }
//                else
//                {
//                    qb.push(box(b.x, b.y, b.x + 1, b.y, b.num));
//                }
//                break;
//            case -1:
//                temp = b.num / 2;
//                if (b.num % 2)
//                {
//                    qb.push(box(b.x, b.y, b.x, b.y + 1, temp));
//                    qb.push(box(b.x, b.y, b.x + 1, b.y, temp + 1));
//                    B[b.x][b.y] = 1;
//                }
//                else
//                {
//                    qb.push(box(b.x, b.y, b.x, b.y + 1, temp));
//                    qb.push(box(b.x, b.y, b.x + 1, b.y, temp));
//                }
//                break;
//            case 1:
//                temp = b.num / 2;
//                if (b.num % 2)
//                {
//                    qb.push(box(b.x, b.y, b.x, b.y + 1, temp + 1));
//                    qb.push(box(b.x, b.y, b.x + 1, b.y, temp));
//                    B[b.x][b.y] = -1;
//                }
//                else
//                {
//                    qb.push(box(b.x, b.y, b.x, b.y + 1, temp));
//                    qb.push(box(b.x, b.y, b.x + 1, b.y, temp));
//                }
//                break;
//        }
//    }
//}
//
//int main(int argc, const char * argv[])
//{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
//    
//    scan_d(M);
//    scan_d(N);
//    scan_d(K);
//    for (int i = 1; i <= N; i++)
//    {
//        for (int j = 1; j <= M; j++)
//        {
//            scan_d(B[i][j]);
//        }
//    }
//    
//    solve();
//    
//    cout << ans << '\n';
//    
//    return 0;
//}

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int M, N;
long long k;
int state[MAXN][MAXN];
long long res[MAXN][MAXN][2];

int main()
{
    scanf("%d%d%lld", &M, &N, &k);
 
    long long temp;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%d", &state[i][j]);
            if (i != 1 || j != 1)
            {
                temp = res[i - 1][j][0] + res[i][j - 1][1];
                
                switch (state[i][j])
                {
                    case 0:
                        res[i][j][0] = res[i - 1][j][0];
                        res[i][j][1] = res[i][j - 1][1];
                        break;
                    case 1:
                        res[i][j][1] = (temp + 1) / 2;
                        res[i][j][0] = temp / 2;
                        break;
                    default:
                        res[i][j][0] = (temp + 1) / 2;
                        res[i][j][1] = temp / 2;
                        break;
                }
            }
            else
            {
                switch (state[i][j])
                {
                    case 0:
                        res[i][j][0] = k;
                        res[i][j][1] = 0;
                        break;
                    case 1:
                        res[1][1][1] = (k + 1) / 2;
                        res[1][1][0] = k / 2;
                        break;
                    default:
                        res[1][1][0] = (k + 1) / 2;
                        res[1][1][1] = k / 2;
                        break;
                }
            }
        }
    }
    
    printf("%lld\n", res[N][M][0]);
    
    return 0;  
}
