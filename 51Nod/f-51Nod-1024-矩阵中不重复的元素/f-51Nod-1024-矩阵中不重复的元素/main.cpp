//
//  main.cpp
//  f-51Nod-1024-矩阵中不重复的元素
//
//  Created by ZYJ on 16/7/31.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

set<double> S;

int main(int argc, const char * argv[])
{
    int m, n, a, b;
    double v;
    
    while (cin >> m >> n >> a >> b)
    {
        for (int i = b; i < b + m; i++)
        {
            for (int j = a; j < a + n; j++)
            {
                v = (double)i * log2(1.0 * j);
                S.insert(v);
            }
        }
    }
    std::cout << S.size();
    
    return 0;
}
