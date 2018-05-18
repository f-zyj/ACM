//
//  main.cpp
//  f-腾讯2017暑期实习生编程题-B-算法基础-字符移位
//
//  Created by ZYJ on 2017/3/7.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(int argc, const char * argv[])
//{
//    string s;
//    cin >> s;
//    
//    for (int i = 0; i < s.length(); i++)
//    {
//        if (s[i] >= 'a' && s[i] <= 'z')
//        {
//            cout << s[i];
//        }
//    }
//    for (int i = 0; i < s.length(); i++)
//    {
//        if (s[i] >= 'A' && s[i] <= 'Z')
//        {
//            cout << s[i];
//        }
//    }
//    cout << '\n';
//    
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    string s;
    cin >> s;

    for (int i = (int)s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            for (int j = i; j < s.length(); j++)
            {
                if (s[j + 1] >= 'a' && s[j + 1] <= 'z')
                {
                    s[j] ^= s[j + 1];
                    s[j + 1] ^= s[j];
                    s[j] ^= s[j + 1];
                }
            }
        }
    }
    cout << s << '\n';

    return 0;
}
