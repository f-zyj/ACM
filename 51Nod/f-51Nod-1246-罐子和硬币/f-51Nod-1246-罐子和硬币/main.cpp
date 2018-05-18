//
//  main.cpp
//  f-51Nod-1246-罐子和硬币
//
//  Created by ZYJ on 16/8/8.
//  Copyright ? 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int n, k, c;
    
    while (cin >> n >> k >> c)
    {
        //  这道题要说的就是，分配是我们自己分配
        //  拿的时候也是我们自己拿的，所以，
        //  我们是可以知道每个罐子中可能有几个的
        
        //  想要最糟询问方案次数最少，需要先考虑
        //  不会出现抓空的情况(尽量均分)     (1)
        //  其次要考虑尽量少抓空的情况       (2)
        int x = k / n;      //  每个罐子最少x个
        int y = n - k % n;  //  y个罐子有x个，其他的罐子有x+1个
        
        if (x * n >= c || k % n == 0)   //  (1)
        {
            //  当出现这两种情况时，我们一定不会浪费询问次数的
            printf("%d\n", c);
        }
        else                            //  (2)
        {
            //  两种情况 第一种是尽量均分策略:  c+y(最糟糕抓空y次)
            //  第二种是保证足够多的罐子装x+1:  res(最多抓空n-z次)
            int z = k / (x + 1);              //  z个罐子可以方x+1个
            int res = n - z + c;              //  会抓空n-z次，然后有c次没有抓空
            printf("%d\n", min(res, c + y));  //  从两种情况中保留最少的次数并输出
        }
    }
    
    return 0;
}