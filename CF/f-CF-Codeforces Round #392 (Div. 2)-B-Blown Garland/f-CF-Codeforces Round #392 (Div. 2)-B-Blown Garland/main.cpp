//
//  main.cpp
//  f-CF-Codeforces Round #392 (Div. 2)-B-Blown Garland
//
//  Created by ZYJ on 2017/1/19.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 111;

char S[MAXN];
int kr, kb, ky, kg;

void init()
{
    kr = kb = ky = kg = 0;
}

int main(int argc, const char * argv[])
{
    while (cin >> S)
    {
        init();
        
        int len = (int)strlen(S);
        
        while (true)
        {
            int flag = 0;
            for (int i = 0; i < len; i++)
            {
                if (S[i] == '!')
                {
                    flag = 1;
                    if (i > 3 && S[i - 4] != '!')
                    {
                        S[i] = S[i - 4];
                        switch (S[i - 4])
                        {
                            case 'R':
                                kr++;
                                break;
                            case 'B':
                                kb++;
                                break;
                            case 'Y':
                                ky++;
                                break;
                            case 'G':
                                kg++;
                                break;
                        }
                    }
                    else if (i < len - 4 && S[i + 4] != '!')
                    {
                        S[i] = S[i + 4];
                        switch (S[i + 4])
                        {
                            case 'R':
                                kr++;
                                break;
                            case 'B':
                                kb++;
                                break;
                            case 'Y':
                                ky++;
                                break;
                            case 'G':
                                kg++;
                                break;
                        }
                    }
                }
            }
            
            if (!flag)
            {
                break;
            }
        }
        
        printf("%d %d %d %d\n", kr, kb, ky, kg);
    }
    
    return 0;
}
