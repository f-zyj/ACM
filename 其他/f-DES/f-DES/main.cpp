//
//  main.cpp
//  f-DES
//
//  Created by ZYJ on 2017/12/5.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include "DES.hpp"

using namespace std;

string plain, key, cipher;

int main(int argc, const char * argv[])
{
    DES des;
    cin >> plain >> key;
    string en = des.Encrypt(plain, key);
    for (int i = 0; i < 8; i++)
    {
        cout << en[i] << '\n';
    }
    
    cin >> cipher >> key;
    string de = des.Decrypt(cipher, key);
    cout << de << '\n';
    
    return 0;
}
