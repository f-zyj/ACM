//
//  main.cpp
//  f-牛客网-剑指Offer
//
//  Created by ZYJ on 2018/7/14.
//  Copyright © 2018年 ZYJ. All rights reserved.
//
//  GitHub : https://github.com/f-zyj
//  CSDN   : https://blog.csdn.net/f_zyj
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool Find(int target, vector<vector<int>> array)
    {
        size_t rows = array.size();
        size_t cols = array[0].size();
        
        if (!array.empty() && rows > 0 && cols > 0)
        {
            int row = 0;
            int col = (int)cols - 1;
            while (row < rows && col >= 0)
            {
                if (array[row][col] == target)
                {
                    return true;
                }
                else if (array[row][col] > target)
                {
                    --col;
                }
                else
                {
                    ++row;
                }
            }
        }
        
        return false;
    }
};

int main()
{
    return 0;
}
