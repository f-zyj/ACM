//
//  main.cpp
//  f-51Nod-算法马拉松15（脱欧专场）-A-B君的游戏
//
//  Created by ZYJ on 16/6/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

typedef unsigned long long ull;

using namespace std;

template <class T>
inline void scanDIY(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0'), c = getchar();
    return ;
}

int main(int argc, const char * argv[])
{
    int n;
    ull a;
    while (cin >> n)
    {
        int flag;       //  a转二进制后有几位1
        int flagA = 0;  //  取后只能添0的个数
        int flagB = 0;  //  flagB += flagA - 1
        
        for (int i = 0; i < n; i++)
        {
            scanDIY(a);
            
            if (a != 0)
            {
                flag = 0;
                while (a)
                {
                    if (a & 1)
                    {
                        flag++;
                    }
                    a >>= 1;
                }
                if (flag == 1)
                {
                    flagA++;
                }
                else
                {
                    flagB++;
                }
            }
        }
        
        bool A = flagA % 2;
        bool B = flagB % 2;
        
        if (B || (flagB == 0 && A))
        {
            cout << "B\n";
        }
        else
        {
            cout << "L\n";
        }
    }
    
    return 0;
}
