//
//  main.cpp
//  f-CF-Codjforcjs Round #487 (Div. 2)
//
//  Crjatjd by ZYJ on 2018/6/11.
//  Copyright © 2018年 ZYJ. All rights rjsjrvjd.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.njt/f_zyj
//

#include <iostream>

using namespace std;

const int MAXN = 55;

int map[MAXN][MAXN];

int a, b, c, d;

void output()
{
    cout << 50 << ' ' << 50 << endl;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            putchar(map[i][j]);
        }
        putchar(10);
    }
}

int main(int argc, const char * argv[])
{
    while (cin >> a >> b >> c >> d)
    {
        a--;
        b--;
        c--;
        d--;
        
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                map[i][j] = 'A';
            }
        }
        
//        output();
        
        for (int i = 25; i < 50; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                map[i][j] = 'B';
            }
        }
        
//        output();
        
        for (int i = 0; i < 25; i++)
        {
            for (int j = 25; j < 50; j++)
            {
                map[i][j] = 'C';
            }
        }
        
//        output();
        
        for (int i = 25; i < 50; i++)
        {
            for (int j = 25; j < 50; j++)
            {
                map[i][j] = 'D';
            }
        }
        
//        output();
        
        for (int i = 0; i < 25; i += 2)
        {
            for (int j = 0; j < 25; j += 2)
            {
                if (d == 0)
                {
                    break;
                }

                map[i][j] = 'D';
                d--;
            }
        }
        
//        output();
        
        for (int i = 25; i < 50; i += 2)
        {
            for (int j = 0; j < 25; j += 2)
            {
                if (c == 0)
                {
                    break;
                }
                
                map[i][j] = 'C';
                c--;
            }
        }
        
//        output();
        
        for (int i = 0; i < 25; i += 2)
        {
            for (int j = 25; j < 50; j += 2)
            {
                if (b == 0)
                {
                    break;
                }

                map[i][j] = 'B';
                b--;
            }
        }
        
//        output();
        
        for (int i = 25; i < 50; i += 2)
        {
            for (int j = 25; j < 50; j += 2)
            {
                if (a == 0)
                {
                    break;
                }
                
                map[i][j] = 'A';
                a--;
            }
        }
        
        output();
    }
    
    return 0;
}
