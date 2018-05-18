//
//  main.cpp
//  f-51Nod-TalkingData数据科学精英夏令营挑战赛-B-丢手绢
//
//  Created by ZYJ on 2017/6/17.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int G;
int num[] = {0, 2, 7, 5, 30,
           169, 441, 1872, 7632, 1740,
           93313, 459901, 1358657, 2504881, 13482720};

int main(int argc, const char * argv[])
{
    while (cin >> G, G)
    {
        cout << num[G] << '\n';
    }
    
    return 0;
}
