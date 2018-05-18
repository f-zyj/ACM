//
//  main.cpp
//  f-51Nod-1995-三子棋
//
//  Created by ZYJ on 2017/12/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    int x, y;
    while (T--)
    {
        cin >> x >> y;
        switch (x)
        {
            case 1:
                switch (y)
                {
                    case 1:
                        printf("Win\n6\n");
                        break;
                    case 2:
                        printf("Win\n4\n");
                        break;
                    case 3:
                        printf("Win\n4\n");
                        break;
                    case 4:
                        printf("Win\n6\n");
                        break;
                }
                break;
            case 2:
                switch (y)
                {
                    case 1:
                        printf("Equal\n0\n");
                        break;
                    case 2:
                        printf("Win\n4\n");
                        break;
                    case 3:
                        printf("Win\n4\n");
                        break;
                    case 4:
                        printf("Equal\n0\n");
                        break;
                }
                break;
            case 3:
                switch (y)
                {
                    case 1:
                        printf("Win\n6\n");
                        break;
                    case 2:
                        printf("Win\n4\n");
                        break;
                    case 3:
                        printf("Win\n4\n");
                        break;
                    case 4:
                        printf("Win\n6\n");
                        break;
                }
                break;
        }
    }
    
    return 0;
}
