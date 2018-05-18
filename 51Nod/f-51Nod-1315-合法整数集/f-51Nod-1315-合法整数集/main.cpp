//
//  main.cpp
//  f-51Nod-1315-合法整数集
//
//  Created by ZYJ on 16/8/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int digit[33] = {0};    //  所有有可能需要删除的数的对应数位的和
int digitX[33];         //  X的二进制表示

int main(int argc, const char * argv[])
{
    int N, X;
    cin >> N >> X;
    
    //  将X转化为2进制
    int XX = X;
    int key = 0;
    while (XX)
    {
        digitX[key++] = XX % 2;
        XX /= 2;
    }
    
    int Y;
    int res = 55;
    for (int i = 0; i < N; i++)
    {
        cin >> Y;
        if ((Y | X) > X)    //  说明存在X的二进制位为0位，Y为1，不用考虑删除
        {
            continue;
        }
        int key = 0;
        while (Y)
        {
            digit[key++] += Y % 2;
            Y /= 2;
        }
    }
    for (int i = 0; i < 33; i++)
    {
        if (digitX[i] && !digit[i]) //  X的某二进制位为1，但是集合内数无法为此位提供1
        {
            res = 0;
            break;
        }
        if (digit[i])               //  删除能提供的最少的二进制位
        {
            res = res > digit[i] ? digit[i] : res;
        }
    }
    
    std::cout << res << '\n';
    return 0;
}
