//
//  main.cpp
//  f-容斥
//
//  Created by ZYJ on 2017/9/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAXN = 1111;

int n;
double ans;
double p[MAXN];

void dfs(int x, int tot, double sum)    //  dfs(1, 0, ?)
{
    if (x == n + 1)
    {
        if (sum == 0.0)
        {
            return ;
        }
        
        if (tot & 1)
        {
            ans += 1 / sum; //  公式随意变
        }
        else
        {
            ans -= 1 / sum;
        }
        return ;
    }
    
    dfs(x + 1, tot, sum);
    dfs(x + 1, tot + 1, sum + p[x]);
}

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
