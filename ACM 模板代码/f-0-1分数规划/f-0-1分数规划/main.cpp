//
//  main.cpp
//  f-0-1分数规划
//
//  Created by ZYJ on 16/7/22.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

/*
 *  0-1 分数规划
 *      t1 * x1 + t2 * x2 + ... + tn * xn
 *  r = ---------------------------------
 *      c1 * x1 + c2 * x2 + ... + cn * xn
 *  给定t[1..n], c[1..n], 求x[1..n]使得sigma(xi)=k且r最大(小). 
 *  为了让r最大, 先设计子问题z(r) = (t1 * x1 + .. + tn * xn) - r * (c1 * xn + .. + cn * xn);
 *  假设r的最优值为R. 则有:
 *  z(r) < 0 当且仅当 r > R;
 *  z(r) = 0 当且仅当 r = R;
 *  z(r) > 0 当且仅当 r < R;
 *  于是可二分求R.
 */

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
