//
//  main.cpp
//  f-HDU-5559-Frog and String
//
//  Created by ZYJ on 2017/10/16.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const char STR[][10] = {"A", "ABC", "ABAABB"};
const int SIZ[] = {1, 3, 6};

int n, m, k;

void draw(int id, int n)
{
    for (int i = 0, v; i < n; i++)
    {
        v = i % SIZ[id];
        printf("%c", STR[id][v]);
    }
}

void print_Im()
{
    printf("Impossible");
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int case_ = 1; case_ <= T; case_++)
    {
        scanf("%d%d%d", &n, &m, &k);
        
        printf("Case #%d:\n", case_);
        
        if (n < m)
        {
            print_Im();
        }
        else if (n == m)
        {
            draw(0, n);
        }
        else
        {
            if (k == 1)
            {
                print_Im();
            }
            else if (k == 2)
            {
                if (n == 8 && m == 7)
                {
                    printf("AABABBAA");
                }
                else if (m < 8)
                {
                    print_Im();
                }
                else
                {
                    draw(0, m - 8);
                    draw(2, n - m + 8);
                }
            }
            else
            {
                if (m < 3)
                {
                    print_Im();
                }
                else
                {
                    draw(0, m - 3);
                    draw(1, n - m + 3);
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}
