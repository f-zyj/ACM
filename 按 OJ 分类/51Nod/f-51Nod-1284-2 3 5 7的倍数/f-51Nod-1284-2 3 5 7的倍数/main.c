//
//  main.c
//  f-51Nod-1284-2 3 5 7的倍数
//
//  Created by qingyun on 16/5/16.
//  Copyright © 2016年 qingyun. All rights reserved.
//

#include <stdio.h>
#include <string.h>
typedef long long ll;

int main(int argc, const char * argv[])
{
    long long a;
    
    while (~scanf("%lld", &a))
    {
        //2、3、5、7
        ll a_2 = a / 2;
        ll a_3 = a / 3;
        ll a_5 = a / 5;
        ll a_7 = a / 7;
        
        //2 * 3、2 * 5......
        ll a_6 = a / 6;
        ll a_10 = a / 10;
        ll a_14 = a / 14;
        ll a_15 = a / 15;
        ll a_21 = a / 21;
        ll a_35 = a / 35;
        
        //2 * 3 * 5......
        ll a_30 = a / 30;
        ll a_42 = a / 42;
        ll a_70 = a / 70;
        ll a_105 = a / 105;
        
        //2 * 3 * 5 * 7
        ll a_210 = a / 210;
        
        ll ans = a - a_2 - a_3 - a_5 - a_7 + a_6 + a_10 + a_14 + a_15 + a_21 + a_35 - a_30 - a_42 - a_70 - a_105 + a_210;
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
