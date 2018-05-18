//
//  main.cpp
//  f-蓝桥-ALGO-9-摆动序列
//
//  Created by ZYJ on 2017/6/1.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <iostream>
//
//using namespace std;
//
//int com(int n, int r)
//{
//    if (n - r > r)
//    {
//        r = n - r;
//    }
//    int s = 1;
//    for (int i = 0, j = 1; i < r; i++)
//    {
//        s *= (n - i);
//        for (; j <= r && s % j == 0; j++)
//        {
//            s /= j;
//        }
//    }
//    
//    return s;
//}
//
//int main(int argc, const char * argv[])
//{
//    int k;
//    cin >> k;
//    
//    int res = 0;
//    for (int i = 2; i <= k; i++)
//    {
//        res += com(k, i);
//    }
//    
//    cout << res * 2 << '\n';
//    
//    return 0;
//}

#include <cstdio>
#include <cmath>

int main()
{
    int k;
    scanf("%d", &k);
    printf("%d\n", (int)(pow(2, k) - k - 1) * 2);
    
    return 0;
}
