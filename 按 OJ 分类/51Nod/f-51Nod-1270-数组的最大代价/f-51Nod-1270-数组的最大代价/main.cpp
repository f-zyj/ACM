//
//  main.cpp
//  f-51Nod-1270-数组的最大代价
//
//  Created by ZYJ on 16/8/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <cstdio>
//#include <cmath>
//
//using namespace std;
//
//const int MAXN = 5e4 + 10;
//
//int B[MAXN];
//int dp[MAXN][2] = {0};  //  dp[i][j]:j->0表示A[i]取1，j->1表示A[i]取B[i]
//
//int main(int argc, const char * argv[])
//{
//    int N;
//    cin >> N;
//    
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", B +i);
//    }
//    
//    for (int i = 2; i <= N; i++)
//    {
//        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + B[i - 1] - 1);
//        dp[i][1] = max(dp[i - 1][0] + B[i] - 1, dp[i - 1][1] + abs(B[i] - B[i - 1]));
//    }
//    
//    std::cout << max(dp[N][0], dp[N][1]) << "\n";
//    return 0;
//}


//  空间优化，滚动数组
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 5e4 + 10;

int B[MAXN];

int main()
{
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", B + i);
    }
    
    int dpx[2], dp[2] = {0, 0};
    for (int i = 1; i < N; i++)
    {
        dpx[0] = max(dp[0], dp[1] + B[i - 1] - 1);
        dpx[1] = max(dp[0] + B[i] - 1, dp[1] + abs(B[i] - B[i - 1]));
        dp[0] = dpx[0];
        dp[1] = dpx[1];
    }
    
    cout << max(dp[0], dp[1]);
    
    return 0;
}
