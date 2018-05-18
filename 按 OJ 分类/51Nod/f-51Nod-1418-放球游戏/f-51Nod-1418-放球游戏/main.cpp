//
//  main.cpp
//  f-51Nod-1418-放球游戏
//
//  Created by ZYJ on 16/8/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAXS = 55;
const int MAXC = 3;

char S[MAXS];
int RGB[MAXC]; //  0R 1G B2

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    while (T--)
    {
        memset(RGB, 0, sizeof(RGB));
        
        cin >> S;
        int len = (int)strlen(S);
        if (len == 1)
        {
            cout << "0\n";
            continue;
        }
        else if (len == 2)
        {
            cout << "1\n";
            continue;
        }
        
        int res = 1;
        RGB[S[0] == 'R' ? 0 : S[0] == 'G' ? 1 : 2]++;
        RGB[S[1] == 'R' ? 0 : S[1] == 'G' ? 1 : 2]++;
  
        for (int i = 2; i < len; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                res += RGB[j] >= 2 ? 2 : RGB[j];
            }
            RGB[S[i] == 'R' ? 0 : S[i] == 'G' ? 1 : 2]++;
        }
        
        cout << res << '\n';
    }
    
    return 0;
}
