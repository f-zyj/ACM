//
//  main.cpp
//  f-51Nod-1138-连续整数的和
//
//  Created by ZYJ on 16/8/3.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

int main(int argc, const char * argv[])
{
    int N;
    
    while (cin >> N)
    {
        bool flag = true;
        //  设首项为i,项数为j,则(2*i+j-1)*j/2=n
        //  (2*i+j-1)*j=2n
        //  (2n-j*j+j)/(2*j)=i
        ll N_ = 2 * N;
        int MAX_J = (int)sqrt(N_);
        for (int j = MAX_J; j >= 2; j--)
        {
            double i = (N_ - j * j + j) * 1.0 / (2 * j);
            if (i == (int)i)
            {
                flag = false;
                printf("%d\n", (int)i);
            }
        }
        if (flag)
        {
            cout << "No Solution\n";
        }
    }
    
    return 0;
}
