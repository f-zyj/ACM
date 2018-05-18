//
//  main.cpp
//  f-51Nod-1116-K进制下的大数
//
//  Created by ZYJ on 16/8/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXS = 1e5 + 10;
const int MAXK = 36;

char num[MAXS];

int main(int argc, const char * argv[])
{
    while (cin >> num)
    {
        int sum = 0;
        int len = (int)strlen(num);
        int MINK = 2;
        for (int i = 0; i < len; i++)
        {
            if (num[i] >= '0' && num[i] <= '9')
            {
                if (num[i] - '0' + 1 > MINK)
                {
                    MINK = num[i] - '0' + 1;
                }
                sum += num[i] - '0';
            }
            else
            {
                if (num[i] - 'A' + 11 > MINK)
                {
                    MINK = num[i] - 'A' + 11;
                }
                sum += num[i] - 'A' + 10;
            }
        }
        
        bool flag = true;
        for (int i = MINK; i <= MAXK; i++)
        {
            if (sum % (i - 1) == 0)
            {
                flag = false;
                cout << i << '\n';
                break;
            }
        }
        if (flag)
        {
            cout << "No Solution\n";
        }
    }
    
    return 0;
}
