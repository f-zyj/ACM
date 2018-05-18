//
//  main.cpp
//  f-2016河南ACM省赛-A-表达式求值
//
//  Created by ZYJ on 16/6/7.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <string>
#include <stack>
#include <iostream>
using namespace::std;

char str[1005];
stack<int>post;
stack<char>sym;

//各位数字之和取最大
int sMax(int x, int y)
{
    int sumX = 0;
    int sumY = 0;
    while (x)
    {
        sumX += x % 10;
        x /= 10;
    }
    while (y)
    {
        sumY += y % 10;
        y /= 10;
    }
    return sumX > sumY ? sumX : sumY;
}

//读取整数
int getNum(int *key)
{
    int num = 0;
    while (str[*key] >= '0' && str[*key] <= '9')
    {
        num = num * 10 + str[(*key)++] - '0';
    }
    (*key)--;
    return num;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    
    while (T--)
    {
        cin >> str;
        int len = (int)strlen(str);
        
        for (int i = 0; i < len; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                post.push(getNum(&i));
            }
            else if (str[i] == 'S')
            {
                i += 3;
            }
            else if (str[i] == ')')
            {
                while (!sym.empty() && sym.top() != '(')
                {
                    int numA = post.top();
                    post.pop();
                    int numB = post.top();
                    post.pop();
                    int num;
                    
                    switch (sym.top())
                    {
                        case '+':
                            num = numA + numB;
                            break;
                        case '*':
                            num = numA * numB;
                            break;
                        case ',':
                            num = sMax(numA, numB);
                            break;
                    }
                    
                    post.push(num);
                    sym.pop();
                }
                sym.pop();
            }
            else if (str[i] == ',' || (str[i] == '+' && !sym.empty() && sym.top() == '*'))
            {
                while (!sym.empty() && sym.top() != '(')
                {
                    int numA = post.top();
                    post.pop();
                    int numB = post.top();
                    post.pop();
                    int num;
                    
                    switch (sym.top())
                    {
                        case '+':
                            num = numA + numB;
                            break;
                        case '*':
                            num = numA * numB;
                            break;
                    }
                    
                    post.push(num);
                    sym.pop();
                }
                sym.push(str[i]);
            }
            else if (str[i] == '+' || str[i] == '*' || str[i] == ',' || str[i] == '(')
            {
                sym.push(str[i]);
            }
        }
        
        while (!sym.empty())
        {
            int numA = post.top();
            post.pop();
            int numB = post.top();
            post.pop();
            int num;
            
            switch (sym.top())
            {
                case '+':
                    num = numA + numB;
                    break;
                case '*':
                    num = numA * numB;
                    break;
                case ',':
                    num = sMax(numA, numB);
                    break;
            }
            
            post.push(num);
            sym.pop();
        }
        
        cout << post.top() << endl;
    }
    return 0;
}
