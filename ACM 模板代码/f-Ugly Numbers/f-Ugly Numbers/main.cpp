//
//  main.cpp
//  f-Ugly Numbers
//
//  Created by ZYJ on 16/6/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <queue>

/*
 * Ugly Numbers
 * Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
 * 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
 */

typedef std::pair<unsigned long, int> node_type;

int main(int argc, const char * argv[])
{
    unsigned long result[1502];
    std::priority_queue<node_type, std::vector<node_type>, std::greater<node_type>> Q;
    Q.push(std::make_pair(1, 2));
    for (int i = 0; i < 1500; i++)
    {
        node_type node = Q.top();
        Q.pop();
        switch (node.second)
        {
            case 2:
                Q.push(std::make_pair(node.first * 2, 2));
            case 3:
                Q.push(std::make_pair(node.first * 3, 3));
            case 5:
                Q.push(std::make_pair(node.first * 5, 5));
        }
        result[i] = node.first;
    }
    
    int n;
    std::cin >> n;
    while (n > 0)
    {
        std::cout << result[n - 1] << '\n';
        std::cin >> n;
    }
    
    return 0;
}
