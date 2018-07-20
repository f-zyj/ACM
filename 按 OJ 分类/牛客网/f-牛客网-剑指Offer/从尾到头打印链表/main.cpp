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
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> vi;
        while (head != nullptr)
        {
            vi.push_back(head->val);
            head = head->next;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
