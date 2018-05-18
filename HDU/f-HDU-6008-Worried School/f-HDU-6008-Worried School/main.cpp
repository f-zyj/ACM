//
//  main.cpp
//  f-HDU-6008-Worried School
//
//  Created by ZYJ on 2017/11/18.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

const int MAXN = 6;
const int MAXM = 21;
const int MAXB = 100;

int G;
string S;
string ECsite[MAXM];
string RGsite[MAXN][MAXM];
set<string> st;

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int ce = 1; ce <= T; ce++)
    {
        cin >> G >> S;
        for (int i = 1; i < MAXN; i++)
        {
            for (int j = 1; j < MAXM; j++)
            {
                cin >> RGsite[i][j];
            }
        }
        for (int j = 1; j < MAXM; j++)
        {
            cin >> ECsite[j];
        }
        
        int pos, cnt, y = -1;
        for (int x = 0; x <= G; x++)
        {
            st.clear();
            bool staX = false, staY = false;
            if (x > 0)
            {
                for (int r = 1; r <= MAXB; r++)
                {
                    pos = r % 5;
                    if (pos == 0)
                    {
                        pos += 5;
                    }
                    cnt = (int)ceil(r / 5.0);
                    if (RGsite[pos][cnt] == S)
                    {
                        staX = 1;
                    }
                    st.insert(RGsite[pos][cnt]);
                    if (st.size() >= x)
                    {
                        break;
                    }
                }
            }
            
            if (G - x > 0)
            {
                for (int j = 1; j < MAXM; j++)
                {
                    if (ECsite[j] == S)
                    {
                        staY = 1;
                    }
                    st.insert(ECsite[j]);
                    if (st.size() >= G)
                    {
                        break;
                    }
                }
            }
            
            if (!staX && !staY)
            {
                y = G - x;
            }
        }
        
        printf("Case #%d: ", ce);
        if (y == -1)
        {
            printf("ADVANCED!\n");
        }
        else
        {
            printf("%d\n", y);
        }
    }
    
    return 0;
}
