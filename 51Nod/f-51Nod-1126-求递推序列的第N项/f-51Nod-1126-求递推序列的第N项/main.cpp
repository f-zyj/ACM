//
//  main.cpp
//  f-51Nod-1126-求递推序列的第N项
//
//  Created by ZYJ on 16/8/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int f[300] = {1, 1, 1};   //  根据规律可知，一定存在循环节

int main(int argc, const char * argv[])
{
    int A, B, N;
    
    while (cin >> A >> B >> N)
    {
        if (N == 1 || N == 2)
        {
            printf("1\n");
            continue;
        }
        int i;
        for (i = 3; i < 300; i++)
        {
            f[i] = ((A * f[i - 1] + B * f[i - 2]) % 7 + 7) % 7;
            if (f[i - 1] == 1 && f[i] == 1)
            {
                break;
            }
        }
        f[0] = f[i - 2];    //  将循环节尾部值赋值给f[0]
        printf("%d\n", f[N % (i - 2)]);
    }
    
    return 0;
}
