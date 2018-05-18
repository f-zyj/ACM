//
//  main.cpp
//  f-NYOJ-1236-挑战密室
//
//  Created by ZYJ on 2017/5/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

map<string, int> msi;

void init()
{
    msi["N"] = 14;
    msi["C"] = 12;
    msi["O"] = 16;
    msi["Cl"] = 35;
    msi["S"] = 32;
    msi["H"] = 2;
    msi["Al"] = 27;
    msi["Ca"] = 40;
    msi["Zn"] = 65;
    msi["Na"] = 23;
}

int main()
{
    init();
    
    int K;
    cin >> K;
    
    string s;
    while (K--)
    {
        cin >> s;
        
        int i = 0;
        while (s[i] != '=')
        {
            i++;
        }
        i++;
        
        int coe = 0;
        while (s[i] >= '0' && s[i] <= '9')
        {
            coe *= 10;
            coe += s[i] - '0';
            i++;
        }
        if (coe == 0)
        {
            coe = 1;
        }
        
        int res = 0;
        int tmp, n;
        while (s[i] != '+' && i < s.length())
        {
            if (s[i] == '(')
            {
                i++;
                tmp = 0;
                int tmp_;
                while (s[i] != ')')
                {
                    if (s[i] == 'N')
                    {
                        if (s[i + 1] == 'a')
                        {
                            tmp_ = msi["Na"];
                            i++;
                        }
                        else
                        {
                            tmp_ = msi["N"];
                        }
                    }
                    else if (s[i] == 'C')
                    {
                        if (s[i + 1] == 'a')
                        {
                            tmp_ = msi["Ca"];
                            i++;
                        }
                        else if (s[i + 1] == 'l')
                        {
                            tmp_ = msi["Cl"];
                            i++;
                        }
                        else
                        {
                            tmp_ = msi["C"];
                        }
                    }
                    else if (s[i] == 'A')
                    {
                        tmp_ = msi["Al"];
                        i++;
                    }
                    else if (s[i] == 'Z')
                    {
                        tmp_ = msi["Zn"];
                        i++;
                    }
                    else
                    {
                        string a = "";
                        tmp_ = msi[a + s[i]];
                    }
                    i++; 
                    int n_ = 0;
                    while (s[i] >= '0' && s[i] <= '9')
                    {
                        n_ *= 10;
                        n_ += s[i] - '0';
                        i++;
                    }
                    if (n_ == 0)
                    {
                        n_ = 1;
                    }
                    tmp += tmp_ * n_; 
                }
                goto tag;
            }
            
            if (s[i] == 'N')
            {
                if (s[i + 1] == 'a')
                {
                    tmp = msi["Na"];
                    i++; 
                }
                else
                {
                    tmp = msi["N"];
                }
            }
            else if (s[i] == 'C')
            {
                if (s[i + 1] == 'a')
                {
                    tmp = msi["Ca"];
                    i++;
                }
                else if (s[i + 1] == 'l')
                {
                    tmp = msi["Cl"];
                    i++;
                }
                else
                {
                    tmp = msi["C"];
                }
            }
            else if (s[i] == 'A')
            {
                tmp = msi["Al"];
                i++;
            } 
            else if (s[i] == 'Z')
            {
                tmp = msi["Zn"];
                i++;
            }
            else
            {
                string a = "";
                tmp = msi[a + s[i]];
            }
            
        tag:
            i++; 		
            n = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                n *= 10;
                n += s[i] - '0';
                i++;
            }
            if (n == 0)
            {
                n = 1;
            }
            res += tmp * n;
        }
        
        printf("%04d\n", res * coe);
    }	
    
    return 0;
}
