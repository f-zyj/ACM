//
//  main.cpp
//  f-51Nod-1433-0和5
//
//  Created by ZYJ on 16/8/4.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

typedef long long ll;

using namespace std;

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    
    int K, num_0 = 0, num_5 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> K;
        if (K)
        {
            num_5++;
        }
        else
        {
            num_0++;
        }
    }
    
    //  判断是否存在0
    bool flag = num_0 > 0 ? false : true;
    
    if (flag)
    {
        cout << "-1\n";
    }
    else
    {
        //  判断5的个数是否可以凑成9的倍数
        bool tag = num_5 >= 9 ? false : true;
        if (tag)
        {
            cout << "0\n";
        }
        else
        {
            int times = num_5 / 9 * 9;  //  ex:11 / 9 * 9 = 9
            for (int i = 0; i < times; i++)
            {
                cout << "5";
            }
            for (int i = 0; i < num_0; i++)
            {
                cout << "0";
            }
            cout << '\n';
        }
    }
    
    return 0;
}
