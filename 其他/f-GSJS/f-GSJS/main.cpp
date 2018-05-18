//
//  main.cpp
//  f-GSJS
//
//  Created by ZYJ on 2017/10/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include "radianToAngle.hpp"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
    int a = 0;
    double e2 = 0;
    char type;
//    double x,y,B,L,L0;
//    printf("≤ŒøºÕ÷«Ú—°‘Ò\n");
//    printf("A:øÀ¿≠À˜∑ÚÀπª˘Õ÷«ÚÃÂ B:IUGG-75Õ÷«ÚÃÂ C£∫WGS-84Õ÷«Ú D£∫CGCS2000\n");//
    scanf("%c",&type);
    if(type=='A')
    {
        a = 6378245;
        e2 = 0.006693421622966;
    }
    else if(type=='B')
    {
        a = 6378140;
        e2 = 0.006694384999588;
    }
    else if(type=='C')
    {
        a = 6378137;
        e2 = 0.00669437999013;
    }
    else if(type=='D')
    {
        a = 6378137;
        e2 = 0.00669438002290;
    }
    
    
    printf("%.15f\n%d",e2,a);
    //printf("%f",PI);
    return 0;
}
